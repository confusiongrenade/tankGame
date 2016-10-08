//
// ai.h
//  tankgame
//
//  Created by James Marvin
//  Copyright © 2016 JM. All rights reserved.
//

#ifndef _ai_h
#define _ai_h
//
//  ai.cpp
//
//
//  Created by James Marvin on 4/10/16.
//
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include "object.h"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>
#include "object.h"




const int screenwidth = 640;
const int screenheight = 480;
using namespace std;
class ai: public object {
    friend class nickWall;
private:
    double angle;
    
public:
    ai(int , int ); //constructor
    void move(int , int);
    virtual void draw(SDL_Renderer*);
    int getxcenter();
    int getycenter();
    int objectAhead();
    int tooClose(int, int);
    
    void render();
    
    
    
};



ai::ai(int x, int y) : object(x, y){
    
    angle=0;
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
    
    if (sqrdist<90){
        if (xcenter < x)
            xcenter-=10;
        else if (xcenter > x)
            xcenter+=10;
        else if (ycenter > y)
            ycenter+=10;
        else if (ycenter < y)
            ycenter-=10;
        return 1;
    }
    else if (sqrdist<100) {
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
    
    
    double o = y-ycenter;
    double a = (x-xcenter);
    double theta;
    if (a > 0){
     theta = atan(o/a)*(180/PI);
    }
    else
    {
    theta = atan(o/a)*(180/PI) + 180;
    }
    

    
    if (tooClose(x, y)) {
        xcenter+=0;
        ycenter+=0;
        //do nothing
    }
    else
    {
    double dtheta = theta -angle;
    
    int xChange =5*cos(angle * PI / 180.0 );
    int yChange =5*sin(angle * PI / 180.0);
    
    if (dtheta > 10)
    {
        angle += 5;
    }
    else if (dtheta < -10)
    {
        angle -= 5;
    }
    else{
        xcenter += xChange;
        ycenter += yChange;
    }
    }
    /*
    if ((angle) > theta ){
        angle +=5;
    }
    else
    {
        angle -=5;
    }
    
    if (angle > 360)
        angle -=360;
    
    if (angle < 0)
        angle +=360;
    
     */
    /*
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
    
    if (xcenter < 0){
        xcenter = 0;
    }
    else if (xcenter + 50 > screenwidth){
        xcenter = screenwidth - 50;
    }
    if (ycenter < 0)
        ycenter = 0;
    else if (ycenter + 50 > screenheight)
        ycenter = screenheight - 50 ;
     */
    
    
}
int ai::getxcenter()
{
    return xcenter;
}
int ai::getycenter()
{
    return ycenter;
}
void ai::draw(SDL_Renderer* gRenderer){
    SDL_Rect fillRect2 = { xcenter, ycenter, 50, 50};
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );
    SDL_RenderFillRect( gRenderer, &fillRect2 );
}


void ai::render()
{
    evilTank.render( getxcenter(), getycenter(), &EvilTankRECT, angle );
}


#endif