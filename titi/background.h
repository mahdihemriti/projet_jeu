#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

typedef struct
{
SDL_Surface *img;
SDL_Rect bgpos;
}background;



void init_background(background bg[],int n);
void affichage_background(SDL_Surface *screen,background bg[],int i);


#endif

