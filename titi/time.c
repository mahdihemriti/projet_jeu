#include <stdio.h>
#include"time.h"


void initTimer(timer *t)
{
   //Initialisation des variables
    t->startTicks = 0;
    t->pausedTicks = 0;
    t->paused = 0;
    t->started = 0;


}
void startTimer(timer *t)
{
  //Permet de mettre le timer en marche
    t->started = 1;

    //Permet de mettre le timer en mode non pause
     t->paused = 0;

    //On récupére le temps courant
    t->startTicks = SDL_GetTicks();
}



int  get_ticks(timer *t)
{
//Si le timer est en marche
    if( t->started == 1 )
    {
        //Si le timer est en pause
        if( t->paused == 1 )
        {
            //On retourne le nombre de ticks quand le timer a été mis en pause
            return t->pausedTicks;
        }
        else
        {
            //On retourne le temps courant moins le temps quand il a démarré
            return SDL_GetTicks() - t->startTicks;
        }
    }

    //Si le timer n'est pas en marche
    else return 0;


}


void initializerTemps(Time *time)
{
	char img[50];
	int i,j=2,k=0;
	//init_les premier image

	time->T1[0]=IMG_Load("/home/mahdi/titi/countdown timer/0.png");

	time->T2[0]=IMG_Load("/home/mahdi/titi/countdown timer/0.png");

	time->T1[1]=IMG_Load("/home/mahdi/titi/countdown timer/1.png");

	time->T2[1]=IMG_Load("/home/mahdi/titi/countdown timer/1.png");

	time->T3[6]=IMG_Load("/home/mahdi/titi/countdown timer/0.png");

	time->T4=IMG_Load("/home/mahdi/titi/countdown timer/0.png");

	for (int i = 2; i < 20; ++i)
	{
		snprintf (img, sizeof img,"/home/mahdi/titi/countdown timer/%d.png",i);
		//init T1
		time->T1[i]=IMG_Load(img);

		//init T2
		if(i>=10)
		{
			time->T2[j]=IMG_Load(img);
			j++;
		}

		//init T3
		if(i>=14)
		{
			time->T3[k]=IMG_Load(img);
			k++;
		}

	}



	//init T1
	time->pos[0].x=590;
	time->pos[0].y=22;
	//init T2
	time->pos[1].x=570;
	time->pos[1].y=22;
	//init T3
	time->pos[2].x=540;
	time->pos[2].y=22;
	//init T4
	time->pos[3].x=520;
	time->pos[3].y=22;


	time->ms=0;
	time->s=0;
	time->m=0;
	time->timeSurf=IMG_Load("/home/mahdi/titi/countdown timer/time.png");
	time->postime.x=503;
	time->postime.y=7;
	initTimer(&time->anim);
	startTimer(&time->anim);



}

void updateTemps(Time *time)
{
	if (time->m != 6 || time->s!=0 || time->ms!=0 )

	{
		if( get_ticks(&time->anim) >= 250) 
 	 	{

     	 	// On remet le timer à 0
      		startTimer(&time->anim);

      		// On passe à la frame suivante
      		if (time->s==0 && time->ms==0 ||time->s==1 && time->ms==1) time->m++;
      		if(time->ms==0 ||time->ms==1 ) time->s++;
      		time->ms++;

      	

 		 }
		if(time->s >=12) time->s = 0;
		if(time->ms >=20) time->ms = 0;
		


	

	


	}



}


void afficherTemps(Time time, SDL_Surface *screen)
{

	//SDL_BlitSurface(time.timeSurf,NULL,screen,&time.postime);
	SDL_BlitSurface(time.T1[time.ms],NULL,screen,&time.pos[0]);
	SDL_BlitSurface(time.T2[time.s],NULL,screen,&time.pos[1]);
	SDL_BlitSurface(time.T3[time.m],NULL,screen,&time.pos[2]);
	SDL_BlitSurface(time.T4,NULL,screen,&time.pos[3]);



}
