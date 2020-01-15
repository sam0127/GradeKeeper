#include "Category.h"
using namespace std;

Category::Category(string name, double weight) : name(name), weight(weight)
{}

double Category::calculateAverage(){
  double sum;
  for(int i = 0; i < grades.size(); i++){
    sum += grades.at(i);
  }
  return sum / grades.size();
}

void Category::addGrade(double grade){
  grades.push_back(grade);
}

void Category::removeGrade(int index){
  grades.erase(grades.begin()+index);
}

double Category::getWeight(){
  return weight;
}

string Category::getName(){
  return name;
}

vector<double> Category::getGrades(){
  return grades;
}

void Category::print(){
  cout << "--------------------" << endl;
  cout << name << " - " << weight * 100 << "%" << endl;
  for(int i = 0; i < grades.size(); i++){
    cout << i << ". " << grades.at(i) << endl;
  }
  cout << "Average: " << calculateAverage() << endl;
}
