#include "bouton.h"

void init_Pages(page p[],int Nbr_Pages)
{
int x=30,y=204,k=0,i,j;
char img[50];
printf("heyyy1\n");
p[0].NbrBoutons=4;
p[1].NbrBoutons=3;
p[2].NbrBoutons=5;

//init page 0
 snprintf (img, sizeof img, "/home/mahdi/titi/b/%d.png",k);
   p[0].b[0].t[0]=IMG_Load(img);
   snprintf (img, sizeof img, "/home/mahdi/titi/b/%d.png",k+1);
   p[0].b[0].t[1]=IMG_Load(img);
   p[0].b[0].existe=1;
   p[0].b[0].etat=0;
   p[0].b[0].PosBouton[0].x=x;
   p[0].b[0].PosBouton[0].y=y;
   p[0].b[0].PosBouton[1].x=p[0].b[0].PosBouton[0].x+80;
   p[0].b[0].PosBouton[1].y=p[0].b[0].PosBouton[0].y-7;
   k+=2;
//init boutons page0
   for(j=1;j<p[0].NbrBoutons;j++)
   {
      snprintf (img, sizeof img, "/home/mahdi/titi/b/%d.png",k);
      p[0].b[j].t[0]=IMG_Load(img);
      snprintf (img, sizeof img, "/home/mahdi/titi/b/%d.png",k+1);
      p[0].b[j].t[1]=IMG_Load(img);
      p[0].b[j].etat=0;
      p[0].b[j].existe=1;
      p[0].b[j].PosBouton[0].x=p[0].b[j-1].PosBouton[0].x;
      p[0].b[j].PosBouton[0].y=p[0].b[j-1].PosBouton[0].y+84;
      p[0].b[j].PosBouton[1].x=p[0].b[j].PosBouton[0].x+80;										
      p[0].b[j].PosBouton[1].y=p[0].b[j].PosBouton[0].y-7;
      k+=2;
   }



//init pages

for(i=1;i<Nbr_Pages;i++)
{
//init bouton n1
printf("heyyy3\n");
   snprintf (img, sizeof img, "/home/mahdi/titi/b/%d.png",k);
   p[i].b[0].t[0]=IMG_Load(img);
   snprintf (img, sizeof img, "/home/mahdi/titi/b/%d.png",k+1);
   p[i].b[0].t[1]=IMG_Load(img);
   p[i].b[0].existe=1;
   p[i].b[0].etat=0;
   p[i].b[0].PosBouton[0].x=x;
   p[i].b[0].PosBouton[0].y=y;
   p[i].b[0].PosBouton[1].x=p[i].b[0].PosBouton[0].x+80;
   p[i].b[0].PosBouton[1].y=p[i].b[0].PosBouton[0].y-7;
   k+=2;
//init boutons
printf("heyyy4\n");

   for(j=1;j<p[i].NbrBoutons-1;j++)
   {
      snprintf (img, sizeof img, "/home/mahdi/titi/b/%d.png",k);
      p[i].b[j].t[0]=IMG_Load(img);
	printf("%d %s\n",i,img);
      snprintf (img, sizeof img, "/home/mahdi/titi/b/%d.png",k+1);
      p[i].b[j].t[1]=IMG_Load(img);
      printf("%s\n",img);
      p[i].b[j].etat=0;
      p[i].b[j].existe=1;
      p[i].b[j].PosBouton[0].x=p[i].b[j-1].PosBouton[0].x;
      p[i].b[j].PosBouton[0].y=p[i].b[j-1].PosBouton[0].y+84;
      p[i].b[j].PosBouton[1].x=p[i].b[j].PosBouton[0].x+80;										
      p[i].b[j].PosBouton[1].y=p[i].b[j].PosBouton[0].y-7;
      k+=2;
   }
//bouton back
   p[i].b[j].t[0]=IMG_Load("/home/mahdi/titi/b/back.png");
   p[i].b[j].t[1]=IMG_Load("/home/mahdi/titi/b/fback.png");
   p[i].b[j].etat=0;
   p[i].b[j].existe=1;
   p[i].b[j].PosBouton[0].x=34;
   p[i].b[j].PosBouton[0].y=655;
   p[i].b[j].PosBouton[1].x=20;
   p[i].b[j].PosBouton[1].y=655;
	





}
//exception page 2
p[2].b[2].etat=0;
p[2].b[2].existe=1;
p[2].b[2].PosBouton[0].x=p[2].b[1].PosBouton[0].x;
p[2].b[2].PosBouton[0].y=p[2].b[1].PosBouton[0].y;
p[2].b[2].PosBouton[1].x=p[2].b[1].PosBouton[0].x+80;										
p[2].b[2].PosBouton[1].y=p[2].b[1].PosBouton[0].y-7;

p[2].b[1].etat=0;
p[2].b[1].existe=0;
p[2].b[1].PosBouton[0].x=p[2].b[0].PosBouton[0].x;
p[2].b[1].PosBouton[0].y=p[2].b[0].PosBouton[0].y;
p[2].b[1].PosBouton[1].x=p[2].b[0].PosBouton[0].x+80;										
p[2].b[1].PosBouton[1].y=p[2].b[0].PosBouton[0].y-7; 

p[2].b[3].etat=0;
p[2].b[3].existe=0;
p[2].b[3].PosBouton[0].x=p[2].b[2].PosBouton[0].x;
p[2].b[3].PosBouton[0].y=p[2].b[2].PosBouton[0].y;
p[2].b[3].PosBouton[1].x=p[2].b[2].PosBouton[0].x+80;										
p[2].b[3].PosBouton[1].y=p[2].b[2].PosBouton[0].y-7; 
}







void afficher_pages(page p[],int Num_Page,SDL_Surface *screen)
{
int i;
int etat;

for(i=0;i<p[Num_Page].NbrBoutons;i++)
{
   if(p[Num_Page].b[i].existe==1)
   {
      etat=p[Num_Page].b[i].etat;
      SDL_BlitSurface(p[Num_Page].b[i].t[etat],NULL,screen,&p[Num_Page].b[i].PosBouton[etat]);
   }
}
}







void mouse(SDL_Event event,SDL_Surface *screen,page p[],int Num_Page,int *continuer)
{

/*SDL_Event *events;
events = (SDL_Event*)calloc(sizeof(SDL_Event), 100);

				
				int count = SDL_PeepEvents(events, 100, SDL_PEEKEVENT, SDL_EVENTMASK (SDL_MOUSEMOTION));
printf("count=%d\n",count);*/

int xm,ym,i;					
int h,w,x,y;	
xm=event.button.x;
ym=event.button.y;     

for(i=0;i<p[Num_Page].NbrBoutons;i++)
{ 
	h=p[Num_Page].b[i].t[0]->h;
	w=p[Num_Page].b[i].t[0]->w;
	x=p[Num_Page].b[i].PosBouton[0].x;
	y=p[Num_Page].b[i].PosBouton[0].y;


                                       if (xm>x && xm<x+w && ym>y && ym<y+h && p[Num_Page].b[i].existe==1)
	
								{       
                                                                        p[Num_Page].b[i].etat=1;
								       
										
					
								}


                                                           else {	
									p[Num_Page].b[i].etat=0;	
							
     								}                                                                 
								       
}
							
}


void mouseClick(SDL_Event eventClick,SDL_Surface *screen,page p[],int *Num_Page,int *continuer,int *fenetre)
{
int xm,ym,h,w,x,y,i;
xm=eventClick.button.x;
ym=eventClick.button.y;

	
for(i=0;i<p[*Num_Page].NbrBoutons;i++)
{ 
	if (p[*Num_Page].b[i].etat==1 && p[*Num_Page].b[i].existe==1 && eventClick.button.button==SDL_BUTTON_LEFT)
		{
									
                 	
			ChangePage(Num_Page,i,p,fenetre);
			break;

		}

}
								

}



void keyboard(SDL_Event event,page p[],int *Num_Page,int *continuer,int *fenetre)
{


int i,j;
int b1=0;
int bn=p[*Num_Page].NbrBoutons-1;

while(p[*Num_Page].b[b1].existe!=1) b1++;
printf("le premier bouton =%d\n",b1);
while(p[*Num_Page].b[bn].existe!=1) bn--;
printf("le dernier bouton =%d\n",bn);
i=b1;

while(i<p[*Num_Page].NbrBoutons && p[*Num_Page].b[i].etat!=1) i++;

if (i==p[*Num_Page].NbrBoutons) 
{
p[*Num_Page].b[b1].etat=1;

}

else
{
printf("i=%d\n",i);


					switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							*continuer = 0;
							break;
                                                case SDLK_UP:
                                                    if (i==b1) 
							{
							p[*Num_Page].b[b1].etat=0;			
							p[*Num_Page].b[bn].etat=1;
								
							}
						else
							{
							p[*Num_Page].b[i].etat=0;
							i--;
							while(i>=b1 && p[*Num_Page].b[i].existe!=1) i--;
							printf("i=%d",i);
							p[*Num_Page].b[i].etat=1;
							
                                                         }                     
                                                                    
                                                        break;        

                                                 case SDLK_DOWN:
                                                      if (i==bn) 
							{
							p[*Num_Page].b[b1].etat=1;			
							p[*Num_Page].b[bn].etat=0;
								
							}
						else
							{
							p[*Num_Page].b[i].etat=0;
							i++;
							while(i<=bn&& p[*Num_Page].b[i].existe!=1) i++;
							p[*Num_Page].b[i].etat=1;
							
                                                         }                           
                                                                    
                                                        break; 
						case SDLK_RETURN:
							for(j=0;j<p[*Num_Page].NbrBoutons;j++) p[*Num_Page].b[j].etat=0;
							ChangePage(Num_Page,i,p,fenetre);
							break;
						
						
                                          

					}
  }                         
                                                                    
}                                                       






void ChangePage(int *pageActuelle,int bouton_presse,page p[],int *fenetre)
{
printf("pageActuelle= %d\n",*pageActuelle);
switch (*pageActuelle)
{
case 0:
if (bouton_presse==0) *pageActuelle=1;
else if (bouton_presse==1) *pageActuelle=2;

break;

case 1:
if (bouton_presse==2) *pageActuelle=0;
else if (bouton_presse==0) 
{
*fenetre =1;
*pageActuelle=0;
}
break;

case 2:
if (bouton_presse==4) *pageActuelle=0;
else if (bouton_presse==0 && p[2].b[0].existe==1) 
	{
	  p[2].b[0].existe=0;
	  p[2].b[1].existe=1;
	  p[2].b[1].etat=1;
	}
else if (bouton_presse==1 && p[2].b[1].existe==1) 
	{
	  p[2].b[1].existe=0;
	  p[2].b[0].existe=1;
	  p[2].b[0].etat=1;
	}
else if (bouton_presse==2 && p[2].b[2].existe==1) 
	{
	  p[2].b[3].existe=1;
	  p[2].b[2].existe=0;
	  p[2].b[3].etat=1;
	}

else if (bouton_presse==3 && p[2].b[3].existe==1) 
	{
	  p[2].b[2].existe=1;
	  p[2].b[3].existe=0;
	  p[2].b[2].etat=1;
	}
break;




}



}


















