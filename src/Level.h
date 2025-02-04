#pragma once
#include <vector>
#include <list>
#include <map>
#include <sgg/graphics.h>
#include "GameObject.h"
#include "Block.h"
#include "Enemy.h"
#include "Coin.h"

namespace AuebGame
{
    enum LevelNumber
    {
        LEVEL_1,
        LEVEL_2
    };

    struct LevelData
    {
        std::vector<BlockData> blockData;
        std::vector<EnemyData> enemyData;
        std::vector<CoinData> coinData;
    };

    class Level : public GameObject
    {
    public:
        Level(LevelNumber level, const std::string& name = "Level");
        ~Level() override;

        void Init() override;
        void Draw() override;
        void Update(float ms) override;

        bool IsLevelComplete() const { return m_Coins.empty(); }
        bool IsGameOver() const { return s_GameState->GetLives() == 0; }

        LevelNumber GetLevelNumber() const { return m_LevelNumber; }

        LevelNumber GetNextLevel() const;

    private:
        void CheckCollisions();

    private:
        static std::map<LevelNumber, LevelData> s_LevelData;
        static LevelData LEVEL_1_DATA;
        static LevelData LEVEL_2_DATA;

        LevelNumber m_LevelNumber;

        std::vector<GameObject*> m_StaticObjects;
        std::vector<Box*> m_Blocks;

        std::list<GameObject*> m_DynamicObjects;
        std::list<Enemy*> m_Enemies;
        std::list<Coin*> m_Coins;

        const float m_BlockSize = 1.0f;
        float m_CenterX = 5.0f;
        float m_CenterY = 5.0f;

        graphics::Brush m_BrushBackground;
    };
}
