//
// Created by mike on 2/15/17.
//

#include "bresenham.h"

#define SIZE 2

vector <vector <grid_quad>> grid_matrix;

int x_0, y_0;
int x_1, y_1;
int r1, r2;

void changeSize(int w, int h)
{
    if (h == 0) h = 1;
    double ratio = 1.0 * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    if (w <= h)
        glOrtho(-100, 100, -100.0 / ratio, 100.0 / ratio, -100, 100);
    else
        glOrtho(-100.0*ratio, 100.0*ratio, -100.0, 100.0, -100, 100);
    glMatrixMode(GL_MODELVIEW);
}
void menu(void) {
    cout << "Enter first coords: ";
    cin >> x_0;
    cin >> y_0;
    cout << "Enter second coords: ";
    cin >> x_1;
    cin >> y_1;

}
void init(void) {
    for (int j = -100 + SIZE/2; j < 100 - SIZE/2; j += SIZE) {
        vector <grid_quad> temp;
        for (int i = -100 + SIZE/2; i < 100 - SIZE/2; i += SIZE) {
            grid_quad gq;
            gq.gc = new GridQuad((float)j, (float)i, (float)SIZE);
            gq.isFilled = true;
            temp.push_back(gq);
        }
        grid_matrix.push_back(temp);
    }
}
void drawGrid(void) {
    glBegin(GL_LINES);
    {
        for (int i = -100; i <= 100; i += SIZE) {
            glVertex2f(i, 100);
            glVertex2f(i, -100);

            glVertex2f(100, i);
            glVertex2f(-100, i);
        }
    }
    glEnd();
}

void line(int x0, int y0, int x1, int y1, const GLubyte *begin_color, const GLubyte *end_color) {
    GLubyte cur_color[3] = {begin_color[0], begin_color[1], begin_color[2]};

    bool steep = false;
    if (std::abs(x0 - x1)<std::abs(y0 - y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if (x0>x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    int dx = x1 - x0;
    int dy = y1 - y0;
    float derror = std::abs(dy)*2;
    float error = 0;
    int y = y0;

    float t_step = 1 / (float)dx;
    float t = 0;

    for (int x = x0; x <= x1; x++) {
        cur_color[0] = (GLubyte)(begin_color[0] * (1 - t) + end_color[0] * t);
        cur_color[1] = (GLubyte)(begin_color[1] * (1 - t) + end_color[1] * t);
        cur_color[2] = (GLubyte)(begin_color[2] * (1 - t) + end_color[2] * t);

        if (steep) {
            fillQuad(y, x, cur_color);
        }
        else {
            fillQuad(x, y, cur_color);
        }
        error += derror;

        if (error>dx) {
            y += (y1>y0 ? 1 : -1);
            error -= dx *2;
        }

        t+=t_step;
    }
}


void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    const GLubyte begin_color[] = {0, 255, 0};
    const GLubyte end_color[] = {255, 0, 0};
    //glColor3f(1, 0, 0);

    line(x_0, y_0, x_1, y_1, begin_color, end_color);


    glColor3ub(47, 79, 79);
    drawGrid();
    glutSwapBuffers();
}

GridQuad::GridQuad(float x, float y, float size) {
    this->size = size;
    this->x = x;
    this->y = y;
}
void GridQuad::draw(bool isFilled, const GLubyte *color) {
    int type;
    if (isFilled)
        type = GL_POLYGON;
    else
        type = GL_LINE_STRIP;

    glColor3ubv(color);
    glBegin(type);
    {
        glVertex2f(x - size / 2, y - size / 2);
        glVertex2f(x + size / 2, y - size / 2);
        glVertex2f(x + size / 2, y + size / 2);
        glVertex2f(x - size / 2, y + size / 2);
        glVertex2f(x - size / 2, y - size / 2);
    }
    glEnd();
}

void fillQuad(int x, int y, const GLubyte *color) {
    grid_matrix[grid_matrix.size() / 2 + x][grid_matrix.size() / 2 + y].gc->draw(true, color);
}
void timer(int x) {
    Display();
    glutTimerFunc(10, timer, x);
}


