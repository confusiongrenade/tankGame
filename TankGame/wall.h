//
//  wall.hpp
//  TankGame
//
//  Created by Nicholas Carroll on 4/14/16.
//  Copyright © 2016 Nicholas Carroll. All rights reserved.
//

#ifndef wall_hpp
#define wall_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class wall {
private:
    int xcenter;
    int ycenter;
    int xlen;
    int ylength;
    SDL_Rect rect;
    
    
public:
    wall(int , int , int , int); //constructor
    void move(int , int);
    int collision(int xpos, int ypos);
    void render(SDL_Renderer* gRenderer);
    int getxcenter();
    int getycenter();
    int objectAhead();
    int tooClose(int, int);
};


#endif /* wall_hpp */
