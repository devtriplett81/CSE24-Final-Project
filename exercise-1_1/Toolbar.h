#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Rectangle.h"
#include "Texture.h"

enum Tool {PENCIL, ERASER, SQUARE, MOUSE, CIRCLE, TRASH, TRIANGLE};

struct Toolbar {
private:
    Rectangle area;
    Texture pencilButton;
    Texture eraserButton;
    Texture mouseButton;
    Texture squareButton;
    Texture trashButton;
    Texture circleButton;
    Tool selectedTool;

    void deselectAll(){
        pencilButton.deselect();
        eraserButton.deselect();
        mouseButton.deselect();
        squareButton.deselect();
        trashButton.deselect();
        circleButton.deselect();
    }

public:
    Toolbar(){
        area = Rectangle(-1.0f, 1.0f, 0.2f, 2.0f, Color(0.8f, 0.8f, 0.8f));
        pencilButton = Texture("assets/pencil.png", -1.0f, 1.0f, 0.2f, 0.2f);
        eraserButton = Texture("assets/eraser.png", -1.0f, 0.8f, 0.2f, 0.2f);
        mouseButton = Texture("assets/mouse.png", -1.0f, 0.6f, 0.2f, 0.2f);
        squareButton = Texture("assets/square.png", -1.0f, 0.4f, 0.2f, 0.2f);
        trashButton = Texture("assets/trash.png", -1.0f, 0.2f, 0.2f, 0.2f);
        circleButton = Texture("assets/circle.png", -1.0f, 0.0f, 0.2f, 0.2f);

        selectPencil();
    }

    Tool getSelectedTool(){
        return selectedTool;
    }

    void selectPencil() {
        deselectAll();
        pencilButton.select();
        selectedTool = PENCIL;
    }

    void selectEraser() {
        deselectAll();
        eraserButton.select();
        selectedTool = ERASER;
    }

    void selectMouse() {
        deselectAll();
        mouseButton.select();
        selectedTool = MOUSE;
    }

    void selectSquare() {
        deselectAll();
        squareButton.select();
        selectedTool = SQUARE;
    }

    void selectTrash() {
        deselectAll();
        trashButton.select();
        selectedTool = TRASH;
    }

    void selectCircle() {
        deselectAll();
        circleButton.select();
        selectedTool = CIRCLE;
    }

    void handleMouseClick(float x, float y){
        if (pencilButton.contains(x, y)){
            selectPencil();
        } else if (eraserButton.contains(x, y)){
            selectEraser();
        } else if (mouseButton.contains(x, y)) {
            selectMouse();
        } else if (squareButton.contains(x, y)) {
            selectSquare();
        } else if (trashButton.contains(x, y)) {
            selectTrash();
        } else if (circleButton.contains(x, y)) {
            selectCircle();
        }
    }

    void draw(){
        area.draw();
        pencilButton.draw();
        eraserButton.draw();
        mouseButton.draw();
        squareButton.draw();
        trashButton.draw();
        circleButton.draw();
    }

    bool contains(float x, float y){
        return area.contains(x, y);
    }
};

#endif
