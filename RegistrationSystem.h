#ifndef __RegistrationSystem_H
#define __RegistrationSystem_H
#include "Student.h"
using namespace std;
class RegistrationSystem {
public:
		RegistrationSystem();
		~RegistrationSystem();
		void addStudent(const int studentId, const string firstName, const string lastName);
		void deleteStudent(const int studentId);
		void addCourse(const int studentId, const int courseId, const string courseName);
		void withdrawCourse(const int studentId, const int courseId);
		void cancelCourse(const int courseId);
		void showStudent(const int studentId);
		void showCourse(const int courseId);
		void showAllStudents();

		void sortStudents();
		
private:
	Student* students;
	int studentCount;
	bool deleteCourse(const int studentId, const int courseId, const bool isWithdraw);
};
#endif