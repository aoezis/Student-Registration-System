#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(const int id, const std::string fName, const std::string lName) {
	studentId = id;
	firstName = fName;
	lastName = lName;
	courses =NULL;
	courseCount = 0;
}
Student::~Student() {
	if (courses) {
		delete[] courses;
	}
}
std::string Student::getFirstName() {
	return firstName;
}
std::string Student::getLastName() {
	return lastName;
}
int Student::getStudentId() {
	return studentId;
}
int Student::getCourseCount() {
	return courseCount;
}
bool Student::addCourseToStudent(const int courseId, const std::string courseName) {

	for (int i = 0; i < courseCount; i++) {
		if (courses[i].getCourseId() == courseId)
			return false;
	}

	Course* temp = new Course[courseCount+1];
	Course toAdd(courseName, courseId);
	for (int i = 0; i < courseCount; i++) {
		temp[i] = courses[i];
	}
	delete[] courses;
	courses = new Course[courseCount + 1];
	for (int i = 0; i < courseCount+1; i++) {
		courses[i] = temp[i];
	}
	courses[courseCount] = toAdd;
	delete[] temp;
	courseCount++;
	return true;

}
bool Student::removeCourseFromStudent(const int courseId) {
	int pos = -1;
	for (int i = 0; i < courseCount; i++) {
		if (courses[i].getCourseId() == courseId)
			pos = i;
	}
	if (pos == -1) {
		return false;
	}
	Course* temp = new Course[courseCount - 1];
	for (int i = 0; i < pos; i++) {
		temp[i] = courses[i];
	}
	for (int i = pos + 1;i< courseCount; i++) {
		temp[i - 1] = courses[i];
	}
	delete[] courses;
	courses = new Course[courseCount - 1];
	for (int i = 0; i < courseCount - 1; i++) {
		courses[i] = temp[i];
	}
	delete[] temp;
	courseCount--;
	return true;
}
void Student::showCourses() {
	cout << "\tCourseId\tCourse Name"<< endl;
	for (int i = 0; i < courseCount; i++) {
		cout << "\t" << courses[i].getCourseId() << "\t\t" << courses[i].getCourseName()<<endl;
	}
}

void Student::operator=(const Student &right) {
	if (&right != this) {
		studentId = right.studentId;
		firstName = right.firstName;
		lastName = right.lastName;
		courseCount = right.courseCount;
		delete[] courses;
		if (courseCount == 0) {
			courses = NULL;
		}
		else {
			courses = new Course[courseCount];
			for (int i = 0; i < courseCount; i++) {
				courses[i] = right.courses[i];
			}
		}
	}
}
void Student::showCourse(int courseId) {
	for (int i = 0; i < courseCount; i++) {
		if (courseId == courses[i].getCourseId()) {
			cout << "\t" << studentId << "\t" << firstName <<"\t"<<lastName<< endl;
			return;
		}
	}
}
string Student::getCourseName(int courseId) {
	for (int i = 0; i < courseCount; i++) {
		if (courseId == courses[i].getCourseId()) {
			return courses[i].getCourseName();
		}
	}
	return"";
}
bool Student::doesExist(int courseId) {

	for (int i = 0; i < courseCount; i++) {
		if (courseId == courses[i].getCourseId()) {
			return true;
		}
	}
	return false;	
	
}