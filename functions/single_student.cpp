/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
/***************************************************************
        Function to write a single student in file
***************************************************************/
void write_database()
{
    ofstream data;
    string student_record;
    string studentClass;
    double studentGPA;

    data.open("database.dat", ios_base::app); // ios_base::app <--- this add data at the end of the opened file
    if (!data)
    {
        cout << "No record found!" << endl;
        cout << "\nPress enter to return ...";
        cin.ignore();
        cin.get();
        return;
    }

    cin.ignore();

    cout << "\n\n\t\tENTER STUDENT'S DETAILS\n\n"
         << endl;

    cout << "Name: ";
    getline(cin, student_record);
    data << setw(7) << left << "Name: " << student_record << endl;

    cout << "Class: ";
    getline(cin, studentClass);
    data << setw(7) << left << "Class: " << studentClass << endl;

    cout << "Overall GPA: ";
    cin >> studentGPA;
    data << fixed << setprecision(2);
    data << setw(7) << left << "GPA: " << studentGPA << endl;

    // Divider between students
    data << "#" << endl;

    data.close();
    cout << "Record Saved... Press any key to continue ...";
    cin.get();
}