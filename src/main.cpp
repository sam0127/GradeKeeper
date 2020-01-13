#include "DataIO.h"
#include "CourseManager.h"
#include "Course.h"
#include "Category.h"
#include <iostream>
#include <vector>

using namespace std;
int main(){
  cout << "Loading courses..." << endl;
  //DataIO IOobject;
  //CourseManager cm(IOobject.readCourses());

  //cout << cm.size() << " courses loaded." << endl;


  //TESTING

  Category * tests313 = new Category("Tests", .5);
  tests313->addGrade(90);
  tests313->addGrade(84);
  Category * hw313 = new Category("Homework", .2);
  hw313->addGrade(30);
  hw313->addGrade(50);
  hw313->addGrade(60);
  hw313->addGrade(80);
  Category * project313 = new Category("Projects", .3);
  project313->addGrade(85);
  project313->addGrade(90);
  project313->addGrade(26);
  project313->addGrade(54);
  project313->addGrade(32);

  vector<Category*> c313;
  c313.push_back(tests313);
  c313.push_back(hw313);
  c313.push_back(project313);
  Course * cs313 = new Course("CSCE 313", c313);

  Category * tests315 = new Category("Tests", .4);
  tests315->addGrade(100);
  tests315->addGrade(45);
  tests315->addGrade(88);
  Category * project315 = new Category("Projects", .4);
  project315->addGrade(92);
  project315->addGrade(83);
  project315->addGrade(78);
  Category * quiz315 = new Category("Quizzes", .2);
  quiz315->addGrade(68);
  quiz315->addGrade(69);
  quiz315->addGrade(75);
  quiz315->addGrade(88);

  vector<Category*> c315;
  c315.push_back(tests315);
  c315.push_back(project315);
  c315.push_back(quiz315);
  Course * cs315 = new Course("CSCE 315", c315);

  vector<Course*> courses;
  courses.push_back(cs313);
  courses.push_back(cs315);

  CourseManager cm(courses);

  cout << ">>>>>>>>>>COURSES<<<<<<<<<<" << endl;
  cm.print();
  cout << ">>>class breakdown<<<" << endl;
  vector<Course*> a = cm.getCourses();
  for(int i = 0; i < a.size(); i++){
    a.at(i)->print();
  }



}
