#ifndef __Course_H
#define __Course_H
#include <string>
using namespace std;
#include <iostream>
class Course {
public:
	Course(const string cName = "", const int cId = 0);
	~Course();
	void operator=(const Course &right);
	int getCourseId();
	string getCourseName();
private:
	string courseName;
	int courseId;
};

#endif