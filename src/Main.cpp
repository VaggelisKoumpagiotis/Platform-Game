#include <sgg/graphics.h>

#include "GameState.h"

static void Draw()
{
    AuebGame::GameState::GetInstance()->Draw();
}

static void Update(float ms)
{
    AuebGame::GameState::GetInstance()->Update(ms);
}

int main(int argc, char** argv)
{
    graphics::createWindow(800, 800, "Aueb Game");

    graphics::setDrawFunction(Draw);
    graphics::setUpdateFunction(Update);

    AuebGame::GameState* gameState = AuebGame::GameState::GetInstance();
    gameState->Init();

    graphics::setCanvasSize(gameState->GetCanvasWidth(), gameState->GetCanvasHeight());
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::startMessageLoop();

    return 0;
}
