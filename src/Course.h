#ifndef Course_h
#define Course_h
#include <vector>
#include <string>
#include <iostream>
#include "Category.h"

class Course
{
  public:
    Course(std::string name, std::vector<Category*> categories);
    ~Course();

    double calculateWeightedAverage();
    void addCategory(Category* category);
    void addCategory(std::string name, double weight);
    void removeCategory(Category* category);
    void removeCategory(std::string name);
    std::string getName();
    std::vector<Category*> getCategories();
    void print();
  private:
    std::string name;
    std::vector<Category*> categories;

};
#endif
