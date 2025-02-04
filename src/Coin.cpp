#include "Coin.h"

namespace AuebGame
{
    Coin::Coin(CoinData coinData, const std::string& name)
        : GameObject(name), Box(coinData.m_PosX, coinData.m_PosY)
    {
    }

    Coin::~Coin()
    {
    }

    void Coin::Init()
    {
        m_BrushCoin.fill_opacity = 1.0f;
        m_BrushCoin.outline_opacity = 0.0f;
        m_BrushCoin.texture = s_GameState->GetFullAssetPath("coin.png");
    }

    void Coin::Draw()
    {
        float width = s_GameState->GetCanvasWidth();
        float height = s_GameState->GetCanvasHeight();

        float offsetX = s_GameState->GetGlobalOffsetX() + m_PosX;
        float offsetY = s_GameState->GetGlobalOffsetY() + m_PosY;

        graphics::drawRect(offsetX, offsetY, 0.5f, 0.5f, m_BrushCoin);
    }

    void Coin::Update(float ms)
    {
    }
}