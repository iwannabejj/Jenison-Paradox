#pragma once

#include "paradox_lib.h"

enum SpriteID
{
    SPRITE_ATLAS,

    SPRITE_COUNT
};

struct Sprite
{
    IVec2 atlasOffset;
    IVec2 spriteSize;
};

Sprite get_Sprite(SpriteID spriteID)
{
    Sprite sprite = {};
    
    switch(spriteID)
    {
        case SPRITE_ATLAS:
        {
            sprite.atlasOffset = {0, 0};
            sprite.spriteSize = {16, 16};
        }
    }

    return sprite;
}   