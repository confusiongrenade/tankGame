//
//  nickWall.h
//  TankGame
//
//  Created by Nicholas Carroll on 4/25/16.
//  Copyright © 2016 Nicholas Carroll. All rights reserved.
//

#ifndef nickWall_h
#define nickWall_h


#endif /* nickWall_h */

#include "object.h"
#include "player.h"

class nickWall: public object {
    
    friend class player;
    
public:
    
    
    void draw(SDL_Renderer* gRenderer);
    void render();
    nickWall(int , int , int , int); //constructor
    
    void collision(player *a, ai *b, SDL_Event e, int oldx, int oldy);
private:
    int xlen;
    int ylen;
    
};


nickWall::nickWall(int x, int y, int xlength, int ylength) : object(x,y){
    
    xlen=xlength;
    ylen=ylength;
}




void nickWall::draw(SDL_Renderer* gRenderer){
    SDL_Rect fillRect = { static_cast<int>(xcenter), static_cast<int>(ycenter), xlen, ylen};
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 255, 0 );
    SDL_RenderFillRect( gRenderer, &fillRect );
}


void nickWall::render(){
    
    SDL_Rect fillRect3 = { xcenter, ycenter, xlen, ylen};
    SDL_SetRenderDrawColor( gRenderer, 150, 150, 150, 150);
    SDL_RenderFillRect( gRenderer, &fillRect3);
}


void nickWall::collision(player *a, ai *b, SDL_Event e, int oldx, int oldy){
    
    int left = xcenter;
    int right = xcenter + xlen;
    int top = ycenter;
    int bottom = ycenter + ylen;
    if( (a->xcenter+25>left && a->xcenter-25<right) && (a->ycenter+25>top && a->ycenter-25<bottom))
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
                a->ycenter = bottom + 25;
                break;
                
            case SDLK_DOWN:
                a->ycenter = top - 25;
                break;
                
            case SDLK_LEFT:
                a->xcenter = right + 25;
                break;
                
            case SDLK_RIGHT:
                a->xcenter = left - 25;
                break;
                
        }
        
    }
    
    if ( (b->xcenter+25>left && b->xcenter-25<right) && (b->ycenter+25>top && b->ycenter-25<bottom))
    {
        b->xcenter = oldx;
        b->ycenter = oldy;
        if ( (b->xcenter+25>xcenter && b->xcenter-25<xcenter+xlen) )
        {
            if (b->xcenter > left + xlen/2)
                b->xcenter = oldx + 3;
            else
                b->xcenter = oldx - 3;
        }
        
        if ((b->ycenter+25>ycenter && b->ycenter-25<ycenter+ylen))
        {
            if (b->ycenter > top + xlen/2)
                b->ycenter = oldy + 3;
            else
                b->ycenter = oldy - 3;
        }
        /*
         if ((b->xcenter+25 == left) && (b->ycenter+25 == top))
         {
         b->xcenter = oldx - 3;
         b->ycenter = oldy - 3;
         }
         else if ((b->xcenter+25 == left) && (b->ycenter-25 == bottom))
         {
         b->ycenter = oldy + 3;
         b->xcenter = oldx - 3;
         }
         else if ((b->xcenter-2525 == right) && (b->ycenter+25 == top))
         {
         b->xcenter = oldx + 3;
         b->ycenter = oldy - 3;
         }
         else if ((b->xcenter-25 == right) && (b->ycenter-25 == bottom))
         {
         b->ycenter = oldy + 3;
         b->xcenter = oldx + 3;
         }
         */
        
        
    }
    
    
    
}