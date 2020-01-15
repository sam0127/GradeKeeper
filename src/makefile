gradekeeper: main.cpp Category.o Course.o CourseManager.o DataIO.o
	g++ -w -std=c++11 -o gradekeeper main.cpp Category.o Course.o CourseManager.o DataIO.o

Category.o: Category.h Category.cpp
	g++ -w -std=c++11 -c Category.cpp

Course.o: Course.h Course.cpp
	g++ -w -std=c++11 -c Course.cpp

CourseManager.o: CourseManager.h CourseManager.cpp
	g++ -w -std=c++11 -c CourseManager.cpp

DataIO.o: DataIO.h DataIO.cpp
	g++ -w -std=c++11 -c DataIO.cpp

run:
	./gradekeeper

clean:
	rm -rf *.o
	rm -rf gradekeeper
