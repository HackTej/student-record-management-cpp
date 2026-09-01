#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string rollNo;
    string name;
    string course;
};

void addStudent() {
    ofstream file("students.txt", ios::app);
    Student s;
    
    cout << "Enter Roll Number: ";
    cin >> s.rollNo;
    cin.ignore(); 
    
    cout << "Enter Full Name: ";
    getline(cin, s.name);
    
    cout << "Enter Course: ";
    getline(cin, s.course);
    
    // Save to file comma-separated
    file << s.rollNo << "," << s.name << "," << s.course << endl;
    file.close();
    
    cout << "\n[Success] Student record saved securely.\n";
}

void viewAllStudents() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\n[Error] No database found. Add a student first.\n";
        return;
    }
    
    string line;
    cout << "\n--- Student Directory ---\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void searchStudent() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\n[Error] No database found.\n";
        return;
    }

    string searchRoll, line;
    cout << "Enter Roll Number to search: ";
    cin >> searchRoll;
    
    bool found = false;
    while (getline(file, line)) {
        // If the line starts with the exact roll number and a comma
        if (line.find(searchRoll + ",") == 0) {
            cout << "\n[Record Found]: " << line << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "\n[Not Found] No student matches that Roll Number.\n";
    }
    file.close();
}

int main() {
    int choice;
    do {
        cout << "\n=== Student Record System ===\n";
        cout << "1. Add New Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting system...\n"; break;
            default: cout << "Invalid selection. Try again.\n";
        }
    } while (choice != 4);
    
    return 0;
}