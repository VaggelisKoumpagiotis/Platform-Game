#include "GameObject.h"

namespace AuebGame
{
    GameState* GameObject::s_GameState = GameState::GetInstance();

    int GameObject::s_IdCounter = 0;

    GameObject::GameObject(const std::string& name)
        : m_Name(name), m_Id(s_IdCounter++)
    {
    }

    GameObject::~GameObject()
    {
    }

    void GameObject::Init()
    {
    }

    void GameObject::Draw()
    {
    }

    void GameObject::Update(float ms)
    {
    }
}
