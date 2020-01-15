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
  cout << "fco - set course focus" << endl;
  cout << "fca - set category focus" << endl;
  cout << "cd - display courses" << endl;
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
  DataIO IOobject;
  CourseManager cm(IOobject.readCourses());
  //IOobject.test("yeeee");
  //cout << cm.size() << " courses loaded." << endl;

  //CourseManager cm;
  helpDisplay();

  //runtime loop
  Course* courseFocus = nullptr;
  Category* catFocus = nullptr;
  while(true)
  {
    string command;
    cout << "> ";
    cin >> command;

    if(command == "w"){
      //write
      IOobject.writeCourses(cm.getCourses());
    }
    else if(command == "r"){
      //update data to file
      //cm = CourseManager(IOobject.readCourses());
    }
    else if(command == "fco"){
      cout << "Focus on which course? ";
      string name;
      cin >> name;
      Course* course = cm.findCourse(name);
      if(course){
        courseFocus = course;
        cout << "Course focus set to " << name << "." << endl;
      }else{
        cout << "Course " << name << " not found." << endl;
      }
    }
    else if(command == "fca"){
      if(!courseFocus){
        cout << "In which course? ";
        string name;
        cin >> name;
        Course* course = cm.findCourse(name);
        if(course){
          courseFocus = course;
          cout << "Course focus set to " << name << "." << endl;
        }else{
          cout << "Course " << name << " not found." << endl;
          continue;
        }
      }
      cout  << "Focus on which category in " << courseFocus->getName() << "? ";
      string name;
      cin >> name;
      Category* cat = courseFocus->findCategory(name);
      if(cat){
        catFocus = cat;
        cout << "Category focus set to " << name << "." << endl;
      }else{
        cout << "Category " << name << " not found in " << courseFocus->getName() << "." << endl;
      }
    }
    else if(command == "cd"){
      cm.print();
    }
    else if(command == "bd"){
      if(courseFocus){
        courseFocus->print();
      }else{
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
    }
    else if(command == "aco"){
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
        cout << "Course " << name << " added." << endl;
      }
    }
    else if(command == "rco"){
      cout << "Remove which course? ";
      string name;
      cin >> name;

      Course* course = cm.findCourse(name);
      if(course){
        cm.removeCourse(course);
        cout << "Course " << name << " removed." << endl;
      }else{
        cout << "Course " << name << " not found" << endl;
      }
    }
    else if(command == "aca"){
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
        cout << "Category " << name << " added to " << courseFocus->getName() << "." << endl;
      }
    }
    else if(command == "rca"){
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
        cout << "Category " << name << " removed from " << courseFocus->getName()<< "." << endl;
      }else{
        cout << "Category " << name << " not found." << endl;
      }
    }
    else if(command == "ag"){
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
      if(!catFocus){
        cout << "What category does the grade belong to? ";
        string name;
        cin >> name;
        Category* cat = courseFocus->findCategory(name);
        if(cat){
          catFocus = cat;
        }else{
          cout << "Category " << name << " not found." << endl;
          continue;
        }
      }

      cout << "Enter grade: ";
      string grade_string;
      cin >> grade_string;
      int grade = atof(grade_string.c_str());
      catFocus->addGrade(grade);
      cout << grade << " added to " << catFocus->getName() << "." << endl;
    }
    else if(command == "rg"){
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
      if(!catFocus){
        cout << "What category does the grade belong to? ";
        string name;
        cin >> name;
        Category* cat = courseFocus->findCategory(name);
        if(cat){
          catFocus = cat;
        }else{
          cout << "Category " << name << " not found." << endl;
          continue;
        }
      }

      cout << "Enter grade index: ";
      string index_string;
      cin >> index_string;
      int index = atoi(index_string.c_str());
      catFocus->removeGrade(index);
      cout << "Removed grade at " << index << " from " << catFocus->getName() << "." << endl;
    }
    else if(command == "q"){
      break;
    }
    else if(command == "help"){
      helpDisplay();
    }
    else{
      cout << "Unknown command, use help for a list of commands" << endl;
    }
  }

}


