#include "GameState.h"
#include "Player.h"
#include "Text.h"
#include "Level.h"

namespace AuebGame
{
    GameState* GameState::s_Instance = nullptr;

    int GameState::s_Score = 0;
    int GameState::s_Lives = 3;

    GameState::GameState()
    {
    }

    GameState::~GameState()
    {
        if (m_Level) delete m_Level;
    }

    GameState* GameState::GetInstance()
    {
        if (s_Instance == nullptr)
            s_Instance = new GameState();

        return s_Instance;
    }

    void GameState::Init()
    {
        m_Level = new Level(LevelNumber::LEVEL_1, "Level 1");
        m_Level->Init();

        m_Player = new Player(PlayerData(5.0f, 5.0f), "Player");
        m_Player->Init();

        m_ScoreText = new Text(TextData(0.5f, 0.6f), "ScoreText");
        m_ScoreText->Init();

        m_LivesText = new Text(TextData(7.7f, 0.6f), "LivesText");
        m_LivesText->Init();

        graphics::preloadBitmaps(m_AssetPath);
        graphics::setFont(this->GetFullAssetPath("Montserrat-Regular.ttf"));
    }

    void GameState::Draw()
    {
        if (m_Level) m_Level->Draw();

        const std::string scoreStr = "Score: " + std::to_string(s_Score);
        if (m_ScoreText) m_ScoreText->Draw(scoreStr);

        const std::string livesStr = "Lives: " + std::to_string(s_Lives);
        if (m_LivesText) m_LivesText->Draw(livesStr);
    }

    void GameState::Update(float ms)
    {
        if (ms > 500 || !m_Level) return;

        m_Level->Update(ms);

        if (m_Level->IsGameOver())
        {
            graphics::stopMessageLoop();
        }

        if (m_Level->IsLevelComplete())
        {
            LevelNumber nextLevel = m_Level->GetNextLevel();

            if (nextLevel == LevelNumber::LEVEL_1)
            {
                graphics::stopMessageLoop();
            }
            else
            {
                delete m_Level;
                m_Level = new Level(nextLevel, "Level " + std::to_string(static_cast<int>(nextLevel) + 1));

                delete m_Player;
                m_Player = new Player(PlayerData(5.0f, 3.0f), "Player");

                m_Level->Init();
                m_Player->Init();
            }
        }
    } 
}
