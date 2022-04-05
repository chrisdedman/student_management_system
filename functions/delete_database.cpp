/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
/***************************************************************
        Function to delete database
***************************************************************/
void delete_database()
{
    ifstream data;
    char deleteDatabase;

    data.open("database.dat");
    if (!data)
    {
        cout << "No record found!" << endl;
        cin.ignore();
        cin.get();
        return;
    }
    cout << "Do you want to delete all records? [Y/n] ";
    cin >> deleteDatabase;
    if (deleteDatabase == 'y' || deleteDatabase == 'Y')
    {
        remove("database.dat");
        cout << "Database Deleted!" << endl;
    }
    else
        return;

    cin.get();
    data.close();
    cout << "\nPress enter to return ...";
    cin.get();
}