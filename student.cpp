#include "student.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

void searchByName(const vector<Student>& database) {
    string searchName;
    cout << "Введите имя для поиска: ";
    cin >> searchName;
    
    string lowerSearchName = toLower(searchName);
    bool found = false;
    
    cout << "Результаты поиска:\n";
    for (const Student& student : database) {
        if (toLower(student.name) == lowerSearchName) {
            cout << "Имя: " << student.name << "\n";
            cout << "Возраст: " << student.age << "\n";
            cout << "Специальность: " << student.major << "\n";
            cout << "Средний балл: " << student.gpa << "\n\n";
            found = true;
        }
    }
    
    if (!found) {
        cout << "Студенты с именем '" << searchName << "' не найдены.\n";
    }
}

void searchByMajor(const vector<Student>& database) {
    string searchMajor;
    cout << "Введите специальность для поиска: ";
    cin >> searchMajor;
    
    string lowerSearchMajor = toLower(searchMajor);
    bool found = false;
    
    cout << "Результаты поиска:\n";
    for (const Student& student : database) {
        if (toLower(student.major) == lowerSearchMajor) {
            cout << "Имя: " << student.name << "\n";
            cout << "Возраст: " << student.age << "\n";
            cout << "Специальность: " << student.major << "\n";
            cout << "Средний балл: " << student.gpa << "\n\n";
            found = true;
        }
    }
    
    if (!found) {
        cout << "Студенты со специальностью '" << searchMajor << "' не найдены.\n";
    }
}

void addStudent(vector<Student>& database) {
    Student student;
    cout << "Введите имя студента: ";
    cin >> student.name;
    cout << "Введите возраст студента: ";
    cin >> student.age;
    cout << "Введите специальность студента: ";
    cin >> student.major;
    cout << "Введите средний балл студента: ";
    cin >> student.gpa;

    database.push_back(student);
    cout << "Студент добавлен в базу данных.\n";
}

void displayStudents(const vector<Student>& database) {
    cout << "Список студентов:\n";
    for (const Student& student : database) {
        cout << "Имя: " << student.name << "\n";
        cout << "Возраст: " << student.age << "\n";
        cout << "Специальность: " << student.major << "\n";
        cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Тестируемая версия поиска по имени
vector<Student> searchByNameTestable(const vector<Student>& database, const string& searchName) {
    vector<Student> result;
    string lowerSearchName = toLower(searchName);
    
    for (const Student& student : database) {
        if (toLower(student.name) == lowerSearchName) {
            result.push_back(student);
        }
    }
    
    return result;
}

// Тестируемая версия поиска по специальности
vector<Student> searchByMajorTestable(const vector<Student>& database, const string& searchMajor) {
    vector<Student> result;
    string lowerSearchMajor = toLower(searchMajor);
    
    for (const Student& student : database) {
        if (toLower(student.major) == lowerSearchMajor) {
            result.push_back(student);
        }
    }
    
    return result;
}

// Тестируемая версия создания студента
Student createStudentTestable(const string& name, int age, const string& major, double gpa) {
    Student student;
    student.name = name;
    student.age = age;
    student.major = major;
    student.gpa = gpa;
    return student;
}

// Тестируемая версия отображения студентов (возвращает строку)
string displayStudentsTestable(const vector<Student>& database) {
    stringstream ss;
    for (const Student& student : database) {
        ss << "Имя: " << student.name << "\n";
        ss << "Возраст: " << student.age << "\n";
        ss << "Специальность: " << student.major << "\n";
        ss << "Средний балл: " << student.gpa << "\n\n";
    }
    return ss.str();
}