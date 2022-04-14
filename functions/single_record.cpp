/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
//***************************************************************
//    	Function declaration
//**************************************************************/
int main();
void delete_individual_record();
/***************************************************************
        Function navigating between single records
***************************************************************/
void singleRecord()
{
  char selection;
  do{
    system("clear");
    cout << "\t\t\tProject in progress...\n";
    cout << "====== STUDENT DATABASE MANAGEMENT SYSTEM ======\n" << endl;
  
    cout << "\t\t\t< SINGLE RECORD MENU >\n"
         << "\t\t1. Add a Student\n"
         << "\t\t2. Find a Student\n"
         << "\t\t3. Edit a Student File\n"
         << "\t\t4. Delete a Student File\n"
         << "\t\t5. Return\n"
         << "\n\tPlease enter your choice [1-5]\n"
         << endl;
    cin >> selection;
    switch (selection) 
    {
        case '1':
                  write_database(); 
                  break;
        case '2':
                  display_individual();
                  break;
        case '3':
                  break;
        case '4':
                  delete_individual_record();
                  break;
        case '5':
                  main();
        default:
                  cout << "Error!";
    }
  } while (selection != 5);
}