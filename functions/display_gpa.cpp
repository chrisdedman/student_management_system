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
        Function to display all students grade report
***************************************************************/
void display_grades() 
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
  
  cout << "\n\n\t\tDISPLAY All GPAs\n\n" << endl;
  while (getline(database, studentName)) 
  {
    getline(database, studentClasses);
    getline(database, studentGPA);
    getline(database, studentSeparator);
    
    // for(string::iterator itr=studentName.begin();itr!=studentName.end();++itr)
    // cout << *(itr+6);
    
    string::iterator GPA=studentGPA.end();
    cout << setw(25) << left << studentName << setw(4) << right;
    cout << *(GPA-4) << *(GPA-3) << *(GPA-2) << *(GPA-1) << endl;
  }

  database.close();
  cin.ignore();
  cout << "\nPress enter to return ...";
  cin.get();
}