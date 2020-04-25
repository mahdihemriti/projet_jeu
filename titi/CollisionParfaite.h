#ifndef CollisionParfaite_h_
#define CollisionParfaite_h_
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"
SDL_Color GetPixel(SDL_Surface *backgroundMasque,int x,int y);
void init(SDL_Color *couleur_obstacle,SDL_Rect posperso,SDL_Rect pos[]);


int CollisionParfaite(SDL_Surface *backgroundMasque,SDL_Rect posperso,int direction);

int collision_surface(SDL_Surface *backgroundMasque,int x,int y);

#endif


