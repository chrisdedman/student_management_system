/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
/***************************************************************
        Function to delete single record of file
***************************************************************/
void delete_individual_record()
{
    ifstream data;
    string recordLine;

    data.open("database.dat", ios_base::in);
    if (!data)
    {
        cout << "No record found!" << endl;
        cout << "\nPress enter to return ...";
        cin.ignore();
        cin.get();
        return;
    }

    ofstream temporary;
    string student_record;
    string studentClass;
    string studentGPA;
    string studentSeparator;
    
    temporary.open("temporary.dat", ofstream::out);

    cin.ignore();
    string student_name;
    cout << "Who's record would you want to remove? [Enter Student's Name]\n[CASE SENSITIVE]: ";
    getline(cin, student_name);
    student_record = ("Name: " + student_name);
    
    while(getline(data, recordLine))
    {
        getline(data, studentClass);
        getline(data, studentGPA);
        getline(data, studentSeparator);
      
      if (recordLine == student_record)
      {
        if (recordLine == studentSeparator)
        {
          break;
        }
        else
        {
          temporary << "";
        }
      }
      else
      {
        temporary << recordLine << '\n' << studentClass << '\n' << studentGPA << '\n' << studentSeparator << endl;
      }
		}

    temporary.close();
    data.close();
    remove("database.dat");
    rename("temporary.dat", "database.dat");
    cout << student_name << " Record Deleted!" << endl;
    cout << "\nPress enter to return ...";
    cin.get();
}