#pragma once
#include <string>

namespace AuebGame
{
    class GameState
    {
    public:
        static GameState* GetInstance();

        void Init();
        void Draw();
        void Update(float ms);

        float GetCanvasWidth() const { return m_CanvasWidth; }
        float GetCanvasHeight() const { return m_CanvasHeight; }

        float GetGlobalOffsetX() const { return m_GlobalOffsetX; }
        float GetGlobalOffsetY() const { return m_GlobalOffsetY; }

        void SetGlobalOffsetX(float x) { m_GlobalOffsetX = x; }
        void SetGlobalOffsetY(float y) { m_GlobalOffsetY = y; }

        std::string GetFullAssetPath(const std::string& assetName) const { return m_AssetPath + assetName; }

        int GetLives() const { return s_Lives; }

        void IncreaseScore(int amount) { s_Score += amount; }
        void DecreaseLives(int amount) { s_Lives -= amount; }

        class Player* GetPlayer() const { return m_Player; }

    private:
        static GameState* s_Instance;

        static int s_Score;
        static int s_Lives;

        GameState();
        ~GameState();

        // ==============================

        const std::string m_AssetPath = "assets\\";

        const float m_CanvasWidth = 10.0f;
        const float m_CanvasHeight = 6.0f;

        float m_GlobalOffsetX = 0.0f;
        float m_GlobalOffsetY = 0.0f;

        class Player* m_Player = nullptr;
        class Level* m_Level = nullptr;
        class Text* m_ScoreText = nullptr;
        class Text* m_LivesText = nullptr;
    };
}
