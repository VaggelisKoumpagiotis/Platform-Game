#include "Player.h"

namespace AuebGame
{
    Player::Player(PlayerData playerData, const std::string& name)
        : GameObject(name), Box(playerData.posX, playerData.posY)
    {
    }

    Player::~Player()
    {
    }

    void Player::Init()
    {
        s_GameState->SetGlobalOffsetX(s_GameState->GetCanvasWidth() / 2.0f - m_PosX);
        s_GameState->SetGlobalOffsetY(s_GameState->GetCanvasHeight() / 2.0f - m_PosY);

        m_BrushPlayer.fill_opacity = 1.0f;
        m_BrushPlayer.outline_opacity = 0.0f;
        m_BrushPlayer.texture = s_GameState->GetFullAssetPath("player.png");
    }

    void Player::Draw()
    {
        graphics::drawRect
        (
            s_GameState->GetCanvasWidth() * 0.5f,
            s_GameState->GetCanvasHeight() * 0.5f,
            1.0f,
            1.0f,
            m_BrushPlayer
        );
    }

    void Player::Update(float ms)
    {
        float dt = ms / 1000.0f;

        if (m_EnemyCollisionTimeout > 0.0f)
			m_EnemyCollisionTimeout -= ms;

        float move = 0.0f;
        if (graphics::getKeyState(graphics::SCANCODE_A))
        {
            move -= 1.0f;
            m_BrushPlayer.texture = s_GameState->GetFullAssetPath("player_left.png");
        }

        if (graphics::getKeyState(graphics::SCANCODE_D))
        {
            move = 1.0f;
            m_BrushPlayer.texture = s_GameState->GetFullAssetPath("player.png");
        }

        m_VelocityX = std::min<float>(m_MaxVelocity, m_VelocityX + dt * move * m_AccelerationHorizontal);
        m_VelocityX = std::max<float>(-m_MaxVelocity, m_VelocityX);

        // friction
        m_VelocityX -= 0.2f * m_VelocityX / (0.1f + fabs(m_VelocityX));

        // apply static friction threshold
        if (fabs(m_VelocityX) < 0.01f)
            m_VelocityX = 0.0f;

        // adjust horizontal position
        m_PosX += m_VelocityX * dt;

        // jump only when not in flight:
        if (m_VelocityY == 0.0f)
        {
            if (graphics::getKeyState(graphics::SCANCODE_SPACE))
            {
                m_VelocityY -= m_AccelerationVertical * 0.02f; // not delta_time!! Burst

                graphics::playSound(s_GameState->GetFullAssetPath("jump.wav"), 1.0f);
            }
            else
            {
                m_VelocityY = 0.0f;
            }
        }

        // add gravity
        m_VelocityY += dt * m_Gravity;

        // adjust vertical position
        m_PosY += m_VelocityY * dt;

        s_GameState->SetGlobalOffsetX(s_GameState->GetCanvasWidth() / 2.0f - m_PosX);
        s_GameState->SetGlobalOffsetY(s_GameState->GetCanvasHeight() / 2.0f - m_PosY);

        GameObject::Update(ms);
    }

    bool Player::CheckBlockCollisionVertical(Box& other)
    {
        float offset = this->IntersectDown(other);

        if (offset)
        {
            m_PosY += offset;

            m_VelocityY = 0.0f;
        }

        return offset;
    }

    bool Player::CheckBlockCollisionHorizontal(Box& other)
    {
        float offset = this->IntersectSideways(other);

        if (offset)
        {
            m_PosX += offset;

            m_VelocityX = 0.0f;
        }

        return offset;
    }

    bool Player::CheckEnemyCollision(Enemy& other)
    {
        if (m_EnemyCollisionTimeout > 0.0f)
			return false;

        float offset = this->IntersectSideways(other);

        if (offset)
        {
            s_GameState->DecreaseLives(1);

            m_EnemyCollisionTimeout = 1000.0f;
        }

        return offset;
    }

    bool Player::CheckCoinCollision(Coin& other)
    {
		float offset = this->Intersect(other);

        if (offset)
        {
			s_GameState->IncreaseScore(1);
		}

		return offset;
	}
}
