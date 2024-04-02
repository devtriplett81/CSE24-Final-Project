#ifndef CANVAS_H
#define CANVAS_H

#include "Rectangle.h"
#include "Scribble.h"
#include "Toolbar.h"
#include "Circle.h"

struct Canvas{
private:
    Rectangle area;
    
    float offsetX;
    float offsetY;
    Scribble scribbles[100];
    int scribbleCounter;
    int selectedScribble;
    Shape* shapes[1000];
    int shapeCounter;
    int selectedShape;
    Rectangle squares[1000];
    int sCounter;
    int selectedSquare;
    Circle circles[1000];
    int cCounter;
    int selectedCircle;

public:
    Canvas() {
        area = Rectangle(-0.8, 1, 1.8, 1.8, Color(1, 1, 1));
        scribbleCounter = 0;
        selectedScribble = -1;
        shapeCounter = 0;
        selectedShape = -1;
        sCounter = 0;
        selectedSquare = -1;
        cCounter = 0;
        selectedCircle = -1;

        offsetX = 0;
        offsetY = 0;
    }

    void draw() {
        area.draw();

        for (int i = 0; i < scribbleCounter; i++) {
            scribbles[i].draw();
        }

        for (int i = 0; i < shapeCounter; i++) {
            shapes[i]->draw();
        }

        for (int i = 0; i < sCounter; i++) {
            squares[i].draw();
        }

        for (int i = 0; i < cCounter; i++) {
            circles[i].draw();
        }
    }

    void handleMouseClick(float x, float y, Tool selectedTool, Color color) {
        if (selectedTool == PENCIL) {
            // shapes[shapeCounter] = new Scribble();
            // shapeCounter++;
            // ((Scribble*)shapes[shapeCounter-1])->addPoint(x, y, color);
            Scribble* newScribble = new Scribble();
            newScribble->addPoint(x, y, color);
            shapes[shapeCounter++] = newScribble;
        }
        else if (selectedTool == ERASER) {
            shapes[shapeCounter] = new Scribble();
            shapeCounter++;
            ((Scribble*)shapes[shapeCounter-1])->addPoint(x, y, Color(1, 1, 1));
        }
        else if (selectedTool == SQUARE) {
            shapes[shapeCounter] = new Rectangle(x, y, 0.3, 0.3, color);
            shapeCounter++;
        }
        else if (selectedTool == CIRCLE) {
            shapes[shapeCounter] = new Circle(x, y, 0.2f, color);
            shapeCounter++;
        }
        else if (selectedTool == TRASH) {
            clearScreen();
        }
        else if (selectedTool == MOUSE) {
            bool shapeSelect = false;

            if (selectedShape != -1) {
                shapes[selectedShape]->deselect();
                selectedShape = -1;
            }

            for (int i = shapeCounter - 1; i >= 0 && !shapeSelect; i--) {
                if (shapes[i]->contains(x, y)) {
                    shapes[i]->select();
                    selectedShape = i;
                    shapeSelect = true;

                    offsetX = x - shapes[i]->getX();
                    offsetY = y - shapes[i]->getY();
                    break;
                }
            }
        }
    }

    void handleMouseDrag(float x, float y, Tool selectedTool, Color color) {
        if (selectedTool == PENCIL && shapeCounter > 0) {
            Scribble* currentScribble = dynamic_cast<Scribble*>(shapes[shapeCounter - 1]);
            if (currentScribble) {
                currentScribble->addPoint(x, y, color);
            }
        }
        else if (selectedTool == MOUSE && selectedShape != -1) {
            shapes[selectedShape]->setX(x - offsetX);
            shapes[selectedShape]->setY(y - offsetY);
        }
    }

    void clearScreen() {
        scribbleCounter = 0;
        sCounter = 0;
        cCounter = 0;
        shapeCounter = 0;

        for (int i = 0; i < shapeCounter; i++) {
            delete shapes[i];
            shapes[i] = nullptr;
        }

        selectedSquare = -1;
        selectedScribble = -1;
        selectedShape = -1;
        selectedCircle = -1;
        offsetX = 0;
        offsetY = 0;
    }

    bool contains(float x, float y) {
        return area.contains(x, y);
    }

};

#endif
