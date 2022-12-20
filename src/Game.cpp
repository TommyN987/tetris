#include <raylib.h>
#include <assert.h>
#include "Game.h"
#include "Settings.h"

Game::Game(int width, int height, int fps, std::string title)
    : 
    board(
        settings::boardPosition, 
        settings::boardWidthHeight, 
        settings::cellSize, 
        settings::padding),
    tetromino(board)
{
    assert(!GetWindowHandle()); // If assertion triggers: window is already opened
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept
{
    assert(GetWindowHandle()); // If assertion triggers: window is already close
    CloseWindow();
}

bool Game::GameShouldClose() const
{
    return WindowShouldClose();
}

void Game::Tick()
{
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

void Game::Draw()
{
    ClearBackground(BLACK);
    board.Draw();
    tetromino.Draw();
}

void Game::Update()
{
    if (IsKeyPressed(KEY_A))
    {
        tetromino.RotateCounterClockwise();
    }
    if (IsKeyPressed(KEY_D))
    {
        tetromino.RotateClockwise();
    }
    if (IsKeyPressed(KEY_LEFT))
    {
        tetromino.MoveLeft();
    }
    if (IsKeyPressed(KEY_RIGHT))
    {
        tetromino.MoveRight();
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        tetromino.MoveDown();
    }
}