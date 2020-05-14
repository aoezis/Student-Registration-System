#ifndef __STUDENT_H
#define __STUDENT_H
#include "Course.h"
class Student {
public:
	Student(const int id=0, const std::string fName="", const std::string lName="");
	~Student();
	std::string getFirstName();
	std::string getLastName();
	int getStudentId();
	bool addCourseToStudent(const int courseId, const std::string courseName);
	bool removeCourseFromStudent(const int courseId);
	int getCourseCount();
	void showCourses();

	void operator=(const Student &right);
	void showCourse(int courseId);
	bool doesExist(int courseId);
	string getCourseName(int courseId);
private:
	int studentId;
	std::string firstName;
	std::string lastName;
	Course* courses;
	int courseCount;
};
#endif