#ifndef Category_h
#define Category_h
#include <vector>
#include <string>
#include <iostream>

class Category{
  public:
    Category(std::string name, double weight);

    double calculateAverage();
    void addGrade(double grade);
    void removeGrade(int index);
    double getWeight();
    std::string getName();
    void print();
  private:
    std::string name;
    double weight;
    std::vector<double> grades;

};
#endif
