#pragma once
#include <sgg/graphics.h>
#include "Box.h"
#include "GameObject.h"

namespace AuebGame
{

    enum Direction
    {
        LEFT, 
        RIGHT
    };

    struct EnemyData
    {
        float posX;
		float posY;
		float velocity;
		float directionChangeFrequency;
		Direction initialDirection;
    };

    class Enemy : public Box, public GameObject
    {
    public:
        Enemy(EnemyData enemyData, const std::string& name = "Enemy");
        ~Enemy();

        void Init() override;
        void Draw() override;
        void Update(float ms) override;

    private:
        graphics::Brush m_BrushEnemy;

        float m_Velocity = 1.0f;

        float m_DirectionCounterLimit = 0.0f;
        float m_DirectionCounter = 0.0f;
        Direction m_CurrentDirection = LEFT;
    };
}

