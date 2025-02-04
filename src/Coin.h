#pragma once
#include <sgg/graphics.h>
#include "Box.h"
#include "GameObject.h"

namespace AuebGame
{
    struct CoinData
    {
        float m_PosX;
        float m_PosY;
    };

    class Coin : public Box, public GameObject
    {
    public:
        Coin(CoinData coinData, const std::string& name = "Coin");
        ~Coin();

        void Init() override;
        void Draw() override;
        void Update(float ms) override;

    private:
        graphics::Brush m_BrushCoin;
    };
}
