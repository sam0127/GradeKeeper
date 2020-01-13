#ifndef CourseManager_h
#define CourseManager_h
#include "Course.h"
#include <vector>
#include <iostream>

class CourseManager{
  public:
    CourseManager(std::vector<Course*> courses);
    ~CourseManager();

    void addCourse(Course* course);
    void removeCourse(Course* course);
    std::vector<Course*> getCourses();
    int size();
    void print();
  private:
    std::vector<Course*> courses;
};
#endif
