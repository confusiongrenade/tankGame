//
//  ai.cpp
//  
//
//  Created by James Marvin on 4/10/16.
//
//

#include <stdio.h>
#include "ai.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

ai::ai(int x, int y){
    xcenter=x;
    ycenter=y;
    
    
}
int ai::tooClose(int x, int y){
    double dist;
    int xdist;
    int ydist;
    xdist=x-xcenter;
    ydist=y-ycenter;
    dist= pow(xdist, 2)+pow(ydist,2);
    double sqrdist;
    sqrdist = sqrt(dist);
    if (sqrdist<100) {
        
        return 1;
    }
    else{
        return 0;
    }
}
int ai::objectAhead(){
    if (xcenter+10>100 && xcenter+10<200 && ycenter-10>100 && ycenter-10<200) {
        return 1;
    }
    else
        return 0;
}
void ai::move(int x, int y){
    
    if (tooClose(x, y)) {
        //do nothing
    }
    else if( x>xcenter && y<ycenter)  // up and right
    {
        xcenter+=5;
        ycenter-=5;
    }
    else if( x>xcenter && y==ycenter) //right
    {
        xcenter+=5;
        ycenter+=0;
    }
    else if( x>xcenter && y>ycenter) //down and right
    { 
        xcenter+=5;
        ycenter+=5;
    }
    else if(x==xcenter && y>ycenter) //down
    {
        xcenter+=0;
        ycenter+=5;
    }
    else if(x<xcenter && y>ycenter){ //down and left
        xcenter-=5;
        ycenter+=5;
    }
    else if(x<xcenter && y==ycenter) //left
    {
        xcenter-=5;
        ycenter+=0;
    }
    else if(x<xcenter && y<ycenter) //up and left
    {
        xcenter-=5;
        ycenter-=5;
    }
    else if(x==xcenter && y<ycenter) //up
    {
        xcenter+=0;
        ycenter-=5;
    }
    
    
}
int ai::getxcenter()
{
    return xcenter;
}
int ai::getycenter()
{
    return ycenter;
}

