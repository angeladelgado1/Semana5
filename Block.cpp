#include "Block.h"

Block::Block(int x, int y, int width, int height, SDL_Surface *image, SDL_Surface *screen, Dot* dot)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->image = image;
    this->screen = screen;
    this->dot = dot;
}

Block::~Block()
{
    //dtor
}

void Block::show()
{
   apply_surface( x, y, image, screen );

}

bool Block::pointIsInBlock(int point_x, int point_y)
{
    if (point_x > this->x && point_x < this->x+this->width
        && point_y > this->y && point_y < this->y+this->height)
        return true;
    return false;

}

bool Block::dotCollides()
{
    if (pointIsInBlock(dot->x, dot->y))
        return true;
    if (pointIsInBlock(dot->x+dot->DOT_WIDTH, dot->y))
        return true;
    if (pointIsInBlock(dot->x,dot->y+dot->DOT_HEIGHT))
        return true;
    if (pointIsInBlock(dot->x+dot->DOT_WIDTH, dot->y+dot->DOT_HEIGHT))
        return true;

    return false;

}

void Block::logic()
{
    //if (dot->x > this->x && dot->x < this->x+this->width)
    //    dot->angle =-dot->angle;
   // else
    //    dot->angle=-dot->angle+180;
    if (this->dotCollides())
    {
        dot->angle=-dot->angle;
        //image = 0;
        //delete image;
    }

        //delete image;
            //dot->angle=-dot->angle;
    /*if (this->dotCollides())
    {
        if (colisionHorizontal())
            dot->angle =-dot->angle;
        if(clisionVertical())
            dot->angle =-dot->angle+180;
    }*/
}
