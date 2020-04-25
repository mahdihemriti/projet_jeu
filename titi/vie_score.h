#ifndef VIE_SCORE_H_INCLUDED
#define VIE_SCORE_H_INCLUDED
#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include <SDL/SDL_mixer.h> 
#include <SDL/SDL_ttf.h> 


typedef struct 
{
int nbrVie;
SDL_Surface * heart;
SDL_Rect posVie;	
}vie;



void init_vie(vie *v);
void afficher(vie v,SDL_Surface *screen);







#endif