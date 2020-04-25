#ifndef PERSO_h_
#define PERSO_h_
#include <stdlib.h> 
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> 
#include "CONST_DEF.h"
#include"time.h"
#include "vie_score.h"



typedef struct personnage
{
	SDL_Surface * p[NB_DIRECTION][NB_FRAMES];
	SDL_Rect posperso;
	SDL_Rect vitesse;
	int frame;
	int direction;
    int score;
    vie Vie;
	int state;
	int w;
	int h;
	timer anim;	
        
}personnage;

void init_personnage(personnage *Perso);
void update_perso(personnage *p,SDL_Surface *screen,SDL_Surface *surfM,int *onGround);
void anim_perso(personnage *Perso);
void affiche_perso(personnage *Perso,SDL_Surface *screen,SDL_Rect camera);
void Move_perso(SDL_Event event,personnage *Perso,int *onGround);



#endif
