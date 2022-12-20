#include <assert.h>
#include "Board.h"
#include "CustomRaylib.h"
#include "Vec2.h"

Board::Cell::Cell()
    : 
    bExists(false),
    color(WHITE)
{
}

bool Board::Cell::Exists() const
{
    return bExists;
}

void Board::Cell::SetColor(Color color_in)
{
    color = color_in;
    bExists = true;
}

void Board::Cell::Remove()
{
    bExists = false;
}

Color Board::Cell::GetColor() const
{
    return color;
}

Board::Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellsize_in, int padding)
    :
    screenPos(screenPos),
    width(widthHeight.GetX()),
    height(widthHeight.GetY()),
    cellSize(cellsize_in),
    padding(padding)
{
    assert(width > 0 && height > 0); // If assertion triggers : The width or height is smaller than 1
    assert(cellSize > 0);            // If assertion triggers : The cell size is smaller than 1
    cells.resize(width * height);
}

int Board::GetWidth() const
{
    return width;
}

int Board::GetHeight() const
{
    return height;
}

bool Board::CellExists(Vec2<int> pos) const
{
    return cells[pos.GetY() * width + pos.GetX()].Exists();
}

void Board::SetCell(Vec2<int> pos, Color color)
{
    assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < width && pos.GetY() < height); // If assertion triggers : x or pos.GetY() is out of bounds
    cells[pos.GetY() * width + pos.GetX()].SetColor(color);
}

void Board::DrawCell(Vec2<int> pos) const
{
    Color color = cells[pos.GetY() * width + pos.GetX()].GetColor();
    DrawCell(pos, color);
}

void Board::DrawCell(Vec2<int> pos, Color color) const
{
    assert(pos.GetX() >= 0 && pos.GetX() < width && pos.GetY() >= 0 && pos.GetY() < height); // If assertopm triggers: x or y is out of bounds
    Vec2<int> topLeft = screenPos + padding + (pos * cellSize);
    raycpp::DrawRectangle(topLeft, Vec2<int>{cellSize, cellSize} - padding, color);
}

void Board::Draw() const
{
    for (int iY = 0; iY < height; ++iY)
    {
        for (int iX = 0; iX < width; ++iX)
        {
            if (CellExists({ iX,iY }))
            {
                DrawCell({iX, iY});
            }
        }
    }
    DrawBorder();
}

void Board::DrawBorder() const
{
    raycpp::DrawRectangleLinesEx(
        screenPos - (cellSize / 2),
        Vec2<int>{width * cellSize, height * cellSize} + cellSize,
        cellSize / 2,
        WHITE);
}