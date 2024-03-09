#pragma once

#include "paradox_lib.h"

enum SpriteID
{
    SPRITE_RAINBOW,

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
        case SPRITE_RAINBOW:
        {
            sprite.atlasOffset = {0, 0};
            sprite.spriteSize = {16, 16};
        }
    }

    return sprite;
}   