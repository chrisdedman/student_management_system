/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
/***************************************************************
        Function to write multiple students in file
***************************************************************/
void writeMultipleStudent()
{
    ofstream data;
    int numberOfRecord;
    int count = 0; // Counter for number of multiple record to add into the database
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

    cout << "How many record do you want to add? ";
    cin >> numberOfRecord;
    cin.ignore();

    cout << "\n\n\t\tENTER STUDENT'S DETAILS\n\n"
         << endl;
    do
    {
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
        count++;

        // Divider between students
        data << "#" << endl;
        cin.ignore();

    } while (count != numberOfRecord);

    data.close();
    cout << "Record Saved... Press any key to continue ...";
    cin.get();
}