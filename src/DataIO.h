#ifndef DataIO_h
#define DataIO_h
#include "Course.h"
#include "Category.h"
#include <fstream>
#include <dirent.h>
#include <sstream>

class DataIO{
  public:
    void test(std::string);
    std::vector<Course*> readCourses();
    void writeCourses(std::vector<Course*>);
  private:
    std::vector<std::string> getFiles();
    std::vector<std::string> tokenizer(std::string);
};
#endif
