#pragma once
#include <sgg/graphics.h>
#include "Box.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Coin.h"

namespace AuebGame
{
    struct PlayerData
    {
        float posX;
        float posY;
    };

    class Player: public Box, public GameObject
    {
    public:
        Player(PlayerData playerData, const std::string& name = "Player");
        ~Player();

        void Init() override;
        void Draw() override;
        void Update(float ms) override;

        bool CheckBlockCollisionVertical(Box& other);
        bool CheckBlockCollisionHorizontal(Box& other);

        bool CheckEnemyCollision(Enemy& other);

        bool CheckCoinCollision(Coin& other);

    private:
        graphics::Brush m_BrushPlayer;

        float m_EnemyCollisionTimeout = 1000.0f;

        float m_VelocityX = 0.0f;
        float m_VelocityY = 0.0f;

        const float m_AccelerationHorizontal = 50.0f;
        const float m_AccelerationVertical = 300.0f;
        const float m_MaxVelocity = 5.0f;
        const float m_Gravity = 10.0f;
    };
}
