#include "perso.h"
#include "CollisionParfaite.h"


void init_personnage(personnage *Perso)
{
int i,j,k=0;
char img[50];
   //image load
   for(i=0; i<NB_DIRECTION ;i++)
   {
      for(j=0;j<NB_FRAMES;j++)
      {
         if(i==0)   snprintf (img, sizeof img,"/home/mahdi/travaille/pd/Idle__00%d.png",j);
         else if (i==1)   snprintf (img, sizeof img,"/home/mahdi/travaille/pd/Run__00%d.png",j);
         else if (i==2)   snprintf (img, sizeof img,"/home/mahdi/travaille/pg/RunL__00%d.png",j);
         else if (i==3)   snprintf (img, sizeof img,"/home/mahdi/travaille/pd/Jump__00%d.png",j);
         else if (i==4)   snprintf (img, sizeof img,"/home/mahdi/travaille/pd/Slide__00%d.png",j);
         else if (i==5)   snprintf (img, sizeof img,"/home/mahdi/travaille/pg/Jump__00%d.png",j);
	 else if (i==6)   snprintf (img, sizeof img,"/home/mahdi/travaille/pg/Slide__00%d.png",j);
	 else if (i==7)   snprintf (img, sizeof img,"/home/mahdi/travaille/pg/Idle__00%d.png",j);
	printf("nom=%s\n",img);
      Perso->p[i][j]=IMG_Load(img);
   
      }

   }

Perso->posperso.x=0;
Perso->posperso.y=300;
Perso->posperso.w=PERSO_WIDTH;
Perso->posperso.h=PERSO_HEIGHT;
Perso->vitesse.x=0;
Perso->vitesse.y=0;
Perso->direction=0;
Perso->frame=0;
Perso->score=0;
init_vie(&Perso->Vie);
initTimer(&Perso->anim);
startTimer(&Perso->anim);
 
Perso->state=1;

}



void update_perso(personnage *Perso,SDL_Surface *screen,SDL_Surface *surfM,int *onGround)
{  
int collision;
int t=0;
int c;
int c2;






if (Perso->direction != 4 && Perso->direction != 6 )
{
  //*************movement right****************
  if (Perso->vitesse.x >0) 
  {
    Perso->direction=1;
    collision=CollisionParfaite(surfM,Perso->posperso,RIGHT);
    if(collision==1) Perso->posperso.x-=Perso->vitesse.x;
  }
  //*************movement left****************
  else if (Perso->vitesse.x <0) 
  {  
    Perso->direction=2;
    collision=CollisionParfaite(surfM,Perso->posperso,LEFT);
    if(collision==1) Perso->posperso.x-=Perso->vitesse.x;


  }
  //*************movement up****************
  else if (Perso->vitesse.y <0 && Perso->state ==RIGHT) Perso->direction=3;
  else if (Perso->vitesse.y <0 && Perso->state ==LEFT) Perso->direction=5;
}



//*******perso dans l'air**********

c=CollisionParfaite(surfM,Perso->posperso,DOWN);
if (c==0) *onGround=0;
 
if(*onGround==1 && Perso->vitesse.y>=0)
{
Perso->vitesse.y=0;

}

else
{

Perso->vitesse.y+=GRAVITY; 


}
 /*collision=CollisionParfaite(surfM,Perso->posperso,UP);
if (*onGround==0 && Perso->vitesse.y<0 && collision==1) Perso->vitesse.y=0;*/

//********frainage slide*******

if(Perso->direction==4 && Perso->vitesse.x >0)
{
Perso->vitesse.x-=BREAKING;

}
else if(Perso->direction==6 && Perso->vitesse.x <0)
{
Perso->vitesse.x+=BREAKING;

}

//printf("vitesse.x=%d && vitesse.y=%d\n",Perso->vitesse.x,Perso->vitesse.y);

//*********Predect collision***************
SDL_Rect nextPos;
nextPos.x=Perso->posperso.x + Perso->vitesse.x;
nextPos.y=Perso->posperso.y + Perso->vitesse.y;
c2=CollisionParfaite(surfM,nextPos,DOWN);
while(c2==1)
{
nextPos.y--;
c2=CollisionParfaite(surfM,nextPos,DOWN);
if (c2==0) *onGround=1;
t=1;
}

//**************mouvement********
Perso->posperso.x = nextPos.x;
Perso->posperso.y = nextPos.y+t;

 if( ( Perso->posperso.x < 0 ) || ( Perso->posperso.x + PERSO_WIDTH > LEVEL_WIDTH ) )
    {
        //On revient
        Perso->posperso.x -= Perso->vitesse.x;
    }

   if( ( Perso->posperso.y < 0 ) || ( Perso->posperso.y + PERSO_HEIGHT  > LEVEL_HEIGHT ) )
    {
        //On revient
        Perso->posperso.y -= Perso->vitesse.y;
    }
 

//*******position stable***********
if(Perso->vitesse.y == 0 && Perso->vitesse.x == 0 && *onGround==1)
{
  if(Perso->state == RIGHT) Perso->direction=0;
  else if (Perso->state ==LEFT) Perso->direction=7;
}
//***********jump********
if(*onGround!=1)
{
  if(Perso->state == RIGHT) Perso->direction=3;
  else if (Perso->state ==LEFT) Perso->direction=5;
}


//printf("direction=%d\n",Perso->direction);



}


void anim_perso(personnage *Perso)
{

  if( get_ticks(&Perso->anim) >= 100) 
  {

      // On remet le timer à 0
      startTimer(&Perso->anim);

      // On passe à la frame suivante
      Perso->frame++;
  }

  if (Perso->frame > 9)
  {
      Perso->frame=0;
  }

}

void affiche_perso(personnage *Perso,SDL_Surface *screen,SDL_Rect camera)
{
  SDL_Rect pos;

  pos.x=Perso->posperso.x-camera.x;
  pos.y=Perso->posperso.y-camera.y;
SDL_BlitSurface(Perso->p[Perso->direction][Perso->frame], NULL,screen, &pos);
afficher(Perso->Vie,screen);

}



void Move_perso(SDL_Event event,personnage *Perso,int *onGround)
{

 if( event.type == SDL_KEYDOWN )
    {
        //ajustement de la vitesse
        switch( event.key.keysym.sym )
        {
           case SDLK_UP: 
		if(*onGround==1)
		{
    *onGround=0;
		Perso->vitesse.y -=24;  
		Perso->frame=0;
		}
							break;
           case SDLK_DOWN: 
		if( *onGround==1 && Perso->direction != 4 && Perso->direction != 6)
		{
			
		Perso->frame=0;

			if(Perso->state == RIGHT) 
			{
			Perso->direction=4;
			Perso->vitesse.x =10; 
			}

			else if (Perso->state ==LEFT) 
			{
			Perso->vitesse.x =-10; 	
			Perso->direction=6;
			}
		}
			    
							break;

            case SDLK_LEFT: 
		if (Perso->direction != 4 && Perso->direction != 6 )
		{
		Perso->vitesse.x =-5;
		Perso->frame=0;
		Perso->state =LEFT;
		}
							break;
	

          case SDLK_RIGHT:
		if (Perso->direction != 4 && Perso->direction != 6 )
		{
		Perso->frame=0;
	 	Perso->vitesse.x =5;
		Perso->state =RIGHT;
		}
 							break;
	
            default: break;
        }
     }


   else if( event.type == SDL_KEYUP )
    	{
       		//ajustement de la vitesse
        	switch( event.key.keysym.sym )
        	{
         
            	case SDLK_LEFT: 

			if (Perso->direction != 4 && Perso->direction != 6 && Perso->vitesse.x<0) Perso->vitesse.x =0; 
		
                                                        break;

            	case SDLK_RIGHT:
 
			if (Perso->direction != 4 && Perso->direction != 6 && Perso->vitesse.x>0) Perso->vitesse.x = 0; 

						        break;

            default: break;
        }
    }

}





      /*  case SDL_MOUSEBUTTONUP:
          if(event.button.button == SDL_BUTTON_LEFT )
          {
            p->posperso.x -= 5;
            affiche_personnage(p,screen);
          }
          if(event.button.button == SDL_BUTTON_RIGHT)
          {
           p->posperso.x += 5;
            affiche_personnage(p,screen);
          }
          if(event.button.button== SDL_BUTTON_WHEELUP)
          {
            p->posperso.x+=10;
            p->posperso.y -= 20;
             affiche_personnage(p,screen);
          }
          if(event.button.button == SDL_BUTTON_WHEELDOWN)
          {
            p->posperso.y += 5;
            //affichage d image
          affiche_personnage(p,screen);
          }
        break;
        case SDL_QUIT:

        break;
      }
    }
}*/




