#pragma once

#include"assets.h"
#include"paradox_lib.h"


constexpr int MAX_TRANSFORMS = 1000;

struct OrthographicCamera2D
{
    float zoom = 1.0f;
    Vec2 dimensions;
    Vec2 position;
};

struct Transform
{
    Vec2 pos;
    Vec2 size;
    IVec2 atlasOffset;
    IVec2 spriteSize;
};

struct RenderData
{
    OrthographicCamera2D gameCamera;
    OrthographicCamera2D uiCamera;

    int transformCount;
    Transform transforms[MAX_TRANSFORMS];
};

static RenderData* renderData;

void draw_sprite(SpriteID spriteID, Vec2 pos)
{
    Sprite sprite = get_Sprite(spriteID);

    Transform transform = {};
    transform.pos = pos - vec_2(sprite.spriteSize) / 2.0f;
    transform.size = vec_2(sprite.spriteSize);
    transform.atlasOffset = sprite.atlasOffset;
    transform.spriteSize = sprite.spriteSize;

    renderData->transforms[renderData->transformCount++] = transform;
}