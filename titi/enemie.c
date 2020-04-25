#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "enemie.h"






void set_clips(enemie *E)
{
int i=0,j=0;


for(i=0;i<2;i++)
{
    for(j=0;j<3;j++)
    {
    E->clips[ i ][ j ].x = ENEMIE_WIDTH * j;
    E->clips[ i ][ j ].y = ENEMIE_HEIGHT * i;
    E->clips[ i ][ j ].w = ENEMIE_WIDTH;
    E->clips[ i ][ j ].h = ENEMIE_HEIGHT;

    }

}

}


void inisialiser_enemie (enemie *E)
{

E->enemie=IMG_Load("cat.png");
E->PosEnemie.x=940;
E->PosEnemie.y=390;
E->PosEnemie.w=ENEMIE_WIDTH;
E->PosEnemie.h=ENEMIE_HEIGHT;
E->frame=0;
E->direction=0;
E->state=0;
initTimer(&E->anim);
startTimer(&E->anim);

}


void MoveEnnemi(enemie *E)
{
        	if (E->direction==0)
        	{
        		E->PosEnemie.x +=4;

        	}
        	if(E->direction==1)
        	{
        		E->PosEnemie.x -=4;
        	}

}



void update_ennemi(enemie *E )
{
	if(E->PosEnemie.x>=1150)
	{
		E->direction=1;


	}
	else if(E->PosEnemie.x<=940)
	{
	  E->direction=0;
	}

}
/*********************************************************************************************************/
/*********************************************************************************************************/

void afficher_enemie (enemie *E,SDL_Surface *screen,SDL_Rect camera)
{
  SDL_Rect pos;
  pos.x=E->PosEnemie.x-camera.x;
  pos.y=E->PosEnemie.y-camera.y;
	SDL_BlitSurface(E->enemie,&E->clips[E->direction][E->frame],screen,&pos);
}



/*********************************************************************************************************/
/*********************************************************************************************************/


void animation (enemie *E)
{
 if( get_ticks(&E->anim) >= 120) 
  {

      // On remet le timer à 0
      startTimer(&E->anim);
	E->frame++;
   }
	if (E->frame == 3)
	E->frame=0;

}

/*********************************************************************************************************/
/*********************************************************************************************************/

