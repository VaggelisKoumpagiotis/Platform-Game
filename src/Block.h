#pragma once
#include <sgg/graphics.h>
#include <map>
#include "Box.h"
#include "GameObject.h"

namespace AuebGame
{
    enum class BlockType
	{
        FLOOR,
        ROOF,
        MUDL,
        MUDR,
        JUMP1,
        JUMPM,
        JUMP2
	};

    struct BlockData
	{
		float m_PosX;
		float m_PosY;
		BlockType m_BlockType;
	};

    class Block : public Box, public GameObject
    {
    public:
        Block(BlockData blockData, const std::string& name = "Block");
        ~Block();

        void Init() override;
        void Draw() override;
        void Update(float ms) override;

    private:
        static std::map<BlockType, std::string> s_BlockFilenames;

        graphics::Brush m_BrushBlock;
        
        BlockType m_BlockType;
    };
}