#pragma once
#include <math.h>
#include <algorithm>

namespace AuebGame
{
    struct Box
    {
        Box() : m_PosX(0.0f), m_PosY(0.0f) {}

        Box(float posX, float posY) : m_PosX(posX), m_PosY(posY) {}

        bool Intersect(Box& other)
        {
            return (fabs(m_PosX - other.m_PosX) * 2.0f < (m_Width + other.m_Width)) &&
                (fabs(m_PosY - other.m_PosY) * 2.0f < (m_Height + other.m_Height));
        }

        float IntersectDown(Box& other)
        {
            if (fabs(m_PosX - other.m_PosX) * 2.0f >= (m_Width + other.m_Width) || m_PosY > other.m_PosY)
                return 0.0f;

            return std::min<float>(0.0f, other.m_PosY - (other.m_Height / 2.0f) - m_PosY - (m_Height / 2.0f));
        }

        float IntersectSideways(Box& other)
        {
            if (fabs(m_PosY - other.m_PosY) * 2.0f >= (m_Width + other.m_Width))
                return 0.0f;

            if (m_PosX > other.m_PosX)
                return std::max<float>(0.0f, other.m_PosX + (other.m_Width / 2.0f) - m_PosX + (m_Width / 2.0f));
            else
                return std::min<float>(0.0f, other.m_PosX - (other.m_Width / 2.0f) - m_PosX - (m_Width / 2.0f));
        }

        // ==============================

        float m_PosX;
        float m_PosY;
        float m_Width = 1.0f;
        float m_Height = 1.0f;
    };
}
