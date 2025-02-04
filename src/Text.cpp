#include "Text.h"

namespace AuebGame
{
    Text::Text(TextData coinData, const std::string& name)
        : GameObject(name), Box(coinData.m_PosX, coinData.m_PosY)
    {
    }

    Text::~Text()
    {
    }

    void Text::Init()
    {
    }

    void Text::Draw(const std::string& text)
    {
        graphics::drawText(m_PosX, m_PosY, 0.5f, text, m_BrushText);
    }

    void Text::Update(float ms)
    {
    }
}