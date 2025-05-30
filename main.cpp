#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Input.H>
#include <chrono>
#include <iostream>
#include "rectangle.h"
#include "tasks.h" // Include the TaskManager header

void createButton(int xCord, int yCord, int width, int height, const char* string){
    Fl_Button *Button = new Fl_Button(xCord, yCord, width, height, string);
}

int main(int argc, char **argv) {
  auto now = std::chrono::system_clock::now();
  std::time_t now_c = std::chrono::system_clock::to_time_t(now);
  std::tm now_tm;
  localtime_r(&now_c, &now_tm);

  char date_str[100];
  std::strftime(date_str, sizeof(date_str), "%Y-%m-%d", &now_tm);
  std::cout << "Current time is: " << date_str << std::endl;

  Fl_Window *window = new Fl_Window(800, 800, "FLTK Test");
  window->color(FL_WHITE);

  Rectangle *rectangle = new Rectangle(15, 20, 100, 30, "Your Day!");
  Rectangle *dateRectangle = new Rectangle(19, 50, 100, 30, date_str);
  TaskManager *Tasks = new TaskManager(15, 15, 700, 700, window);
  window->add(rectangle);
  window->end();
  window->show(argc, argv);

  return Fl::run();
}