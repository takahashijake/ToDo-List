#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <string>
#include <vector>

class TaskManager{

private:
    Fl_Input* input;
    Fl_Button* addButton;
    Fl_Scroll* scrollArea;
    Fl_Group* Group;
    std::vector<std::string> tasks; // Add the tasks vector
    int yCoordinate;
    int xCoordinate;

    static void addClicked_cb(Fl_Widget* widget, void* data);
    void updateTaskListDisplay(); // Declare the update function

public:
    TaskManager(int x, int y, int width, int height, Fl_Window* parent);
    void addClicked(); // Make addClicked a non-static instance method
};
#endif