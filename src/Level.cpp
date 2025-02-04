#include "Level.h"
#include <sgg/graphics.h>
#include "Player.h"

namespace AuebGame
{
    LevelData Level::LEVEL_1_DATA = {
        .blockData = {
            { -7.5f, -7.5f, BlockType::MUDL },
            { -7.5f, -6.5f, BlockType::MUDL },
            { -7.5f, -5.5f, BlockType::MUDL },
            { -7.5f, -4.5f, BlockType::MUDL },
            { -7.5f, -3.5f, BlockType::MUDL },
            { -7.5f, -2.5f, BlockType::MUDL },
            { -7.5f, -1.5f, BlockType::MUDL },
            { -7.5f, -0.5f, BlockType::MUDL },
            { -7.5f, 0.5f, BlockType::MUDL },
            { -7.5f, 1.5f, BlockType::MUDL },
            { -7.5f, 2.5f, BlockType::MUDL },
            { -7.5f, 3.5f, BlockType::MUDL },
            { -7.5f, 4.5f, BlockType::MUDL },
            { -7.5f, 5.5f, BlockType::MUDL },
            { -7.5f, 6.5f, BlockType::MUDL },
            { -7.5f, 7.5f, BlockType::MUDL },
            { -7.5f, 8.5f, BlockType::MUDL },
            { -7.5f, 9.5f, BlockType::MUDL },
            { -7.5f, 10.5f, BlockType::MUDL },
            { -7.5f, 11.5f, BlockType::MUDL },
            { -7.5f, 12.5f, BlockType::MUDL },
            { -7.5f, 13.5f, BlockType::MUDL },
            { -7.5f, 14.5f, BlockType::MUDL },
            { -7.5f, 15.5f, BlockType::MUDL },

            { 15.5f, 15.5f, BlockType::MUDR },
            { 15.5f, 14.5f, BlockType::MUDR },
            { 15.5f, 13.5f, BlockType::MUDR },
            { 15.5f, 12.5f, BlockType::MUDR },
            { 15.5f, 11.5f, BlockType::MUDR },
            { 15.5f, 10.5f, BlockType::MUDR },
            { 15.5f, 9.5f, BlockType::MUDR },
            { 15.5f, 8.5f, BlockType::MUDR },
            { 15.5f, 7.5f, BlockType::MUDR },
            { 15.5f, 6.5f, BlockType::MUDR },
            { 15.5f, 5.5f, BlockType::MUDR },
            { 15.5f, 4.5f, BlockType::MUDR },
            { 15.5f, 3.5f, BlockType::MUDR },
            { 15.5f, 2.5f, BlockType::MUDR },
            { 15.5f, 1.5f, BlockType::MUDR },
            { 15.5f, 0.5f, BlockType::MUDR },
            { 15.5f, -0.5f, BlockType::MUDR },
            { 15.5f, -1.5f, BlockType::MUDR },
            { 15.5f, -2.5f, BlockType::MUDR },
            { 15.5f, -3.5f, BlockType::MUDR },
            { 15.5f, -4.5f, BlockType::MUDR },
            { 15.5f, -5.5f, BlockType::MUDR },
            { 15.5f, -6.5f, BlockType::MUDR },
            { 15.5f, -7.5f, BlockType::MUDR },

            { -7.5f, 15.5f, BlockType::FLOOR },
            { -6.5f, 15.5f, BlockType::FLOOR },
            { -5.5f, 15.5f, BlockType::FLOOR },
            { -4.5f, 15.5f, BlockType::FLOOR },
            { -3.5f, 15.5f, BlockType::FLOOR },
            { -2.5f, 15.5f, BlockType::FLOOR },
            { -1.5f, 15.5f, BlockType::FLOOR },
            { -0.5f, 15.5f, BlockType::FLOOR },
            { 0.5f, 15.5f, BlockType::FLOOR },
            { 1.5f, 15.5f, BlockType::FLOOR },
            { 2.5f, 15.5f, BlockType::FLOOR },
            { 3.5f, 15.5f, BlockType::FLOOR },
            { 4.5f, 15.5f, BlockType::FLOOR },
            { 5.5f, 15.5f, BlockType::FLOOR },
            { 6.5f, 15.5f, BlockType::FLOOR },
            { 7.5f, 15.5f, BlockType::FLOOR },
            { 8.5f, 15.5f, BlockType::FLOOR },
            { 9.5f, 15.5f, BlockType::FLOOR },
            { 10.5f, 15.5f, BlockType::FLOOR },
            { 11.5f, 15.5f, BlockType::FLOOR },
            { 12.5f, 15.5f, BlockType::FLOOR },
            { 13.5f, 15.5f, BlockType::FLOOR },
            { 14.5f, 15.5f, BlockType::FLOOR },
            { 15.5f, 15.5f, BlockType::FLOOR },

            { 14.5f, -7.5f, BlockType::ROOF },
            { 13.5f, -7.5f, BlockType::ROOF },
            { 12.5f, -7.5f, BlockType::ROOF },
            { 11.5f, -7.5f, BlockType::ROOF },
            { 10.5f, -7.5f, BlockType::ROOF },
            { 9.5f, -7.5f, BlockType::ROOF },
            { 8.5f, -7.5f, BlockType::ROOF },
            { 7.5f, -7.5f, BlockType::ROOF },
            { 6.5f, -7.5f, BlockType::ROOF },
            { 5.5f, -7.5f, BlockType::ROOF },
            { 4.5f, -7.5f, BlockType::ROOF },
            { 3.5f, -7.5f, BlockType::ROOF },
            { 2.5f, -7.5f, BlockType::ROOF },
            { 1.5f, -7.5f, BlockType::ROOF },
            { 0.5f, -7.5f, BlockType::ROOF },
            { -0.5f, -7.5f, BlockType::ROOF },
            { -1.5f, -7.5f, BlockType::ROOF },
            { -2.5f, -7.5f, BlockType::ROOF },
            { -3.5f, -7.5f, BlockType::ROOF },
            { -4.5f, -7.5f, BlockType::ROOF },
            { -5.5f, -7.5f, BlockType::ROOF },
            { -6.5f, -7.5f, BlockType::ROOF },

            { -1.5f, 13.5f, BlockType::JUMP1 },
            { -0.5f, 13.5f, BlockType::JUMPM },
            { 0.5f, 13.5f, BlockType::JUMPM },
            { 1.5f, 13.5f, BlockType::JUMP2 },

            { 11.5f, 13.5f, BlockType::JUMP1 },
            { 12.5f, 13.5f, BlockType::JUMPM },
            { 13.5f, 13.5f, BlockType::JUMP2 },

            { 6.5f, 11.5f, BlockType::JUMP1 },
            { 7.5f, 11.5f, BlockType::JUMPM },
            { 8.5f, 11.5f, BlockType::JUMPM },
            { 9.5f, 11.5f, BlockType::JUMPM },
            { 10.5f, 11.5f, BlockType::JUMP2 },

            { 1.5f, 9.5f, BlockType::JUMP1 },
            { 2.5f, 9.5f, BlockType::JUMPM },
            { 3.5f, 9.5f, BlockType::JUMPM },
            { 4.5f, 9.5f, BlockType::JUMPM },
            { 5.5f, 9.5f, BlockType::JUMP2 },

            { -2.5f, 7.0f, BlockType::JUMP1 },
            { -1.5f, 7.0f, BlockType::JUMPM },
            { -0.5f, 7.0f, BlockType::JUMP2 },

            { 6.5f, 7.5f, BlockType::JUMP1 },
            { 7.5f, 7.5f, BlockType::JUMPM },
            { 8.5f, 7.5f, BlockType::JUMPM },
            { 9.5f, 7.5f, BlockType::JUMPM },
            { 10.5f, 7.5f, BlockType::JUMPM },
            { 11.5f, 7.5f, BlockType::JUMPM },
            { 12.5f, 7.5f, BlockType::JUMPM },
            { 13.5f, 7.5f, BlockType::JUMPM },
            { 14.5f, 7.5f, BlockType::JUMPM },

            { 4.5f, 5.5f, BlockType::JUMP1 },
            { 5.5f, 5.5f, BlockType::JUMP2 },

            { 2.5f, 3.5f, BlockType::JUMP1 },
            { 3.5f, 3.5f, BlockType::JUMP2 },

            { 0.5f, 1.5f, BlockType::JUMP1 },
            { 1.5f, 1.5f, BlockType::JUMP2 },

            { 2.5f, -0.5f, BlockType::JUMP1 },
            { 3.5f, -0.5f, BlockType::JUMP2 },

            { 5.5f, -0.5f, BlockType::JUMP1 },
            { 6.5f, -0.5f, BlockType::JUMP2 },

            { 8.5f, -0.5f, BlockType::JUMP1 },
            { 9.5f, -0.5f, BlockType::JUMP2 },

            { 11.5f, -0.5f, BlockType::JUMP1 },
            { 12.5f, -0.5f, BlockType::JUMP2 },

            { -3.5f, 5.0f, BlockType::JUMP2 },
            { -4.5f, 5.0f, BlockType::JUMPM },
            { -5.5f, 5.0f, BlockType::JUMPM },
            { -6.5f, 5.0f, BlockType::JUMPM },

            { 13.5f, -2.5f, BlockType::JUMP1 },
            { 14.5f, -2.5f, BlockType::JUMPM },

            { 12.5f, -4.5f, BlockType::JUMP2},
            { 11.5f, -4.5f, BlockType::JUMPM },
            { 10.5f, -4.5f, BlockType::JUMPM },
            { 9.5f, -4.5f, BlockType::JUMPM },
            { 8.5f, -4.5f, BlockType::JUMPM },
            { 7.5f, -4.5f, BlockType::JUMPM },
            { 6.5f, -4.5f, BlockType::JUMPM },
            { 5.5f, -4.5f, BlockType::JUMPM },
            { 4.5f, -4.5f, BlockType::JUMPM },
            { 3.5f, -4.5f, BlockType::JUMPM },
            { 2.5f, -4.5f, BlockType::JUMPM },
            { 1.5f, -4.5f, BlockType::JUMPM },
            { 0.5f, -4.5f, BlockType::JUMPM },
            { -0.5f, -4.5f, BlockType::JUMPM },
            { -1.5f, -4.5f, BlockType::JUMPM },
            { -2.5f, -4.5f, BlockType::JUMPM },
            { -3.5f, -4.5f, BlockType::JUMPM },
            { -4.5f, -4.5f, BlockType::JUMP1 }
        },

        .enemyData = {
            { -1.5f, 12.5f, 2.0f, 10.0f, RIGHT },
            { 14.5f, 6.5f, 3.0f, 25.0f, LEFT },
            { -5.5f, -5.5f, 20.0f, 8.0f, RIGHT}
        },

        .coinData = {
            { 1.5f, 12.5f },
            { 14.5f, 14.5f,},
            { -0.5f, 6.0f },
            { 1.5f, 8.5f },
            { 11.5f, 6.5f },
            { 3.0f, -1.5f },
            { 5.0f, 4.5f },
            { 9.0f, -1.5f },
            { 12.0f, -1.5f},
            { -6.5f, 4.0f }
        }
    };

    LevelData Level::LEVEL_2_DATA = {
        .blockData = {
            { 5.0f, 5.0f, BlockType::JUMP1 },
            { 6.0f, 5.0f, BlockType::JUMPM },
            { 7.0f, 5.0f, BlockType::JUMPM },
            { 8.0f, 5.0f, BlockType::JUMP2 },

            { 9.0f, 3.0f, BlockType::JUMP1 },
            { 10.0f, 3.0f, BlockType::JUMPM },
            { 11.0f, 3.0f, BlockType::JUMPM },
            { 12.0f, 3.0f, BlockType::JUMP2 },

            { 13.0f, 5.0f, BlockType::JUMP1 },
            { 14.0f, 5.0f, BlockType::JUMPM },
            { 15.0f, 5.0f, BlockType::JUMPM },
            { 16.0f, 5.0f, BlockType::JUMPM },
            { 17.0f, 5.0f, BlockType::JUMPM },
            { 18.0f, 5.0f, BlockType::JUMPM },
            { 19.0f, 5.0f, BlockType::JUMPM },
            { 20.0f, 5.0f, BlockType::JUMP2 },

            { 4.0f, 3.0f, BlockType::JUMP2 },
            { 3.0f, 3.0f, BlockType::JUMPM },
            { 2.0f, 3.0f, BlockType::JUMPM },
            { 1.0f, 3.0f, BlockType::JUMP1 },

            { 6.0f, 1.0f, BlockType::JUMP1},
            { 7.0f, 1.0f, BlockType::JUMP2 },

            { -1.0f, 2.0f, BlockType::JUMP2 },
            { -2.0f, 2.0f, BlockType::JUMPM },
            { -3.0f, 2.0f, BlockType::JUMPM },
            { -4.0f, 2.0f, BlockType::JUMPM },
            { -5.0f, 2.0f, BlockType::JUMPM },
            { -6.0f, 2.0f, BlockType::JUMPM },
            { -7.0f, 2.0f, BlockType::JUMP1 },
        },

        .enemyData = {
            { 13.0f, 4.0f, 2.0f, 30.0f, RIGHT },
            { -1.0f, 1.0f, 3.0f, 30.0f, LEFT },
            { 4.0f, 2.0f, 2.0f, 28.0f, LEFT },
            { 12.0f, 2.0f, 2.0f, 20.0f, LEFT },
        },

        .coinData = {
            { 6.0f, 4.0f },
            { 18.0f, 4.0f },
            { 2.5f, 2.0f },
            { -6.0f, 1.0f },
        }
    };

    std::map<LevelNumber, LevelData> Level::s_LevelData = {
        { LevelNumber::LEVEL_1, LEVEL_1_DATA },
        { LevelNumber::LEVEL_2, LEVEL_2_DATA }
    };

    Level::Level(LevelNumber level, const std::string& name)
        : GameObject(name), m_LevelNumber(level)
    {
        m_BrushBackground.outline_opacity = 0.0f;
        m_BrushBackground.texture = s_GameState->GetFullAssetPath("background.png");

        // Create the level from the level data
        LevelData data = s_LevelData[level];

		for (auto& blockData : data.blockData)
		{
			Block* block = new Block(blockData);

			m_Blocks.push_back(block);
			m_StaticObjects.push_back(block);
		}

		for (auto& enemyData : data.enemyData)
		{
			Enemy* enemy = new Enemy(enemyData);

			m_Enemies.push_back(enemy);
			m_DynamicObjects.push_back(enemy);
		}

        for (auto& coinData : data.coinData)
        {
            Coin* coin = new Coin(coinData);

            m_Coins.push_back(coin);
            m_DynamicObjects.push_back(coin);
        }
    }

    Level::~Level()
    {
        for (auto& obj : m_StaticObjects)
            delete obj;

        for (auto& obj : m_DynamicObjects)
            delete obj;
    }

    void Level::Init()
    {
        for (auto& obj : m_StaticObjects)
            if (obj) obj->Init();

        for (auto& obj : m_DynamicObjects)
            if (obj) obj->Init();
     }

    void Level::Draw()
    {
        float width = s_GameState->GetCanvasWidth();
        float height = s_GameState->GetCanvasHeight();

        float offsetX = s_GameState->GetGlobalOffsetX() + width / 2.0f;
        float offsetY = s_GameState->GetGlobalOffsetY() + height / 2.0f;

        graphics::drawRect(offsetX, offsetY, 200.0f * width, 200.0f * height, m_BrushBackground);

        if (s_GameState->GetPlayer()->IsActive())
            s_GameState->GetPlayer()->Draw();

        for (auto& obj : m_StaticObjects)
            if (obj) obj->Draw();

        for (auto& obj : m_DynamicObjects)
            if (obj) obj->Draw();
    }

    void Level::Update(float ms)
    {
        if (s_GameState->GetPlayer()->IsActive())
            s_GameState->GetPlayer()->Update(ms);

        for (auto& obj : m_DynamicObjects)
            if (obj) obj->Update(ms);

		CheckCollisions();

        GameObject::Update(ms);
    }

    LevelNumber Level::GetNextLevel() const
    {
        switch (m_LevelNumber)
        {
        case AuebGame::LEVEL_1:
            return AuebGame::LEVEL_2;
        default:
            return AuebGame::LEVEL_1;
        }
	}

	void Level::CheckCollisions()
	{
		for (auto& block : m_Blocks)
			if (s_GameState->GetPlayer()->CheckBlockCollisionVertical(*block)) break;

		for (auto& block : m_Blocks)
			if (s_GameState->GetPlayer()->CheckBlockCollisionHorizontal(*block)) break;

        for (auto& enemy : m_Enemies)
            if (s_GameState->GetPlayer()->CheckEnemyCollision(*enemy)) break;

        for (auto& coin : m_Coins)
            if (s_GameState->GetPlayer()->CheckCoinCollision(*coin)) 
            {
                m_DynamicObjects.remove(coin);
                m_Coins.remove(coin);
				break;
            }
	}
}
