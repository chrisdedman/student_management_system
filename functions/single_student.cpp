/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
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
        cin.get();
        return;
    }
    cin.ignore();
    cout << "\n\n\t\tENTER STUDENT'S DETAILS\n\n"
         << endl;

    cout << "Name: ";
    getline(cin, student_record);
    data << "Name: " << student_record << endl;

    cout << "Class: ";
    getline(cin, studentClass);
    data << "Classes: " << studentClass << endl;

    cout << "Overall GPA: ";
    cin >> studentGPA;
    data << fixed << setprecision(2);
    data << "GPA: " << studentGPA << endl;

    // Divider between students
    data << "\n////\n"
         << endl;

    data.close();
    cout << "Record Saved... Press any key to continue ...";
    cin.get();
}