gradekeeper: Category.o Course.o CourseManager.o
	g++ -w -std=c++11 -o gradekeeper main.cpp Category.o Course.o CourseManager.o

Category.o: Category.h Category.cpp
	g++ -w -std=c++11 -c Category.cpp

Course.o: Course.h Course.cpp
	g++ -w -std=c++11 -c Course.cpp

CourseManager.o: CourseManager.h CourseManager.cpp
	g++ -w -std=c++11 -c CourseManager.cpp


run:
	./gradekeeper

clean:
	rm -rf *.o
	rm -rf gradekeeper
