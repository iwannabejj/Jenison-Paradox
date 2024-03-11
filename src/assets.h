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

Sprite get_Sprite(SpriteID spriteid)
{
    Sprite sprite = {};
    
    switch(spriteid)
    {
        case SPRITE_ATLAS:
        {
            sprite.atlasOffset = {30, 0};
            sprite.spriteSize = {50, 50};
        }
    }

    return sprite;
}   