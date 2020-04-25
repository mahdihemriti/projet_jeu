#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"


void init_background(background bg[],int n)
{
int i;
char img[100];
	
for(i=0;i<n;i++)
{	
	if (i>100) 
		snprintf (img, sizeof img, "/home/mahdi/jeu/background/background photo_00%d.jpg",i);
	
	else if (i>10) 
		snprintf (img, sizeof img, "/home/mahdi/jeu/background/background photo_000%d.jpg",i);
	
	else 
		snprintf (img, sizeof img, "/home/mahdi/jeu/background/background photo_0000%d.jpg",i);

bg[i].bgpos.x=0;
bg[i].bgpos.y=0;
bg[i].img=IMG_Load(img);
}


}

void affichage_background(SDL_Surface *screen,background bg[],int i)
{

SDL_BlitSurface(bg[i].img,NULL,screen,&bg[i].bgpos);
}

