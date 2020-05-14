#include "RegistrationSystem.h"
#include <iostream>
RegistrationSystem::RegistrationSystem() {
	students = NULL;
	studentCount = 0;

}
RegistrationSystem::~RegistrationSystem() {
	if (students) {
		delete[] students;
	}
	
}
void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {
	for (int i = 0; i < studentCount; i++) {
		if (studentId == students[i].getStudentId()) {
			cout<< "Student " << studentId << " already exists"<<endl;
			return;
		}
	}
	if (firstName == "" || lastName == "") {
		cout<< "Cannot leave name blank (" << firstName <<" "<< lastName << ")"<<endl;
		return;
	}
	Student* temp = new Student[studentCount+1];
	Student toAdd(studentId, firstName, lastName);
	for (int i = 0; i < studentCount; i++) {
		temp[i] = students[i];
	}
	delete[] students;
	
	students = new Student[studentCount+1];
	for (int i = 0; i < studentCount; i++) {
		students[i] = temp[i];
	}
	students[studentCount] = toAdd;
	
	delete[] temp;
	studentCount++;
	sortStudents();	
	cout << "Student " << studentId << " has been added" << endl;
}
void RegistrationSystem::deleteStudent(const int studentId) {
	int pos = -1;
	for (int i = 0; i < studentCount; i++) {
		if (studentId == students[i].getStudentId()) {
			pos = i;
		}
	}
	if (pos==-1) {
		cout << "Student " << studentId << " does not exist" << endl;
		return;
	}
	Student* temp = new Student[studentCount - 1];
	for (int i = 0; i < pos; i++) {
		temp[i] = students[i];
	}
	for (int i = pos+1; i < studentCount; i++) {
		temp[i-1] = students[i];
	}
	delete[] students;
	students = new Student[studentCount-1];
	for (int i = 0; i < studentCount - 1; i++) {
		students[i] = temp[i];
	}
	
	delete[] temp;
	studentCount--;
	cout << "Student " << studentId << " has been deleted" << endl;

}
void RegistrationSystem::showStudent(const int studentId) {
	int pos = -1;
	for (int i = 0; i < studentCount; i++) {
		if (studentId == students[i].getStudentId()) {
			pos = i;
		}
	}
	if (pos==-1) {
		cout << "Student couldn't be found " <<studentId<< endl;
		return;
	}
	cout << "Student Id\t" << "First Name\t" << "Last Name" << endl;
	cout << studentId << "\t\t" << students[pos].getFirstName() << "\t\t" << students[pos].getLastName() << endl;
	if (students[pos].getCourseCount()!=0) {
		students[pos].showCourses();
	}
}
void RegistrationSystem::showAllStudents() {
	if (studentCount > 0) {
		cout << "Student Id\t" << "First Name\t" << "Last Name" << endl;
		for (int i = 0; i < studentCount; i++) {
			cout << students[i].getStudentId() << "\t\t" << students[i].getFirstName() << "\t\t" << students[i].getLastName() << endl;
			if (students[i].getCourseCount() != 0) {
				students[i].showCourses();
			}
		}
	}
	else {
		cout << "There are no students in the system" << endl;
	}
}
void RegistrationSystem::sortStudents() {
	if (studentCount < 2) {
		return;
	}
	for (int i = 1; i < studentCount; i++) {
		int j = i - 1;

		while (students[j].getStudentId() > students[j + 1].getStudentId()) {
			Student temp(0, "", "");
				temp = students[j];
			students[j] = students[j + 1];
			students[j + 1] = temp;
			j--;
		}
		
	}

}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName) {
	int pos = -1;
	for (int i = 0; i < studentCount; i++) {
		if (studentId == students[i].getStudentId()) {
			pos = i;
		}
	}
	if (pos==-1) {
		cout << "Student " << studentId << " does not exist"<<endl;
		return;
	}
	if (students[pos].addCourseToStudent(courseId, courseName)) {
		cout << "Course " << courseId << " has been added to Student " << studentId << endl;
	}
	else {
		cout << "Student " << studentId << " is already enrolled in the Course " << courseId << endl;
	}
}
void RegistrationSystem::cancelCourse(const int courseId) {
	int j = 0;
	for (int i = 0; i < studentCount; i++) {
		if (deleteCourse(students[i].getStudentId(), courseId, false))
			j++;
	}
	if (j==0) {
		cout << "Course " << courseId << " does not exist" << endl;
	}
	else {
		cout << "Course " << courseId << " has been cancelled" << endl;
	}
}
bool RegistrationSystem::deleteCourse(const int studentId, const int courseId, const bool isWithdraw) {
	int pos = -1;
	for (int i = 0; i < studentCount; i++) {
		if (studentId == students[i].getStudentId()) {
			pos = i;
		}
	}
	if (pos == -1) {
		if(isWithdraw)
			cout << "Student " << studentId << " does not exist" << endl;
		return false;
	}
	bool flag = students[pos].removeCourseFromStudent(courseId);
	if (flag) {
		if (isWithdraw)
			cout << "Student " << studentId << " has been withdraws from course " << courseId << endl;
		return true;
	}
	else {
		if(isWithdraw)
			cout << "Student " << studentId << " is not enrolled in the Course " <<courseId<< endl;
		return false;
	}
	
}
void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {
		deleteCourse(studentId, courseId, true);
}

void RegistrationSystem::showCourse(const int courseId) {
	int flag = 0;
	string courseName = "";
	for (int i = 0; i < studentCount; i++) {
		for (int j = 0; j < students[i].getCourseCount(); j++) {
			if (students[j].doesExist(courseId)) {
				flag++;
				courseName = students[j].getCourseName(courseId);
			}
		}
	}
	if (flag == 0) {
		cout << "Course " << courseId << " does not exist" << endl;
		return;
	}
	cout << "Course id\t Course name" << endl;
	cout << courseId << "\t" << courseName<< endl;
	cout << "\tStudent id\tFirst name\t Last name" << endl;
	for (int i = 0; i < studentCount; i++) {
		students[i].showCourse(courseId);
	}
	
}

