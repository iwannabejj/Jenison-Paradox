#pragma once

#include "input.h"
#include "paradox_lib.h"
#include"render_interface.h"

constexpr int tset = 5;

struct GameState
{   
    bool initialized = false;
    IVec2 playerPos;
};

static GameState* gameState;


extern "C"
{
    EXPORT_FN void update_game(GameState* gameStateIn, RenderData* renderDataIn, Input* inputIn);
}