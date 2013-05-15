#ifndef BLOCK_H
#define BLOCK_H

#include "SDL.h"
#include "SDL_image.h"
#include "Utility.h"
#include "Dot.h"

class Block
{
    public:
        int x,y;
        int width, height;
        SDL_Surface *image;
        SDL_Surface *screen;
        Dot* dot;

        Block(int x, int y, int width, int height, SDL_Surface *image, SDL_Surface *screen, Dot* dot);
        virtual ~Block();
        void show();
        bool dotCollides();
        bool pointIsInBlock(int point_x, int point_y);
        void logic();

    protected:
    private:
};

#endif // BLOCK_H
