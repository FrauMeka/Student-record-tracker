#include <iostream>
#include <fstream>
using namespace std;

string arr1[20], arr2[20], arr3[20], arr4[20], arr5[20], arr6[20], arr7[20];

int total = 0; //total number of students

//Calculate gpa
double calculateGPA(int math, int physics, int discrete_math, int programming, int calculus) {
    double totalScore = math + physics + discrete_math + programming + calculus;
    double gpa = totalScore / 5.0;
    return gpa;
}

//function prompts the user for information about students
void enter() {
    int ch = 0; //storing the number of students the user wants to enter into the system.
    cout << "How many students do you want to enter?" << endl;
    cin >> ch;

    if (total == 0) {
        for (int i = 0; i < ch; i++) {
            cout << "\nEnter the Data of student " << i + 1 << endl << endl;
            cout << "Name: ";
            cin >> arr1[i];
            cout << "Student ID: ";
            cin >> arr2[i];
            cout << "Department: ";
            cin >> arr3[i];
            cout << "Group: ";
            cin >> arr4[i];
            cout << "Contact: ";
            cin >> arr5[i];

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

            // Calculate GPA
            double gpa = calculateGPA(math, physics, discrete_math, programming, calculus);
            cout << "GPA: " << gpa << endl;

            // Store GPA
            arr6[i] = to_string(gpa);
        }
        total = ch;
        //If total is not 0,program begins to add new students to the existing ones.
    } else {
        for (int i = total; i < ch + total; i++) {
            cout << "\nEnter the Data of student " << i + 1 << endl << endl;
            cout << "Name: ";
            cin >> arr1[i];
            cout << "Student ID: ";
            cin >> arr2[i];
            cout << "Department: ";
            cin >> arr3[i];
            cout << "Group: ";
            cin >> arr4[i];
            cout << "Contact: ";
            cin >> arr5[i];


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

            
            double gpa = calculateGPA(math, physics, discrete_math, programming, calculus);
            cout << "GPA: " << gpa << endl;

            // number values ​​into strings.
            arr6[i] = to_string(gpa);
        }
        total += ch;
    }
}

void show() {
    if (total == 0) {
        cout << "No data is entered" << endl;
    } else {
        cout << "All Students\n\n";
        cout << "============================================================================================================\n";
        cout << "Name   \tStudent ID      \tDepartment     \tCroup       \tContact          \tGPA          \tAttendance" << endl;
        cout << "============================================================================================================\n";
        for (int i = 0; i < total; i++) {
            cout << arr1[i] << "\t" << arr2[i] << "\t" << arr3[i] << "\t" << arr4[i] << "\t" << arr5[i] << "\t" << arr6[i] <<"\t"<<arr7[i]<< endl;
        }
    }
}

void search() {
    if (total == 0) {
        cout << "No data is entered" << endl;
    } else {
        string rollno;
        cout << "Enter the Student ID of student: ";
        cin >> rollno;
        for (int i = 0; i < total; i++) {
            if (rollno == arr2[i]) {
                cout << "Name: " << arr1[i] << endl;
                cout << "student ID: " << arr2[i] << endl;
                cout << "Course: " << arr3[i] << endl;
                cout << "Class: " << arr4[i] << endl;
                cout << "Contact: " << arr5[i] << endl;
                cout << "GPA: " << arr6[i] << endl;
            }
        }
    }
}

void update() {
    if (total == 0) {
        cout << "No data is entered" << endl;
    } else {
        string rollno;
        cout << "Enter the Student ID of student you want to update: ";
        cin >> rollno;
        for (int i = 0; i < total; i++) {
            if (rollno == arr2[i]) {
                cout << "\nPrevious data:" << endl;
                cout << "Data of Student " << i + 1 << endl;
                cout << "Name: " << arr1[i] << endl;
                cout << "Student ID: " << arr2[i] << endl;
                cout << "Course: " << arr3[i] << endl;
                cout << "Class: " << arr4[i] << endl;
                cout << "Contact: " << arr5[i] << endl;
                cout << "GPA: " << arr6[i] << endl;
                cout << "\nEnter new data:" << endl;
                cout << "Enter name: ";
                cin >> arr1[i];
                cout << "Enter Student ID: ";
                cin >> arr2[i];
                cout << "Enter course: ";
                cin >> arr3[i];
                cout << "Enter class: ";
                cin >> arr4[i];
                cout << "Enter contact: ";
                cin >> arr5[i];
            }
        }
    }
}

void deleterecord() {
    if (total == 0) {
        cout << "No data is entered" << endl;
    } else {
        int a;
        cout << "Press 1 to delete all records" << endl;
        cout << "Press 2 to delete a specific record" << endl;
        cin >> a;
        if (a == 1) {
            total = 0;
            cout << "All records are deleted" << endl;
        } else if (a == 2) {
            string rollno;
            cout << "Enter the roll no of student you want to delete: ";
            cin >> rollno;
            for (int i = 0; i < total; i++) {
                if (rollno == arr2[i]) {
                    for (int j = i; j < total; j++) {
                        arr1[j] = arr1[j + 1];
                        arr2[j] = arr2[j + 1];
                        arr3[j] = arr3[j + 1];
                        arr4[j] = arr4[j + 1];
                        arr5[j] = arr5[j + 1];
                        arr6[j] = arr6[j + 1];
                    }
                    total--;
                    cout << "Your required record is deleted" << endl;
                }
            }
        } else {
            cout << "Invalid input" << endl;
        }
    }
}

void takeAttendance() {
    if (total == 0) {
        cout << "No data is entered" << endl;
    } else {
        string rollno;
        char attendance_status;
        cout << "Enter the Student ID of student for attendance: ";
        cin >> rollno;
        for (int i = 0; i < total; i++) {
            if (rollno == arr2[i]) {
                cout << "Is the student present? (p for present, o for absent): ";
                cin >> attendance_status;
                if (attendance_status == 'p' || attendance_status == 'P') {
                    arr7[i] = "Present";
                    cout << "Attendance marked as Present" << endl;
                } else if (attendance_status == 'o' || attendance_status == 'O') {
                    arr7[i] = "Absent";
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
    for (int i = 0; i < total; i++) {
        outfile << arr1[i] << " " << arr2[i] << " " << arr3[i] << " " << arr4[i] << " " << arr5[i] << " " << arr6[i] << " " << arr7[i] << endl;
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
