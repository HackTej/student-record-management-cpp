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

void updateStudent() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\n[Error] No database found.\n";
        return;
    }

    string targetRoll, line;
    cout << "Enter Roll Number to update: ";
    cin >> targetRoll;

    ofstream temp("temp.txt");
    bool found = false;

    while (getline(file, line)) {
        // Raw string matching to find the target roll number line
        if (line.find(targetRoll + ",") == 0) {
            found = true;
            Student s;
            s.rollNo = targetRoll;
            cin.ignore();
            cout << "Enter New Full Name: ";
            getline(cin, s.name);
            cout << "Enter New Course: ";
            getline(cin, s.course);

            // Write the updated data string into the temporary file
            temp << s.rollNo << "," << s.name << "," << s.course << endl;
        } else {
            // Keep all other lines unchanged
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    // Replace old file with the updated temporary file
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        cout << "\n[Success] Student record updated successfully.\n";
    } else {
        cout << "\n[Not Found] Roll Number not found.\n";
    }
}

void deleteStudent() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\n[Error] No database found.\n";
        return;
    }

    string targetRoll, line;
    cout << "Enter Roll Number to delete: ";
    cin >> targetRoll;

    ofstream temp("temp.txt");
    bool found = false;

    while (getline(file, line)) {
        // If it matches the roll number, skip writing it (deleting it)
        if (line.find(targetRoll + ",") == 0) {
            found = true;
        } else {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) {
        cout << "\n[Success] Student record deleted successfully.\n";
    } else {
        cout << "\n[Not Found] Roll Number not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n=== Student Record System ===\n";
        cout << "1. Add New Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search by Roll Number\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: addStudent(); break;
            case 2: viewAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting system...\n"; break;
            default: cout << "Invalid selection. Try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}