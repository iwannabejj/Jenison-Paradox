#include"assets.h"
#include"paradox_lib.h"
#include"render_interface.h"



void update_game()
{
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y < 10; y++)
        {
            draw_sprite(SPRITE_ATLAS, {x * 100.0f,y * 100.0f}, {100.0f, 100.0f});
        } 
    }       
}
