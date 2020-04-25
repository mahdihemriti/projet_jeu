#ifndef ENEMIE_H_INCLUDED
#define ENEMIE_H_INCLUDED
#include "perso.h"
#include "CONST_DEF.h"
typedef struct enemie
{
SDL_Surface *enemie;
SDL_Rect PosEnemie;
SDL_Rect clips[DIRECTIONS_ENEMIE][NBR_FRAMES];
int frame;
int direction;
int moving;
int state;
timer anim;
}enemie;

void set_clips(enemie *E);
void inisialiser_enemie (enemie *E);
void MoveEnnemi(enemie *E);
void update_ennemi(enemie *E);
void afficher_enemie (enemie *E,SDL_Surface *screen,SDL_Rect camera);
void animation (enemie *E);


 #endif // ENEMIE_H_INCLUDED
