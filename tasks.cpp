

#include "tasks.h" // Include the header file
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <string>
#include <vector>
#include <iostream>

TaskManager::TaskManager(int x, int y, int width, int height, Fl_Window* parent) :
    scrollArea(new Fl_Scroll(x + 10, y + 50 + 20, width, height - 100)),
    Group(new Fl_Group(10, 40, width, height)),
    input(new Fl_Input(x + 10, y + height - 20 + 40, width - 100, 30)),
    addButton(new Fl_Button(x + width - 90 + 10, y + height - 50 + 30 + 40, 80, 30, "Add Task"))
    {

    parent->add(input);
    parent->add(addButton);
    parent->add(scrollArea);

    scrollArea->type(Fl_Scroll::VERTICAL);
    scrollArea->add(Group);
    Group->end();

    addButton->callback(addClicked_cb, this);
    yCoordinate = y;
    xCoordinate = x;
}

void TaskManager::addClicked() {
    const char* taskText = input->value();
    if (taskText && *taskText != '\0') {
        tasks.push_back(taskText);
        updateTaskListDisplay();
        input->value("");
    }
}

void TaskManager::addClicked_cb(Fl_Widget* widget, void* data) {
    TaskManager* tm = static_cast<TaskManager*>(data);
    tm->addClicked();
}

void TaskManager::updateTaskListDisplay() {
    Group->clear();
    int yPos = yCoordinate + 70;
    int xPos = xCoordinate;
    int taskHeight = 30;
    int separatorHeight = 2;

    for (const auto& task : tasks) {
        Fl_Box* taskBox = new Fl_Box(xPos + 30, yPos + 10, Group->w(), taskHeight, task.c_str());
        taskBox->box(FL_FLAT_BOX);
        taskBox->labelsize(18);
        taskBox->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        Group->add(taskBox);

        Fl_Box* lineSeparator = new Fl_Box(xPos, yPos, Group->w(), separatorHeight);
        //Fl_Box* lineSeparator = new Fl_Box(xPos, yPos + taskHeight + 40, Group->w(), separatorHeight);
        lineSeparator->box(FL_FLAT_BOX);
        lineSeparator->color(FL_WHITE);
        Group->add(lineSeparator);

        yPos += taskHeight + separatorHeight;
    }

    Group->resizable(Group);
    Group->resize(0, 0, Group->w(), yPos);
    Group->redraw();
    scrollArea->redraw();
}