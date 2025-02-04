#include "Enemy.h"

namespace AuebGame
{
    Enemy::Enemy(EnemyData enemyData, const std::string& name)
        : GameObject(name),
        Box(enemyData.posX, enemyData.posY),
        m_Velocity(enemyData.velocity),
        m_DirectionCounterLimit(enemyData.directionChangeFrequency),
        m_CurrentDirection(enemyData.initialDirection)
    {
    }

    Enemy::~Enemy()
    {
    }

    void Enemy::Init()
    {
        m_BrushEnemy.fill_opacity = 1.0f;
        m_BrushEnemy.outline_opacity = 0.0f;
        m_BrushEnemy.texture = s_GameState->GetFullAssetPath("enemy.png");
    }

    void Enemy::Draw()
    {

        float width = s_GameState->GetCanvasWidth();
        float height = s_GameState->GetCanvasHeight();

        float offsetX = s_GameState->GetGlobalOffsetX() + m_PosX;
        float offsetY = s_GameState->GetGlobalOffsetY() + m_PosY;

        graphics::drawRect(offsetX, offsetY, 1.0f, 1.0f, m_BrushEnemy);
    }

    void Enemy::Update(float ms)
    {
        float dt = ms / 1000.0f;

        m_DirectionCounter += 0.1f;

        if (m_DirectionCounter >= m_DirectionCounterLimit)
        {
            m_DirectionCounter = 0.0f;

            if (m_CurrentDirection == LEFT)
            {
                m_CurrentDirection = RIGHT;
                m_BrushEnemy.texture = s_GameState->GetFullAssetPath("enemy_right.png");
            }

            else
            {
                m_CurrentDirection = LEFT;
                m_BrushEnemy.texture = s_GameState->GetFullAssetPath("enemy.png");
            }



        }
        if (m_CurrentDirection == LEFT) m_PosX -= m_Velocity * dt;
        if (m_CurrentDirection == RIGHT) m_PosX += m_Velocity * dt;

        GameObject::Update(ms);
    }
}
