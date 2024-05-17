#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Student {
    string name;
    string studentID;
    string department;
    string group;
    string contact;
    double gpa;
    string attendance;
};

vector<Student> students; 

double calculateGPA(int math, int physics, int discrete_math, int programming, int calculus) {
    double totalScore = math + physics + discrete_math + programming + calculus;
    double gpa = totalScore / 5.0;
    return gpa;
}

// Function prompts the user for information about students
void enter() {
    int ch = 0; // Storing the number of students the user wants to enter into the system.
    cout << "How many students do you want to enter?" << endl;
    cin >> ch;

    for (int i = 0; i < ch; i++) {
        Student student;
        cout << "\nEnter the Data of student " << i + 1 << endl << endl;
        cout << "Name: ";
        cin >> student.name;
        cout << "Student ID: ";
        cin >> student.studentID;
        cout << "Department: ";
        cin >> student.department;
        cout << "Group: ";
        cin >> student.group;
        cout << "Contact: ";
        cin >> student.contact;

        int math, physics, discrete_math, programming, calculus;
        cout << "Math: ";
        cin >> math;
        cout << "Physics: ";
        cin >> physics;
        cout << "Discrete math: ";
        cin >> discrete_math;
        cout << "Programming: ";
        cin >> programming;
        cout << "Calculus: ";
        cin >> calculus;

        student.gpa = calculateGPA(math, physics, discrete_math, programming, calculus);
        cout << "GPA: " << student.gpa << endl;
        students.push_back(student);
    }
}


void show() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
    } else {
        cout << "All Students\n\n";
        cout << "============================================================================================================\n";
        cout << "Name   \tStudent ID  \tDepartment     \tGroup       \tContact    \tGPA    \tAttendance" << endl;
        cout << "============================================================================================================\n";
        for (const auto& student : students) {
            cout << student.name << "\t" << student.studentID << "\t" << student.department << "  \t" << student.group << "\t" 
                 << student.contact << "\t" << student.gpa << "\t" << student.attendance << endl;
        }
    }
}


void search() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
    } else {
        string rollno;
        cout << "Enter the Student ID of student: ";
        cin >> rollno;
        for (const auto& student : students) {
            if (rollno == student.studentID) {
                cout << "Name: " << student.name << endl;
                cout << "Student ID: " << student.studentID << endl;
                cout << "Department: " << student.department << endl;
                cout << "Group: " << student.group << endl;
                cout << "Contact: " << student.contact << endl;
                cout << "GPA: " << student.gpa << endl;
                cout << "Attendance: " << student.attendance << endl;
                return;
            }
        }
        cout << "Student not found with the given Student ID" << endl;
    }
}

void update() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
    } else {
        string rollno;
        cout << "Enter the Student ID of student you want to update: ";
        cin >> rollno;
        for (auto& student : students) {
            if (rollno == student.studentID) {
                cout << "\nPrevious data:" << endl;
                cout << "Name: " << student.name << endl;
                cout << "Student ID: " << student.studentID << endl;
                cout << "Department: " << student.department << endl;
                cout << "Group: " << student.group << endl;
                cout << "Contact: " << student.contact << endl;
                cout << "GPA: " << student.gpa << endl;
                cout << "Attendance: " << student.attendance << endl;

                cout << "\nEnter new data:" << endl;
                cout << "Name: ";
                cin >> student.name;
                cout << "Student ID: ";
                cin >> student.studentID;
                cout << "Department: ";
                cin >> student.department;
                cout << "Group: ";
                cin >> student.group;
                cout << "Contact: ";
                cin >> student.contact;

                int math, physics, discrete_math, programming, calculus;
                cout << "Math: ";
                cin >> math;
                cout << "Physics: ";
                cin >> physics;
                cout << "Discrete math: ";
                cin >> discrete_math;
                cout << "Programming: ";
                cin >> programming;
                cout << "Calculus: ";
                cin >> calculus;

                student.gpa = calculateGPA(math, physics, discrete_math, programming, calculus);
                cout << "GPA: " << student.gpa << endl;

                return;
            }
        }
        cout << "Student not found with the given Student ID" << endl;
    }
}

void deleterecord() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
    } else {
        int a;
        cout << "Press 1 to delete all records" << endl;
        cout << "Press 2 to delete a specific record" << endl;
        cin >> a;
        if (a == 1) {
            students.clear();
            cout << "All records are deleted" << endl;
        } else if (a == 2) {
            string rollno;
            cout << "Enter the Student ID of student you want to delete: ";
            cin >> rollno;
            for (auto it = students.begin(); it != students.end(); ++it) {
                if (rollno == it->studentID) {
                    students.erase(it);
                    cout << "Your required record is deleted" << endl;
                    return;
                }
            }
            cout << "Student not found with the given Student ID" << endl;
        } else {
            cout << "Invalid input" << endl;
        }
    }
}
void takeAttendance() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
    } else {
        string rollno;
        char attendance_status;
        cout << "Enter the Student ID of student for attendance: ";
        cin >> rollno;
        for (auto& student : students) {
            if (rollno == student.studentID) {
                cout << "Is the student present? (p for present, o for absent): ";
                cin >> attendance_status;
                if (attendance_status == 'p' || attendance_status == 'P') {
                    student.attendance = "Present";
                    cout << "Attendance marked as Present" << endl;
                } else if (attendance_status == 'o' || attendance_status == 'O') {
                    student.attendance = "Absent";
                    cout << "Attendance marked as Absent" << endl;
                } else {
                    cout << "Invalid input for attendance status" << endl;
                }
                return;
            }
        }
        cout << "Student not found with the given Student ID" << endl;
    }
}
void saveToFile() {
    ofstream outfile("student_data.txt");
    if (!outfile) {
        cout << "Error: Unable to open file!" << endl;
        return;
    }
    for (const auto& student : students) {
        outfile << student.name << " " << student.studentID << " " << student.department << " " << student.group << " "
                << student.contact << " " << student.gpa << " " << student.attendance << endl;
    }
    outfile.close();
    cout << "Data saved to file successfully!" << endl;
}

int main() {
    int value;
    while (true) {
        cout << "\nPress 1 to enter data" << endl;
        cout << "Press 2 to show data" << endl;
        cout << "Press 3 to search data" << endl;
        cout << "Press 4 to update data" << endl;
        cout << "Press 5 to delete data" << endl;
        cout << "Press 6 to take attendance" << endl;
        cout << "Press 7 to save data to file" << endl;
        cout << "Press 8 to exit" << endl;
        cin >> value;

        switch (value) {
            case 1:
                enter();
                break;
            case 2:
                show();
                break;
            case 3:
                search();
                break;
            case 4:
                update();
                break;
            case 5:
                deleterecord();
                break;
            case 6:
                takeAttendance();
                break;
            case 7:
                saveToFile();
                break;
            case 8:
                return 0;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
    return 0;
}
