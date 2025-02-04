#pragma once
#include <sgg/graphics.h>
#include "Box.h"
#include "GameObject.h"

namespace AuebGame
{
    struct TextData
    {
        float m_PosX;
        float m_PosY;
    };

    class Text : public Box, public GameObject
    {
    public:
        Text(TextData coinData, const std::string& name = "Text");
        ~Text();

        void Init() override;
        void Draw(const std::string& text);
        void Update(float ms) override;

    private:
        graphics::Brush m_BrushText;
    };
}
