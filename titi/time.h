#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <stdlib.h> 
#include <stdio.h> 
#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include <SDL/SDL_image.h> 

typedef struct
{  
//Le temps quand le timer est lancé
    int startTicks;

    //Les "ticks" enregistré quand le Timer a été mit en pause
    int pausedTicks;

    //Le status du Timer
    int paused;
    int started;

}timer;



typedef struct Time {
	SDL_Surface * T1[20];
	SDL_Surface * T2[12];
	SDL_Surface * T3[7];
	SDL_Surface * T4;
	SDL_Surface * timeSurf;
	SDL_Rect postime;
	SDL_Rect pos[4];
	timer anim;
	int ms,s,m;
	
} Time;


void initTimer(timer *t);
void startTimer(timer *t);
int  get_ticks(timer *t);

void initializerTemps(Time *time);
void updateTemps(Time *time);
void afficherTemps(Time time,SDL_Surface *screen);

 #endif
