#include "Course.h"

using namespace std;

Course::Course(string name) : name(name), categories(0)
{}

Course::Course(string name, vector<Category*> categories) : name(name), categories(categories)
{}

Course::~Course(){
  for(int i = categories.size()-1; i >= 0; i--){
    delete categories.at(i);
  }
}
double Course::calculateWeightedAverage(){
  double sum = 0;
  for(int i = 0; i < categories.size(); i++){
    sum += categories.at(i)->calculateAverage() * categories.at(i)->getWeight();
  }
  return sum;
}

void Course::addCategory(Category* category){
  categories.push_back(category);
}

void Course::addCategory(string name, double weight){
  categories.push_back(new Category(name, weight));
}

void Course::removeCategory(Category* category){
  bool removed = false;
  for(int i = 0; i < categories.size(); i++){
    if(category->getName() == categories.at(i)->getName()){
      categories.erase(categories.begin()+i);
      cout << "Category " << name << " removed." << endl;
      removed = true;
    }
  }
  if(!removed){
    cout << "Category " << name << " not found." << endl;
  }
}

void Course::removeCategory(string name){
  bool removed = false;
  for(int i = 0; i < categories.size(); i++){
    if(name == categories.at(i)->getName()){
      categories.erase(categories.begin()+i);
      cout << "Category " << name << " removed." << endl;
      removed = true;
    }
  }
  if(!removed){
    cout << "Category " << name << " not found." << endl;
  }
}

Category* Course::findCategory(string name){
  for(int i = 0; i < categories.size(); i++){
    if(name == categories.at(i)->getName()){
      return categories.at(i);
    }
  }
  return nullptr;
}

string Course::getName(){
  return name;
}

vector<Category*> Course::getCategories(){
  return categories;
}

void Course::print(){
  cout << "====================" << endl;
  cout << name << " grade breakdown:" << endl;
  for(int i = 0; i < categories.size(); i++){
    categories.at(i)->print();
  }
}
