#include "DataIO.h"
#include "CourseManager.h"
#include "Course.h"
#include "Category.h"
#include <iostream>
#include <vector>

using namespace std;
void helpDisplay()
{
  cout << "Commands:" << endl;
  cout << "w - save changes" << endl;
  cout << "r - recover changes" << endl;
  cout << "co - display courses" << endl;
  cout << "bd - display breakdown of course, this sets course focus" << endl;
  cout << "aco - add course, this sets course focus" << endl;
  cout << "rco - remove course" << endl;
  cout << "aca - add category to course" << endl;
  cout << "rca - remove category from course" << endl;
  cout << "ag - add grade to category of course" << endl;
  cout << "rg - remove grade from category in course" << endl;
  cout << "q - quit without saving" << endl;
  cout << "help - display this message" << endl;
}

int main()
{
  cout << "Loading courses..." << endl;
  //DataIO IOobject;
  //CourseManager cm(IOobject.readCourses());

  //cout << cm.size() << " courses loaded." << endl;


  //TESTING
  /*
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
  */
  /*
  cout << ">>>>>>>>>>COURSES<<<<<<<<<<" << endl;
  cm.print();
  cout << ">>>class breakdown<<<" << endl;
  vector<Course*> a = cm.getCourses();
  for(int i = 0; i < a.size(); i++){
    a.at(i)->print();
  }*/

  CourseManager cm;
  helpDisplay();

  //runtime loop
  Course* courseFocus = nullptr;
  while(true)
  {
    string command;
    cout << "> ";
    cin >> command;
    cout << command << endl;

    if(command == "w"){
      //write
      cout << "write" << endl;
    }
    else if(command == "r"){
      //update data to file
      cout << "recover" << endl;
    }
    else if(command == "co"){
      cout << "disp courses" << endl;
      cm.print();
    }
    else if(command == "bd"){
      cout << "disp course breakdown" << endl;
      cout << "Display which course? ";
      string name;
      cin >> name;

      Course* course = cm.findCourse(name);
      if(course){
        courseFocus = course;
        course->print();
        cout << courseFocus->getName() << endl;
      }else{
        cout << "Course " << name << " not found." << endl;
      }
    }
    else if(command == "aco"){
      cout << "add course" << endl;
      cout << "Enter course name: ";
      string name;
      cin >> name;

      Course* course = cm.findCourse(name);
      if(course){
        cout << "Course " << name << " already exists." << endl;
      }else{
        Course* newCourse = new Course(name);
        courseFocus = newCourse;
        cm.addCourse(newCourse);
      }
    }
    else if(command == "rco"){
      cout << "remove course" << endl;
      cout << "Remove which course? ";
      string name;
      cin >> name;

      Course* course = cm.findCourse(name);
      if(course){
        cm.removeCourse(course);
      }else{
        cout << "Course " << name << " not found" << endl;
      }
    }
    else if(command == "aca"){
      cout << "add category" << endl;
      if(!courseFocus){
        cout << "What course does the category belong to? ";
        string name;
        cin >> name;

        Course* course = cm.findCourse(name);
        if(course){
          courseFocus = course;
        }else{
          cout << "Course " << name << " not found" << endl;
          continue;
        }
      }
      cout << "Enter category name: ";
      string name;
      cin >> name;
      Category* cat = courseFocus->findCategory(name);
      if(cat){
        cout << "Category " << name << " already exists." << endl;
      }else{
        cout << "Enter category weight (decimal): ";
        string weight_string;
        cin >> weight_string;
        double weight = atof(weight_string.c_str());
        Category* newCat = new Category(name, weight);
        courseFocus->addCategory(newCat);
      }
    }
    else if(command == "rca"){
      cout << "remove category" << endl;
      if(!courseFocus){
        cout << "What course does the category belong to? ";
        string name;
        cin >> name;

        Course* course = cm.findCourse(name);
        if(course){
          courseFocus = course;
        }else{
          cout << "Course " << name << " not found" << endl;
          continue;
        }
      }
      cout << "Enter category name: ";
      string name;
      cin >> name;
      Category* cat = courseFocus->findCategory(name);
      if(cat){
        courseFocus->removeCategory(cat);
        cout << "Category " << name << " removed." << endl;
      }else{
        cout << "Category " << name << " not found." << endl;
      }
    }
    else if(command == "ag"){
      cout << "add grade" << endl;
      if(!courseFocus){
        cout << "What course does the grade belong to? ";
        string name;
        cin >> name;

        Course* course = cm.findCourse(name);
        if(course){
          courseFocus = course;
        }else{
          cout << "Course " << name << " not found" << endl;
          continue;
        }
      }
      cout << "What category does the grade belong to? ";
      string name;
      cin >> name;
      Category* cat = courseFocus->findCategory(name);
      if(cat){
        cout << "Enter grade: ";
        string grade_string;
        cin >> grade_string;
        int grade = atoi(grade_string.c_str());
        cat->addGrade(grade);
      }else{
        cout << "Category " << name << " not found." << endl;
      }
    }
    else if(command == "rg"){
      cout << "remove grade" << endl;
      if(!courseFocus){
        cout << "What course does the grade belong to? ";
        string name;
        cin >> name;

        Course* course = cm.findCourse(name);
        if(course){
          courseFocus = course;
        }else{
          cout << "Course " << name << " not found" << endl;
          continue;
        }
      }
      cout << "What category does the grade belong to? ";
      string name;
      cin >> name;
      Category* cat = courseFocus->findCategory(name);
      if(cat){
        cout << "Enter grade index: ";
        string index_string;
        cin >> index_string;
        int index = atoi(index_string.c_str());
        cat->removeGrade(index);
      }else{
        cout << "Category " << name << " not found." << endl;
      }
    }
    else if(command == "q"){
      cout << "quit" << endl;
      break;
    }
    else if(command == "help"){
      cout << "help" << endl;
      helpDisplay();
    }
    else{
      cout << "Unknown command, use help for a list of commands" << endl;
    }
  }

}


