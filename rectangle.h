#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <FL/Fl.H>
#include <FL/Fl_Widget.H> 
#include <FL/fl_draw.H>

class Rectangle : public Fl_Widget { 
public:
    Rectangle(int x, int y, int width, int height, const char *label)
        : Fl_Widget(x, y, width, height, label) {}

    void draw() override;

private:
    void drawRectangle();
};

void Rectangle::draw() {
  fl_color(FL_WHITE);
  fl_rectf(x(), y(), w(), h());

  fl_color(FL_BLACK); 
  fl_font(FL_HELVETICA, 20);
  fl_draw(label(), x(), y(), w(), h(), FL_ALIGN_CENTER);
}

#endif