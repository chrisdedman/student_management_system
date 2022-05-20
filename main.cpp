/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <iostream>
#include "record.h"
using namespace std;
/***************************************************************
         THE MAIN FUNCTION OF THE PROGRAM
***************************************************************/
int main()
{
    char choice;
    bool run = true;

    do
    {
        cout << "\033[2J\033[1;1H"; // Clear the screen
        cout << "====== STUDENT DATABASE MANAGEMENT SYSTEM ======\n"
             << endl;

        cout << "\t\t\t< MAIN MENU >\n"
             << "\t\t1. Multiple Records\n"
             << "\t\t2. Single Record\n"
             << "\t\t3. Total Record\n"
             << "\t\t4. Exit\n"
             << "\n\tPlease enter your choice [1-4]\n"
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
            countStudent();
            break;
        case '4':
            run = false;
            break;
        default:
            cout << "Error!";
        }
    } while (run == true);
    
    return 0;
}
