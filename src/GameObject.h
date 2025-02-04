#pragma once
#include <string>
#include "GameState.h"

namespace AuebGame
{
    class GameObject
    {
    public:
        class GameObject(const std::string& name);
        virtual ~GameObject();

        virtual void Init();
        virtual void Draw();
        virtual void Update(float ms);

        bool IsActive() const { return m_Active; }
        void SetActive(bool active) { m_Active = active; }

    protected:
        static GameState* s_GameState;

        static int s_IdCounter;

    private:
        int m_Id;

        std::string m_Name;

        bool m_Active = true;
    };
}
