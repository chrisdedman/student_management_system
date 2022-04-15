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
void display_menu();
void delete_database();
void display_grades();
/***************************************************************
        Function navigating between multiple records
***************************************************************/
void multipleRecord()
{
    char selection;
    int option;
    do
    {
        system("clear");
        cout << "\t\t\tProject in progress...\n";
        cout << "====== STUDENT DATABASE MANAGEMENT SYSTEM ======\n"
             << endl;

        cout << "\t\t\t< MULTIPLE RECORDS MENU >\n"
             << "\t\t1. Add Records\n"
             << "\t\t2. List Records\n"
             << "\t\t3. Edit Records\n"
             << "\t\t4. Delete Records\n"
             << "\t\t5. Return\n"
             << "\n\tPlease enter your choice [1-5]\n"
             << endl;
        cin >> selection;
        switch (selection)
        {
        case '1':
            writeMultipleStudent();
            break;
        case '2':
            cout << "\n[1]Display All Record / [2]Display Student GPA" << endl;
            cin >> option;
            if (option == 1) display_menu();
            else if (option == 2) display_grades();
            break;
        case '3':
            break;
        case '4':
            delete_database();
            break;
        case '5':
            main();
        default:
            cout << "Error!";
        }
    } while (selection != 5);
}