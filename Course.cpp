#include "Course.h"
using namespace std;
Course::Course(const std::string cName, const int cId) {
	courseName = cName;
	courseId = cId;
}
Course::~Course(){
}
int Course::getCourseId() {
	return courseId;
}
string Course::getCourseName() {
	return courseName;
}
void Course::operator=(const Course &right) {
	if (&right != this) {
		courseId = right.courseId;
		courseName = right.courseName;
	}
}