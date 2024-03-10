#pragma once

#include"assets.h"
#include"paradox_lib.h"


constexpr int MAX_TRANSFORMS = 1000;

struct Transform
{
    Vec2 pos;
    Vec2 size;
    IVec2 atlasOffset;
    IVec2 spriteSize;
};

struct RenderData
{
    int transformCount;
    Transform transforms[MAX_TRANSFORMS];
};

static RenderData* renderData;

void draw_sprite(SpriteID spriteID, Vec2 pos,Vec2 size)
{
    Sprite sprite = get_Sprite(spriteID);

    Transform transform = {};
    transform.pos = pos;
    transform.size = size;
    transform.atlasOffset = sprite.atlasOffset;
    transform.spriteSize = sprite.spriteSize;

    renderData->transforms[renderData->transformCount++] = transform;
}