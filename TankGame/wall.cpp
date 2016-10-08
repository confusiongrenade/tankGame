//
//  wall.cpp
//  TankGame
//
//  Created by Nicholas Carroll on 4/14/16.
//  Copyright © 2016 Nicholas Carroll. All rights reserved.
//

#include "wall.h"
#include <SDL2/SDL.h>


wall::wall(int x, int y, int xlen, int ylen){
    xcenter=x;
    ycenter=y;
    xlen = xlen;
    ylen=ylen;
    rect= {x,y,xlen,ylen};
    
}

void wall::render(SDL_Renderer* gRenderer){
    SDL_RenderFillRect(gRenderer, &rect);
}

int wall::collision(int xpos, int ypos){
    
    if ((xpos > xcenter) && ( xpos < (xcenter + xlen)))
        return 1;
    
   if ((ypos > ycenter ) && ( ypos < (ycenter + ylength)))
       return 1;
    
    
    return 0;
    
    
    
}