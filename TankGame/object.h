//
//  object.h
//  deliverable
//
//  Created by James Marvin on 4/22/16.
//  Copyright (c) 2016 James Marvin. All rights reserved.
//

#ifndef object_h
#define object_h
#include<string>
#include<iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
using namespace std;
class object {
    
    
public:
    object(int , int);
    ~object();
    virtual void draw(SDL_Renderer* )=0;
    
protected:
    int xcenter;
    int ycenter;
    
};

object::object(int x, int y){
    xcenter=x;
    ycenter=y;
}
object::~object(){
    
}
void object::draw(SDL_Renderer* ){
    cout << "This is a test" << endl;
}
#endif
