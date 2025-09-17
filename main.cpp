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
    return Student{name, age, major, gpa};
}

// Тестируемая версия отображения студентов
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

// Оригинальные функции для интерфейса
void searchByName(const vector<Student>& database) {
    string searchName;
    cout << "Введите имя для поиска: ";
    cin >> searchName;
    
    auto results = searchByNameTestable(database, searchName);
    
    cout << "Результаты поиска:\n";
    if (results.empty()) {
        cout << "Студенты с именем '" << searchName << "' не найдены.\n";
    } else {
        for (const Student& student : results) {
            cout << "Имя: " << student.name << "\n";
            cout << "Возраст: " << student.age << "\n";
            cout << "Специальность: " << student.major << "\n";
            cout << "Средний балл: " << student.gpa << "\n\n";
        }
    }
}

void searchByMajor(const vector<Student>& database) {
    string searchMajor;
    cout << "Введите специальность для поиска: ";
    cin >> searchMajor;
    
    auto results = searchByMajorTestable(database, searchMajor);
    
    cout << "Результаты поиска:\n";
    if (results.empty()) {
        cout << "Студенты со специальностью '" << searchMajor << "' не найдены.\n";
    } else {
        for (const Student& student : results) {
            cout << "Имя: " << student.name << "\n";
            cout << "Возраст: " << student.age << "\n";
            cout << "Специальность: " << student.major << "\n";
            cout << "Средний балл: " << student.gpa << "\n\n";
        }
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
        cout << "Возраст: : " << student.age << "\n";
        cout << "Специальность: " << student.major << "\n";
        cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Тесты
TEST(StudentTest, ToLowerTest) {
    EXPECT_EQ(toLower("HELLO"), "hello");
    EXPECT_EQ(toLower("Hello World"), "hello world");
    EXPECT_EQ(toLower("123ABC"), "123abc");
    EXPECT_EQ(toLower(""), "");
}

TEST(StudentTest, SearchByNameTest) {
    vector<Student> database = {
        {"Ivan", 20, "CS", 4.5},
        {"ivan", 21, "Math", 4.2},
        {"Maria", 22, "Physics", 4.8}
    };

    auto result1 = searchByNameTestable(database, "Ivan");
    EXPECT_EQ(result1.size(), 2);
    EXPECT_EQ(result1[0].name, "Ivan");
    EXPECT_EQ(result1[1].name, "ivan");

    auto result2 = searchByNameTestable(database, "Maria");
    EXPECT_EQ(result2.size(), 1);
    EXPECT_EQ(result2[0].name, "Maria");

    auto result3 = searchByNameTestable(database, "John");
    EXPECT_TRUE(result3.empty());
}

TEST(StudentTest, SearchByMajorTest) {
    vector<Student> database = {
        {"Ivan", 20, "CS", 4.5},
        {"Maria", 22, "cs", 4.8},
        {"John", 21, "Math", 4.2}
    };

    auto result = searchByMajorTestable(database, "CS");
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].major, "CS");
    EXPECT_EQ(result[1].major, "cs");
}

TEST(StudentTest, CreateStudentTest) {
    Student student = createStudentTestable("Test", 20, "CS", 4.5);
    
    EXPECT_EQ(student.name, "Test");
    EXPECT_EQ(student.age, 20);
    EXPECT_EQ(student.major, "CS");
    EXPECT_DOUBLE_EQ(student.gpa, 4.5);
}

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

TEST(StudentTest, StudentStructTest) {
    Student s{"Test", 20, "CS", 4.5};
    
    EXPECT_EQ(s.name, "Test");
    EXPECT_EQ(s.age, 20);
    EXPECT_EQ(s.major, "CS");
    EXPECT_DOUBLE_EQ(s.gpa, 4.5);
}

int runProgram() {
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
    
    return 0;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        // Режим тестирования
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    } else {
        // Режим обычной программы
        return runProgram();
    }
}
