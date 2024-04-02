#ifndef CIRCLE_H
#define CIRCLE_H

#include <cmath>
#include <GL/freeglut.h>
#include "Color.h"
#include "Shape.h"

class Circle : public Shape {
    float r;
    Color color;

public:
    Circle() {
        x = 0.0f;
        y = 0.0f;
        r = 0.2f;
        selected = false;
    }

    Circle(float x, float y, float r, Color color) {
        this->x = x;
        this->y = y;
        this->r = r;
        this->color = color;
        selected = false;
    }

    void draw() {
        glColor3f(color.getR(), color.getG(), color.getB());
        glBegin(GL_POLYGON);
        for (float angle = 0.0f; angle < 2 * M_PI; angle += 0.01f) {
            glVertex2f(x + sin(angle) * (r + 0.02f), y + cos(angle) * (r + 0.02f));
        }
        glEnd();

        if (selected) {
            Circle outer(x, y, r - 0.02f, Color(1.0f, 1.0f, 1.0f));
            Circle inner(x, y, r - 0.04f, color);
            outer.draw();
            inner.draw();
        }
    }

    bool contains(float mx, float my) {
        if (r >= sqrt((pow((mx - x), 2) + pow((my - y), 2)))) {
            return true;
        } else {
            return false;
        }
    }

    void setColor(Color color) {
        this->color = color;
    }

    void setR(float r) {
        this->r = r;
    }

    float getR() {
        return r;
    }
};

#endif
