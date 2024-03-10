#pragma once

#include "input.h"
#include "paradox_lib.h"
#include"render_interface.h"

extern "C"
{
    EXPORT_FN void update_game(RenderData* renderDataIn, Input* inputIn);
}