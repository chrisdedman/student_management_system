/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "functions/single_student.cpp"
#include "functions/multiple_student.cpp"
#include "functions/multiple_record.cpp"
#include "functions/display_menu.cpp"
#include "functions/display_individual.cpp"
#include "functions/delete_database.cpp"
#include "functions/single_record.cpp"
#include "functions/delete_individual_record.cpp"
using namespace std;
//***************************************************************
//    	Function declaration
//****************************************************************
void multipleRecord();
void writeMultipleStudent();
void write_database();
void display_menu();
void display_individual();
void delete_database();
void singleRecord();
void editRecord();
void delete_individual_record();
/***************************************************************
         THE MAIN FUNCTION OF THE PROGRAM
***************************************************************/
int main()
{
  char choice;

  do {
    system("clear");
    cout << "\t\t\tProject in progress...\n";
    cout << "====== STUDENT DATABASE MANAGEMENT SYSTEM ======\n" << endl;

    cout << "\t\t\t< MAIN MENU >\n"
         << "\t\t1. Multiple Records\n"
         << "\t\t2. Single Record\n"
         << "\t\t3. Exit\n"
         << "\n\tPlease enter your choice [1-3]\n"
         << endl;
    cin >> choice;

    switch (choice) 
    {
        case '1':
                  multipleRecord();
                  break;
        case '2':
                  singleRecord();
                  break;
        case '3':
                  exit(1);
        default:
                  cout << "Error!";
    }
  } while (choice != 3);

  return 0;
}
/***************************************************************
        Function to modify record of file
***************************************************************/

/***************************************************************
        Function to display all students grade report
***************************************************************/

/***************************************************************
        END OF PROJECT
***************************************************************/
// Made by Chris and Zac
