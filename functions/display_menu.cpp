/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
/***************************************************************
        Function to read all records from file
***************************************************************/
void display_menu()
{
    ifstream database;
    string studentID;
    string studentName;
    string studentClasses;
    string studentGPA;

    database.open("database.dat", ios_base::in);
    if (!database)
    {
        cout << "No record found!" << endl;
        cin.get();
        return;
    }

    cout << "\n\n\n\t\tDISPLAY ALL RECORD\n\n";
    /*  while (getline(database, studentName))
         {
           database.ignore();
           getline(database, studentClasses);
           database.ignore();
           database >> GPA;
           cout << studentName << '\n'
                << studentClasses << '\n'
                << GPA << endl;
           while (database >> breaking)
             {
               if (breaking == "////")
               {
                 break;
               }
               database.ignore();
             }
         }
      */

    while (getline(database, studentName))
    {
        getline(database, studentClasses);
        getline(database, studentGPA);
        cout << studentName << '\n'
             << studentClasses << '\n'
             << studentGPA << endl;
    }

    cin.get();
    database.close();
    cout << "\nPress enter to return ...";
    cin.get();
}