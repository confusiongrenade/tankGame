/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
 and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <time.h>
//#include "wall.h"




//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


SDL_Rect EvilTankRECT;


//Button constants
const int BUTTON_WIDTH = 50;
const int BUTTON_HEIGHT = 50;
const int TOTAL_BUTTONS = 1;

const int TANKSIZE = 50;


enum LButtonSprite
{
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};



//Mouse button sprites
SDL_Rect gSpriteClips[ BUTTON_SPRITE_TOTAL ];



//The window renderer
SDL_Renderer* gRenderer = NULL;


/*
 //Button constants
 const int BUTTON_WIDTH = 150;
 const int BUTTON_HEIGHT = 100;
 const int TOTAL_BUTTONS = 1;
 */


#include "LButton.h"

//Buttons objects
LButton gButtons[ TOTAL_BUTTONS ];

LTexture tank;

LTexture evilTank;

#include "mediaLoad.h"


#define PI 3.14159265



//This code moves a red block around the screen using key inputs
//Author: James Marvin
//Using SDL, SDL_image, standard IO, math, and strings


#include "ai.h"
#include "nickplayer.h"
#include "Bullet.h"
#include "nickWall.h"
int main( int argc, char* args[] )
{
    int xshift=0;
    int yshift =0;
    int oldx;
    int oldy;
    Bullet playerBullet(0,0);
    
    player tank(0,0,0);
    
   nickWall wallOne(100, 100, 50, 100);
    
    
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;
            
            //Event handler
            SDL_Event e;
            ai enemy(300,300);
            int t;
            t=0;//While application is running
            while( !quit )
            {
                
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    else if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
                                yshift-=10;
                                break;
                                
                            case SDLK_DOWN:
                                yshift+=10;
                                break;
                                
                            case SDLK_LEFT:
                                xshift-=10;
                                break;
                                
                            case SDLK_RIGHT:
                                xshift+=10;
                                break;
                                
                            case SDLK_SPACE:
                                
                                playerBullet.set(tank.getxcenter(), tank.getycenter(), tank.getAngle());
                                break;
                                
                            default:
                                xshift+=0;
                                yshift+=0;
                                break;
                        }
                        
                        
                        tank.move(e);
                    }
                }
                
                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );
                
                //Render red filled quad
                SDL_Rect fillRect = { xshift, yshift, 50, 50};
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
                SDL_RenderFillRect( gRenderer, &fillRect );
                
                //render ai object
                enemy.render();
                tank.render();
                
                gButtons[ 0 ].render(10);
                playerBullet.moving();
                playerBullet.render();
                
                wallOne.collision(&tank, &enemy, e, oldx, oldy);
                
                wallOne.render();
                
                if (playerBullet.hit(enemy.getxcenter(),enemy.getycenter())){
                   // score+=1
                }
                
                //render obstacle
                /*SDL_Rect fillRect3 = { 100, 100, 100, 100};
                 SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
                 SDL_RenderFillRect( gRenderer, &fillRect3 );
                 */
                if (t%25==0) {
                    oldx = enemy.getxcenter();
                    oldy = enemy.getycenter();
                    enemy.move(tank.getxcenter(),tank.getycenter());
                    t++;
                }
                else
                {
                    t++;
                }
                
                
                
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}


/*
int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            //Main loop flag
            bool quit = false;
            
            //Event handler
            SDL_Event e;
            
            //Angle of rotation
            double degrees = 0;
            
            
            double movex = 0;
            double movey = 0;
            
            int xChange;
            int yChange;
            
            ai badGuy(0,0);
            
            wall obstacle(100,100, 6, 75);
            
            //Flip type
           // SDL_RendererFlip flipType = SDL_FLIP_NONE;

            
            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    //User presses a key
                    else if( e.type == SDL_KEYDOWN )
                    {
                        xChange =5*cos(degrees * PI / 180.0 );
                        yChange =5*sin(degrees * PI / 180.0);
                        
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                                
                                
                            case SDLK_UP:
                                
                                
                                if (!obstacle.collision(gButtons[ 0 ].getx() +xChange, gButtons[ 0 ].gety() +yChange ))
                                gButtons[ 0 ].changePosition(xChange,yChange);
                                
                                break;
                                
                            case SDLK_DOWN:
                                
                                
                                
                                 gButtons[ 0 ].changePosition(-xChange,-yChange);
                                break;
                                
                            case SDLK_RIGHT:
                                //gButtons[ 0 ].changePosition(5,0);
                                degrees+=5;
                                break;
                                
                            case SDLK_LEFT:
                               // gButtons[ 0 ].changePosition(-5,0);
                                degrees-=5;
                                break;
                        }
                    }
                    
                    //Handle button events
                    for( int i = 0; i < TOTAL_BUTTONS; ++i )
                    {
                        gButtons[ i ].handleEvent( &e );
                    }
                }
                
               
                
                //Clear screen
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                SDL_RenderClear( gRenderer );
                
                badGuy.move(gButtons[0].getx(),gButtons[0].gety());
                
                //Render buttons
                for( int i = 0; i < TOTAL_BUTTONS; ++i )
                {
                    gButtons[ i ].render(degrees);
                }
                
                SDL_SetRenderDrawColor( gRenderer, 0, 0xFF, 0xFF, 0xFF );
                SDL_Rect fillRect = {badGuy.getxcenter(), badGuy.getycenter(), 50, 50};
                SDL_RenderFillRect(gRenderer, &fillRect);
                
                obstacle.render(gRenderer);
                
                //Update screen
                SDL_RenderPresent( gRenderer );
            }
        }
    }
    
    //Free resources and close SDL
    close();
    
    return 0;
}
*/