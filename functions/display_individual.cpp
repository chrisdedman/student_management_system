/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
/***************************************************************
        Function to read specific record from file
***************************************************************/
void display_individual()
{
    ifstream database;
    string theStudent;
    string studentName;
    string studentClasses;
    string studentID;
    string studentGPA;
    string studentSeparator;
    double GPA;

    database.open("database.dat", ios_base::in);
    if (!database)
    {
        cout << "No record found!" << endl;
        cout << "\nPress enter to return ...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "Who's file would you want to see [Enter Student's Name]\n[CASE SENSITIVE]: ";
    cin.ignore();
    getline(cin, theStudent);

    studentID = "Name: " + theStudent;
    cout << "\n\n\t\tDISPLAY INDIVIDUAL RECORD\n\n"
         << endl;
    while (getline(database, studentName))
    {
        getline(database, studentClasses);
        getline(database, studentGPA);
        getline(database, studentSeparator);

        if ((studentName.compare(studentID)) == 0)
        {
            cout << studentName << '\n'
                 << studentClasses << '\n'
                 << studentGPA << endl;
                 
            database.close();
            cout << "\nPress enter to return ...";
            cin.get();
            return;
        }
    }
    cout << "Record No Found!" << endl;

    database.close();
    cout << "\nPress enter to return ...";
    cin.get();
}