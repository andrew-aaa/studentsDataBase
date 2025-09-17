#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int age;
    string major;
    double gpa;
};

string toLower(const string& str);
void searchByName(const vector<Student>& database);
void searchByMajor(const vector<Student>& database);
void addStudent(vector<Student>& database);
void displayStudents(const vector<Student>& database);

// Новые тестируемые версии функций
vector<Student> searchByNameTestable(const vector<Student>& database, const string& searchName);
vector<Student> searchByMajorTestable(const vector<Student>& database, const string& searchMajor);
Student createStudentTestable(const string& name, int age, const string& major, double gpa);
string displayStudentsTestable(const vector<Student>& database);

#endif