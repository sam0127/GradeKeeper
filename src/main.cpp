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
  cout << "fco [co] - focus course co" << endl;
  cout << "fca [co] [ca] - focus on category ca in course co" << endl;
  cout << "uco - unfocus course" << endl;
  cout << "uca - unfocus category" <<endl;
  cout << "vf - view course and category foci" << endl;
  cout << "ls - display courses" << endl;
  cout << "bd [co] - display breakdown of course co" << endl;
  cout << "aco [co] - add course co" << endl;
  cout << "rco [co] - remove course co" << endl;
  cout << "aca [co] [ca] [w] - add category ca with weight w to course co" << endl;
  cout << "rca [ca] - remove category from course" << endl;
  cout << "ag [co] [ca] [g] - add grade g to category ca of course co" << endl;
  cout << "rg [co] [ca] [i] - remove grade i from category ca in course co" << endl;
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
    if(courseFocus){
      cout << courseFocus->getName();
    }
    if(catFocus){
      cout << "/" << catFocus->getName();
    }
    string command;
    cout << "> ";
    cin >> command;

    if(command == "w"){
      //write
      cout << "Writing data...";
      IOobject.writeCourses(cm.getCourses());
      cout << "Data saved." << endl;
    }
    else if(command == "r"){
      //update data to file
      //cm = CourseManager(IOobject.readCourses());
    }
    else if(command == "fco"){
      //cout << "Focus on which course? ";
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
        //cout << "In which course? ";
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
      //cout  << "Focus on which category in " << courseFocus->getName() << "? ";
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
    else if(command == "uco"){
      courseFocus = nullptr;
      cout << "Course unfocused." << endl;
      catFocus = nullptr;
      cout << "Category unfocused." << endl;
    }
    else if(command == "uca"){
      catFocus = nullptr;
      cout << "Category unfocused" << endl;
    }
    else if(command == "vf"){
      cout << "Course focus: ";
      if(courseFocus){
        cout << courseFocus->getName() << endl;
      }else{
        cout << "none" << endl;
      }
      cout << "Category focus: ";
      if(catFocus){
        cout << catFocus->getName() << endl;
      }else{
        cout << "none" << endl;
      }
    }
    else if(command == "cd"){
      cm.print();
    }
    else if(command == "bd"){
      if(courseFocus){
        courseFocus->print();
      }else{
        //cout << "Display which course? ";
        string name;
        cin >> name;

        Course* course = cm.findCourse(name);
        if(course){
          course->print();
        }else{
          cout << "Course " << name << " not found." << endl;
        }
      }
    }
    else if(command == "aco"){
      //cout << "Enter course name: ";
      string name;
      cin >> name;

      Course* course = cm.findCourse(name);
      if(course){
        cout << "Course " << name << " already exists." << endl;
      }else{
        Course* newCourse = new Course(name);
        cm.addCourse(newCourse);
        cout << "Course " << name << " added." << endl;
      }
    }
    else if(command == "rco"){
      //cout << "Remove which course? ";
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
        //cout << "What course does the category belong to? ";
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
      //cout << "Enter category name: ";
      string name;
      cin >> name;
      Category* cat = courseFocus->findCategory(name);
      if(cat){
        cout << "Category " << name << " already exists." << endl;
      }else{
        //cout << "Enter category weight (decimal): ";
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
        //cout << "What course does the category belong to? ";
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
      //cout << "Enter category name: ";
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
        //cout << "What course does the grade belong to? ";
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
        //cout << "What category does the grade belong to? ";
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
        //cout << "What course does the grade belong to? ";
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
        //cout << "What category does the grade belong to? ";
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

      //cout << "Enter grade index: ";
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


