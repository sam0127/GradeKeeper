#ifndef DataIO_h
#define DataIO_h
#include "Course.h"
#include "Category.h"
#include <fstream>

class DataIO{
  public:
    std::vector<Course*> readCourses();
    void writeCourses(std::vector<Course*>);
};
#endif
