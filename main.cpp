#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


struct Student {
    string name;
    int age;
    string major;
    double gpa;
};

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

// Тест для функции toLower
TEST(StudentTest, ToLowerTest) {
    EXPECT_EQ(toLower("HELLO"), "hello");
    EXPECT_EQ(toLower("Hello World"), "hello world");
    EXPECT_EQ(toLower("123ABC"), "123abc");
    EXPECT_EQ(toLower(""), "");
    EXPECT_EQ(toLower("привет"), "привет");
}

// Тест для поиска по имени
TEST(StudentTest, SearchByNameTest) {
    vector<Student> database = {
        {"Ivan", 20, "CS", 4.5},
        {"ivan", 21, "Math", 4.2},
        {"Maria", 22, "Physics", 4.8}
    };

    // Поиск по имени "Ivan" (регистронезависимый)
    auto result1 = searchByNameTestable(database, "Ivan");
    EXPECT_EQ(result1.size(), 2); // Должен найти Ivan и ivan
    EXPECT_EQ(result1[0].name, "Ivan");
    EXPECT_EQ(result1[1].name, "ivan");

    // Поиск по имени "Maria"
    auto result2 = searchByNameTestable(database, "Maria");
    EXPECT_EQ(result2.size(), 1);
    EXPECT_EQ(result2[0].name, "Maria");

    // Поиск несуществующего имени
    auto result3 = searchByNameTestable(database, "John");
    EXPECT_TRUE(result3.empty());
}

// Тест для поиска по специальности
TEST(StudentTest, SearchByMajorTest) {
    vector<Student> database = {
        {"Ivan", 20, "CS", 4.5},
        {"Maria", 22, "cs", 4.8},
        {"John", 21, "Math", 4.2}
    };

    // Поиск по специальности "CS" (регистронезависимый)
    auto result = searchByMajorTestable(database, "CS");
    EXPECT_EQ(result.size(), 2); // Должен найти CS и cs
    EXPECT_EQ(result[0].major, "CS");
    EXPECT_EQ(result[1].major, "cs");
}

// Тест для создания студента
TEST(StudentTest, CreateStudentTest) {
    Student student = createStudentTestable("Test", 20, "CS", 4.5);
    
    EXPECT_EQ(student.name, "Test");
    EXPECT_EQ(student.age, 20);
    EXPECT_EQ(student.major, "CS");
    EXPECT_DOUBLE_EQ(student.gpa, 4.5);
}

// Тест для отображения студентов
TEST(StudentTest, DisplayStudentsTest) {
    vector<Student> database = {
        {"Ivan", 20, "CS", 4.5},
        {"Maria", 22, "Physics", 4.8}
    };

    string result = displayStudentsTestable(database);
    
    EXPECT_TRUE(result.find("Ivan") != string::npos);
    EXPECT_TRUE(result.find("Maria") != string::npos);
    EXPECT_TRUE(result.find("CS") != string::npos);
    EXPECT_TRUE(result.find("Physics") != string::npos);
    EXPECT_TRUE(result.find("4.5") != string::npos);
    EXPECT_TRUE(result.find("4.8") != string::npos);
}

// Тест для структуры Student
TEST(StudentTest, StudentStructTest) {
    Student s{"Test", 20, "CS", 4.5};
    
    EXPECT_EQ(s.name, "Test");
    EXPECT_EQ(s.age, 20);
    EXPECT_EQ(s.major, "CS");
    EXPECT_DOUBLE_EQ(s.gpa, 4.5);
}

void view() {
    vector<Student> database;

    int choice;
    do {
        cout << "Меню:\n";
        cout << "1. Добавить студента\n";
        cout << "2. Вывести список студентов\n";
        cout << "3. Поиск по имени\n";
        cout << "4. Поиск по специальности\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3:
                searchByName(database);
                break;
            case 4:
                searchByMajor(database);
                break;
            case 0:
                cout << "Выход из программы.\n";
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    } else {
        view();
        return 0;
    }
}
