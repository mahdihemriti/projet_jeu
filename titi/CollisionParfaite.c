#include "CollisionParfaite.h"



SDL_Color GetPixel(SDL_Surface *backgroundMasque,int x,int y)
{
SDL_Color color;
Uint32 col=0;
char* pPosition=(char* ) backgroundMasque->pixels;
pPosition+= (backgroundMasque->pitch * y);
pPosition+= (backgroundMasque->format->BytesPerPixel *x);
memcpy(&col ,pPosition ,backgroundMasque->format->BytesPerPixel);
SDL_GetRGB(col,backgroundMasque->format, &color.r, &color.g, &color.b);

return (color);
}


void init(SDL_Color *couleur_obstacle,SDL_Rect posperso,SDL_Rect pos[])
{
int x,y,w,h;
couleur_obstacle->r=0;
couleur_obstacle->g=0;
couleur_obstacle->b=0;
x= posperso.x;
y= posperso.y;
w = 80;
h = 122;

//up
pos[0].x=x+5;		pos[0].y=y;
pos[1].x=x+w/2;		pos[1].y=y;
pos[2].x=x+w-5;		pos[2].y=y;
//left
pos[3].x=x;			pos[3].y=y+5;
pos[4].x=x;			pos[4].y=y+h/2;
pos[5].x=x;	    	pos[5].y=y+h-5;
//right
pos[6].x=x+w;		pos[6].y=y+5;
pos[7].x=x+w;		pos[7].y=y+h/2;
pos[8].x=x+w;	    pos[8].y=y+h-5;
//down
pos[9].x=x+10;			pos[9].y=y+h;
pos[10].x=x+w/2;		pos[10].y=y+h;
pos[11].x=x+w-10;		pos[11].y=y+h;


}


int CollisionParfaite(SDL_Surface *backgroundMasque,SDL_Rect posperso,int direction)
{
SDL_Rect pos[12];
int collision=0;
int i;
SDL_Color color;
SDL_Color couleur_obstacle;

init(&couleur_obstacle,posperso,pos);


switch(direction)

{
	case RIGHT:
		for(i=6;i<9;i++)
		{
			//printf("n=%d | pos.x=%d et pos.y=%d\n",i,pos[i].x,pos[i].y);
			color=GetPixel(backgroundMasque,pos[i].x,pos[i].y);

 			if (color.r==couleur_obstacle.r && color.g==couleur_obstacle.g && color.b==couleur_obstacle.b) 
 			{
 				collision=1;
 				printf("collision RIGHT dans %d\n",i);
 			}
		}

	break;

	case LEFT:
		for(i=3;i<6;i++)
		{
			//printf("n=%d | pos.x=%d et pos.y=%d\n",i,pos[i].x,pos[i].y);
			color=GetPixel(backgroundMasque,pos[i].x,pos[i].y);
 			if (color.r==couleur_obstacle.r && color.g==couleur_obstacle.g && color.b==couleur_obstacle.b) 
 			{
 				printf("collision LEFT dans %d\n",i);
 				collision=1;
 			}
		}

	break;

	case UP:
		for(i=0;i<3;i++)
		{
			//printf("n=%d | pos.x=%d et pos.y=%d\n",i,pos[i].x,pos[i].y);
			color=GetPixel(backgroundMasque,pos[i].x,pos[i].y);
 			if (color.r==couleur_obstacle.r && color.g==couleur_obstacle.g && color.b==couleur_obstacle.b) 
 			{
 				printf("collision UP dans %d\n",i);
 				collision=1;
 			}
		}

	break;

	case DOWN:
		for(i=9;i<12;i++)
		{
			//printf("n=%d | pos.x=%d et pos.y=%d\n",i,pos[i].x,pos[i].y);
			color=GetPixel(backgroundMasque,pos[i].x,pos[i].y);
 			if (color.r==couleur_obstacle.r && color.g==couleur_obstacle.g && color.b==couleur_obstacle.b) 
 			{
 				//printf("collision DOWN dans %d\n",i);
 				collision=1;
 			}
		}
	break;

}
//printf ("%d\n",collision);

return collision;

}
