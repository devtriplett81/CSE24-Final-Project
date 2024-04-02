#ifndef COLOR_PICKER_H
#define COLOR_PICKER_H

#include "Rectangle.h"
#include "Color.h"

struct ColorPicker {
private: 
    
    Rectangle area; 
    Rectangle increaseRed;
    Rectangle decreaseRed;
    Rectangle increaseGreen;
    Rectangle decreaseGreen;
    Rectangle increaseBlue;
    Rectangle decreaseBlue;

    Color currentColor;

public:
    void adjustColor(float& value, float amount) {
        value += amount;
        if(value < 0.0f) value = 0.0f;
        if(value > 1.0f) value = 1.0f;
    }
    ColorPicker() {
        area = Rectangle(-0.8f, -0.8f, 1.8f, 0.6f, Color(0.8f, 0.8f ,0.8f));
        increaseRed = Rectangle(-0.75f, -0.8f, 0.1f, 0.1f, Color(1.0f, 0.0f, 0.0f));
        decreaseRed = Rectangle(-0.6f, -0.8f, 0.1f, 0.1f, Color(1.0f, 0.0f, 0.0f));
        increaseGreen = Rectangle(-0.45f, -0.8f, 0.1f, 0.1f, Color(0.0f, 1.0f, 0.0f));
        decreaseGreen = Rectangle(-0.3f, -0.8f, 0.1f, 0.1f, Color(0.0f, 1.0f, 0.0f));
        increaseBlue = Rectangle(-0.15f, -0.8f, 0.1f, 0.1f, Color(0.0f, 0.0f, 1.0f));
        decreaseBlue = Rectangle(-0.0f, -0.8f, 0.1f, 0.1f, Color(0.0f, 0.0f, 1.0f));

        currentColor = Color(0, 0, 0); // Default to black
    }
    Color getCurrentColor(){
        return currentColor;
    }

    void handleMouseClick(float x, float y) {
        float r = currentColor.getR();
        float g = currentColor.getG();
        float b = currentColor.getB();
        if (increaseRed.contains(x,y)) {
            currentColor.adjustColor(r, 0.1f);
        } else if (decreaseRed.contains(x,y)) {
            currentColor.adjustColor(r, -0.1);
        } else if (increaseGreen.contains(x,y)) {
            currentColor.adjustColor(g, 0.1);
        } else if (decreaseGreen.contains(x,y)) {
            currentColor.adjustColor(g, -0.1);
        } else if (increaseBlue.contains(x,y)) {
            currentColor.adjustColor(b, 0.1);
        } else if (decreaseBlue.contains(x,y)) {
            currentColor.adjustColor(b, -0.1);
        }
        currentColor.setColor(r,g,b);
    }

    void draw() {
        area.draw();
        increaseRed.draw();
        increaseBlue.draw();
        increaseGreen.draw();
        decreaseRed.draw();
        decreaseBlue.draw();
        decreaseGreen.draw();
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_LINES);
            glVertex2f(-0.74f, -0.85f);
            glVertex2f(-0.66f, -0.85f);

            glVertex2f(-0.59f, -0.85f);
            glVertex2f(-0.5f, -0.85f);

            glVertex2f(-0.44f, -0.85f);
            glVertex2f(-0.35f, -0.85f);

            glVertex2f(-0.29f, -0.85f);
            glVertex2f(-0.2f, -0.85f);

            glVertex2f(-0.14f, -0.85f);
            glVertex2f(-0.05f, -0.85f);

            glVertex2f(0.01f, -0.85f);
            glVertex2f(0.1f, -0.85f);
            
            glVertex2f(-0.7f, -0.89f);
            glVertex2f(-0.7f, -0.81f);

            glVertex2f(-0.4f, -0.89f);
            glVertex2f(-0.4f, -0.81f);

            glVertex2f(-0.1f, -0.89f);
            glVertex2f(-0.1f, -0.81f);




        glEnd();

        
    }
    bool contains(float x, float y) {
        return area.contains(x,y);
    }
};
#endif
