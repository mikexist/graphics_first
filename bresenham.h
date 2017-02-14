//
// Created by mike on 2/15/17.
//

#ifndef GRAPHICS_BRESENHAM_H
#define GRAPHICS_BRESENHAM_H

#include <iostream>
#include <vector>
#include <cmath>
#include <GL/freeglut.h>


using namespace std;

class GridQuad {
public:
    GridQuad(float x, float y, float size);
    void draw(bool isFilled);

private:
    float x, y, size;
};

struct grid_quad {
    bool isFilled;
    GridQuad *gc;
};

void changeSize(int, int);
void menu(void);
void init(void);
void drawGrid(void);
void Display(void);

void line(int x0, int y0, int x1, int y1);
void circle(int x, int y, int r);
void ellipse(int x, int y, int a, int b);

void fillQuad(int x, int y);
void timer(int x);

#endif //GRAPHICS_BRESENHAM_H
