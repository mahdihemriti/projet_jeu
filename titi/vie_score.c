#include "vie_score.h"

void init_vie(vie *v)
{
	v->nbrVie=3;
	v->heart=IMG_Load("heart.png");
	v->posVie.x=20;
	v->posVie.y=7;
}

void afficher(vie v,SDL_Surface *screen)
{
	for (int i = 0; i < v.nbrVie; ++i)
	{
		SDL_BlitSurface(v.heart, NULL,screen,&v.posVie);
		v.posVie.x+=53;
		
	}


}