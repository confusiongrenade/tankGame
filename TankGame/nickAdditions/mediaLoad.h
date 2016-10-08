//
//  mediaLoad.h
//  TankGame
//
//  Created by Nicholas Carroll on 4/23/16.
//  Copyright © 2016 Nicholas Carroll. All rights reserved.
//

#ifndef mediaLoad_h
#define mediaLoad_h


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/*
//Button constants
const int BUTTON_WIDTH = 150;
const int BUTTON_HEIGHT = 100;
const int TOTAL_BUTTONS = 1;
*/


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//Buttons objects
LButton gButtons[ TOTAL_BUTTONS ];

LTexture tank;

bool init()
{
    //Initialization flag
    bool success = true;
    
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                
                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    
    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;
    
    SDL_Surface* optimizedSurface = NULL;

    //Load sprites
    if(  !tank.loadFromFile( "resizeTank.png"  ))
    {
        printf( "Failed to load button sprite texture!\n" );
        success = false;
    }
    else
    {
        //Set sprites
        for( int i = 0; i < BUTTON_SPRITE_TOTAL; ++i )
        {
            gSpriteClips[ i ].x = 0;
            gSpriteClips[ i ].y = i * 200;
            gSpriteClips[ i ].w = BUTTON_WIDTH;
            gSpriteClips[ i ].h = BUTTON_HEIGHT;
            
            
            
            
        }
       

        
       // tank.setPosition(0,0);
        
        //Set buttons in corners
     
        // gButtons[ 1 ].setPosition( SCREEN_WIDTH - BUTTON_WIDTH, 0 );
        // gButtons[ 2 ].setPosition( 0, SCREEN_HEIGHT - BUTTON_HEIGHT );
        //gButtons[ 3 ].setPosition( SCREEN_WIDTH - BUTTON_WIDTH, SCREEN_HEIGHT - BUTTON_HEIGHT );
    }
    
    return success;
}

void close()
{
    //Free loaded images
    gButtonSpriteSheetTexture.free();
    
    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    
    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}


#endif /* mediaLoad_h */
