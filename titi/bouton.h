#ifndef bouton_h_
#define bouton_h_
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "background.h"

typedef struct
{
SDL_Surface *t[2];
SDL_Rect PosBouton[2];
int w;
int h;
int etat;
int existe;
}bouton;

typedef struct
{
bouton b[5];
int NbrBoutons;
}page;

void init_Pages(page p[],int Nbr_Pages);
void afficher_pages(page p[],int Num_Page,SDL_Surface *screen);
void mouse(SDL_Event event,SDL_Surface *screen,page p[],int Num_Page,int *continuer);
void mouseClick(SDL_Event eventClick,SDL_Surface *screen,page p[],int *Num_page,int *continuer,int *fenetre);
void keyboard(SDL_Event event,page p[],int *Num_Page,int *continuer,int *fenetre);
void ChangePage(int *pageActuelle,int bouton_presse,page p[],int *fenetre);






#endif


