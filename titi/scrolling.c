#include "scrolling.h"

void set_camera(SDL_Rect *camera,SDL_Rect posperso)
{
    camera->x = ( posperso.x + PERSO_WIDTH / 2 ) - SCREEN_WIDTH / 2;
    camera->y = ( posperso.y + PERSO_HEIGHT/ 2 ) - SCREEN_HEIGHT / 2;

     if( camera->x < 0 )
    {
        camera->x = 0;
    }
    if( camera->y < 0 )
    {
        camera->y = 0;
    }
    if( camera->x > LEVEL_WIDTH - camera->w )
    {
        camera->x = LEVEL_WIDTH - camera->w;
    }
    if( camera->y > LEVEL_HEIGHT - camera->h )
    {
        camera->y = LEVEL_HEIGHT - camera->h;
    }
}
