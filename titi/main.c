#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_audio.h>
#include <SDL/SDL_timer.h>
#include "perso.h"
#include "CollisionParfaite.h"
#include "background.h"
#include "bouton.h"
#include "enemie.h"
#include "time.h"
#include "scrolling.h"
#include "CONST_DEF.h"
const int BG_NR=252;
const int Nbr_Pages=3;

int main(int argc, char *argv[])
{
int x=0;
//*******variable menu***********

int n=11,j=1,BoutonSelectionne=0,Fullscreen=0,sound=1;
page p[3];
background bg[BG_NR];
SDL_Surface *img=NULL;
int pageActuelle=0;


//**************init menu**************
init_background(bg,BG_NR);
init_Pages(p,Nbr_Pages);

//************fps********************
timer fps;
initTimer(&fps);


//*************surface********************
SDL_Surface *screen=NULL;
SDL_Surface *surf =NULL;
SDL_Surface *surfM =NULL;
surf =IMG_Load("background.jpg");
surfM = IMG_Load("backgroundMasque.jpg");

//***************v*****************
int continuer=1;
int fenetre=0;
int onGround=0;
TTF_Init();
Time time;
enemie E;
set_clips(&E);
inisialiser_enemie (&E);
personnage Perso; 
init_personnage(&Perso);

SDL_Event event;

int collision;
SDL_Rect camera = { 0, 0, 640, 480 };
screen=SDL_SetVideoMode(1278,718,32,SDL_HWSURFACE | SDL_DOUBLEBUF);

	SDL_WM_SetCaption("Contagion",NULL);
	if(SDL_INIT_EVERYTHING==-1)
	{
		fprintf(stderr,"Init Video Error: %s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}


initializerTemps(&time);
while (continuer)
{ 
startTimer(&fps);


//*********affichage menu***********
if (fenetre==0)
{ 

	if(j==BG_NR) j=0;  
 	affichage_background(screen,bg,j);
 	afficher_pages(p,pageActuelle,screen);
 	j++;

}

//*********affichage jeu**************
else if (fenetre==1)

{   if (x==0)
	{
		screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);


		x=1;
	}
	set_camera(&camera,Perso.posperso);
	SDL_BlitSurface(surf,&camera,screen,NULL);
	
	afficherTemps(time,screen);
	updateTemps(&time);

	update_perso(&Perso,screen,surfM,&onGround);
	anim_perso(&Perso);
	affiche_perso(&Perso,screen,camera);

	afficher_enemie (&E,screen,camera);
	MoveEnnemi(&E);
	animation (&E);
 	update_ennemi(&E);


}

SDL_Flip(screen);




//****************input****************
   while(SDL_PollEvent(&event)!=0)
   {
   		if (fenetre==0) //update case menu
    	{ 	
    		switch(event.type)
 			{
			case SDL_MOUSEMOTION:
				mouse(event,screen,p,pageActuelle,&continuer);
				BoutonSelectionne=0;
				break;

			case SDL_MOUSEBUTTONUP:
				mouseClick(event,screen,p,&pageActuelle,&continuer,&fenetre);
				break;

			case SDL_KEYDOWN:
				keyboard(event,p,&pageActuelle,&continuer,&fenetre);
				break;

			case SDL_QUIT:
				continuer = 0;
				break;

			default: break;

	}
      	}
			
	else if (fenetre==1)//update case jeu   
	{
			Move_perso(event,&Perso,&onGround);	
           if(event.type==SDL_QUIT)
                continuer = 0;
	}
      

   }




  while( get_ticks(&fps) < 1000 /30)
        {
            //Attente...
        }

  
}

SDL_FreeSurface(surf);
SDL_FreeSurface(surfM);

SDL_Quit();

}


