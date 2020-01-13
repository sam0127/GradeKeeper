#include "CourseManager.h"

using namespace std;

CourseManager::CourseManager(vector<Course*> courses) : courses(courses)
{}

CourseManager::~CourseManager(){
  for(int i = courses.size()-1; i >= 0; i--){
    delete courses.at(i);
  }
}

void CourseManager::addCourse(Course* course){
  courses.push_back(course);
}

void CourseManager::removeCourse(Course* course){
  bool removed = false;
  for(int i = 0; i < courses.size(); i++){
    if(course->getName() == courses.at(i)->getName()){
      courses.erase(courses.begin()+i);
      cout << "Course " << course->getName() << " removed." << endl;
      removed = true;
    }
  }
  if(!removed){
    cout << "Course " << course->getName() << " not found." << endl;
  }
}

vector<Course*> CourseManager::getCourses(){
  return courses;
}
int CourseManager::size(){
  return courses.size();
}

void CourseManager::print(){
  for(int i = 0; i < courses.size(); i++){
    cout << "====================" << endl;
    cout << courses.at(i)->getName() << endl;
    cout << "Course average: " << courses.at(i)->calculateWeightedAverage() << endl;
    cout << "====================" << endl;
  }
}
