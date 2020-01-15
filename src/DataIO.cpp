#include "DataIO.h"

using namespace std;

void DataIO::test(string s){
  ofstream ofs;
  cout << "yes";
  ofs.open("../data/test.txt");
  ofs << s;
  ofs.close();
}

vector<Course*> DataIO::readCourses(){
  vector<string> files = getFiles();
  vector<Course*> courses;
  for(int i = 0; i < files.size(); i++){
    string filename = files.at(i);
    size_t lastindex = filename.find_last_of(".");
    string rawname = filename.substr(0, lastindex);
    Course* newCourse = new Course(rawname);
    string path = "../data/"+filename;
    ifstream ifs(path);
    string line;
    if(ifs.is_open()){
      while(getline(ifs, line)){
        vector<string> tokens = tokenizer(line);
        Category* newCat = new Category(tokens.at(0), atof(tokens.at(1).c_str()));
        for(int i = 2; i < tokens.size(); i++){
          newCat->addGrade(atof(tokens.at(i).c_str()));
        }
        newCourse->addCategory(newCat);
      }
    }
    ifs.close();
    courses.push_back(newCourse);
  }
  return courses;
}

void DataIO::writeCourses(vector<Course*> courses){
  for(int i = 0; i < courses.size(); i++){
    string filename = courses.at(i)->getName() + ".csv";
    string path = "../data/" + filename;
    ofstream ofs(path);
    if(ofs.is_open()){
      vector<Category*> cats = courses.at(i)->getCategories();
      for(int j = 0; j < cats.size(); j++){
        ofs << cats.at(j)->getName() << ",";
        ofs << cats.at(j)->getWeight();
        for(int k = 0; k < cats.at(j)->getGrades().size(); k++){
          ofs << "," << cats.at(j)->getGrades().at(k);
        }
        ofs << "\n";
      }
    }
    ofs.close();
  }
}

vector<string> DataIO::getFiles(){
  DIR* dir;
  dirent* pdir;
  vector<string> files;
  string path = "../data/";
  dir = opendir(path.c_str());
  while(pdir = readdir(dir)){
    files.push_back(pdir->d_name);
  }
  files.erase(files.begin(), files.begin()+3);
  return files;
}

vector<string> DataIO::tokenizer(string line){
  vector<string> tokens;
  stringstream ss(line);
  string intermediate;
  while(getline(ss, intermediate, ',')){
    tokens.push_back(intermediate);
  }
  return tokens;
}
