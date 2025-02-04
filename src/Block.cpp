#include "Block.h"

namespace AuebGame
{
    std::map<BlockType, std::string> Block::s_BlockFilenames = {
        { BlockType::FLOOR, "floor.png" },
        { BlockType::ROOF, "roof.png"},
        { BlockType::MUDL, "mud_left.png" },
        { BlockType::MUDR, "mud_right.png" },
        { BlockType::JUMP1, "jump1.png" },
        { BlockType::JUMPM, "jump_mid.png" },
        { BlockType::JUMP2, "jump2.png" }
	};

    Block::Block(BlockData blockData, const std::string& name)
        : GameObject(name), Box(blockData.m_PosX, blockData.m_PosY), m_BlockType(blockData.m_BlockType)
    {
    }

    Block::~Block()
    {
    }

    void Block::Init()
    {
        m_BrushBlock.fill_opacity = 1.0f;
        m_BrushBlock.outline_opacity = 0.0f;
        m_BrushBlock.texture = s_GameState->GetFullAssetPath(s_BlockFilenames[m_BlockType]);
    }

    void Block::Draw()
    {

        float width = s_GameState->GetCanvasWidth();
        float height = s_GameState->GetCanvasHeight();

        float offsetX = s_GameState->GetGlobalOffsetX() + m_PosX;
        float offsetY = s_GameState->GetGlobalOffsetY() + m_PosY;

        graphics::drawRect(offsetX, offsetY, 1.0f, 1.0f, m_BrushBlock);
    }

    void Block::Update(float ms)
    {
    }
}

