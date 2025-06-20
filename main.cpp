#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int roll;
    string name;
    int age;
    float marks;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "\nEnter Roll Number: ";
    cin >> s.roll;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cout << "Enter Marks: ";
    cin >> s.marks;
    students.push_back(s);
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "\nNo students found.\n";
        return;
    }
    cout << "\nStudent List:\n";
    for (const auto& s : students) {
        cout << "\nRoll: " << s.roll
             << "\nName: " << s.name
             << "\nAge: " << s.age
             << "\nMarks: " << s.marks << "\n";
    }
}

void searchStudent() {
    int r;
    cout << "\nEnter Roll Number to Search: ";
    cin >> r;
    for (const auto& s : students) {
        if (s.roll == r) {
            cout << "\nFound:\n";
            cout << "Name: " << s.name << "\nAge: " << s.age << "\nMarks: " << s.marks << "\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n2. Display All Students\n3. Search Student\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
