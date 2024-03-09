#pragma once

#include "input.h"
#include "paradox_lib.h"
#include "render_interface.h"

// Game Globals 


// Game Struct


// Game Functions (Exposed)
extern "C"
{
    EXPORT_FN void update_game(RenderData* renderDataIn, Input* inputIn);
}
