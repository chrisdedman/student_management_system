/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "record.h"
using namespace std;
/***************************************************************
        Function that start the program
***************************************************************/
void startProgram()
{
    char choice;

    do
    {
        cout << "\033[2J\033[1;1H"; // Clear the screen
        cout << "\t\t\tProject in progress...\n";
        cout << "====== STUDENT DATABASE MANAGEMENT SYSTEM ======\n"
             << endl;

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
}
/***************************************************************
        Function navigating between multiple records
***************************************************************/
void multipleRecord()
{
    char selection;
    int option;
    do
    {
        cout << "\033[2J\033[1;1H"; // Clear the screen
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
            cout << "\n\t[1]Display All Record / [2]Display Student GPA" << endl;
            cin >> option;
            if (option == 1)
                display_menu();
            else if (option == 2)
                display_grades();
            break;
        case '3':
            break;
        case '4':
            delete_database();
            break;
        case '5':
            startProgram();
        default : cout << "Error!";
        }
    } while (selection != 5);
}
/***************************************************************
        Function navigating between single records
***************************************************************/
void singleRecord()
{
    char selection;
    do
    {
        cout << "\033[2J\033[1;1H"; // Clear the screen
        cout << "\t\t\tProject in progress...\n";
        cout << "====== STUDENT DATABASE MANAGEMENT SYSTEM ======\n"
             << endl;

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
            startProgram();
        default:
            cout << "Error!";
        }
    } while (selection != 5);
}
/***************************************************************
        Function to write a single student in file
***************************************************************/
void write_database()
{
    ofstream data;
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

    cin.ignore();

    cout << "\n\n\t\tENTER STUDENT'S DETAILS\n\n"
         << endl;

    cout << "Name: ";
    getline(cin, student_record);
    data << setw(7) << left << "Name: " << student_record << endl;

    cout << "Class: ";
    getline(cin, studentClass);
    data << setw(7) << left << "Class: " << studentClass << endl;

    cout << "Overall GPA: ";
    cin >> studentGPA;
    data << fixed << setprecision(2);
    data << setw(7) << left << "GPA: " << studentGPA << endl;

    // Divider between students
    data << "#" << endl;

    data.close();
    cout << "Record Saved... Press any key to continue ...";
    cin.get();
}
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
        data << setw(7) << left << "Name: " << student_record << endl;

        cout << "Class: ";
        getline(cin, studentClass);
        data << setw(7) << left << "Class: " << studentClass << endl;

        cout << "Overall GPA: ";
        cin >> studentGPA;
        data << fixed << setprecision(2);
        data << setw(7) << left << "GPA: " << studentGPA << endl;
        count++;

        // Divider between students
        data << "#" << endl;
        cin.ignore();
        cout << endl;

    } while (count != numberOfRecord);

    data.close();
    cout << "Record Saved... Press any key to continue ...";
    cin.get();
}
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
    string studentSeparator;

    database.open("database.dat", ios_base::in);
    if (!database)
    {
        cout << "No record found!" << endl;
        cout << "\nPress enter to return ...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "\n\n\n\t\tDISPLAY ALL RECORD\n\n";

    while (getline(database, studentName))
    {
        getline(database, studentClasses);
        getline(database, studentGPA);
        getline(database, studentSeparator);
        cout << studentName << '\n'
             << studentClasses << '\n'
             << studentGPA << '\n'
             << "" << endl;
    }

    cin.get();
    database.close();
    cout << "\nPress enter to return ...";
    cin.get();
}
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

    studentID = "Name:  " + theStudent;
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

    // Variable Declaration
    double sum, average;
    double highestGPA = 0.00, lowestGPA = 5.00;
    string highestName, lowestName;
    int studentCounter = 0;

    cout << "\n\n\t\tDISPLAY All GPAs\n\n"
         << endl;

    cout << setw(25) << left << "Name" << setw(4) << left << "GPA" << endl;
    cout << setw(25) << left << "----" << setw(4) << left << "---" << endl;

    while (getline(database, studentName))
    {
        string recordName;
        string stringGPA;
        double convertedGPA;

        getline(database, studentClasses);
        getline(database, studentGPA);
        getline(database, studentSeparator);
        studentCounter++;

        // retrieve only Names, and GPAs from the database.
        recordName.append(studentName, 7);
        stringGPA.append(studentGPA, 7);
        
        // convert the GPA string into double.
        convertedGPA = atof(stringGPA.c_str());
        if (highestGPA < convertedGPA) 
        {
            highestGPA = double(convertedGPA);
            highestName = recordName;
        }
        if (lowestGPA > convertedGPA) 
        {
            lowestGPA = double(convertedGPA);
            lowestName = recordName;
        }

        // print the name and GPA of all students from the database
        cout << setw(25) << left << recordName << setprecision(2) << fixed << setw(4) << right << convertedGPA << endl;

        // get the sum of all the student's GPA
        sum = sum + convertedGPA;

    }

    // get the average of all student's GPA.
    average = sum / counter;
    cout << "\nAverage / Highest / Lowest\n"
         << "-------   -------   ------" << endl;
    cout << "\nGPAs average: " << average << endl;
    cout << "Highest GPA: " << highestName << " / " << highestGPA << endl;
    cout << "Lowest GPA: " << lowestName << " / " << lowestGPA << endl;

    database.close();
    cin.ignore();
    cout << "\nPress enter to return ...";
    cin.get();
}
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
    student_record = ("Name:  " + student_name);

    while (getline(data, recordLine))
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
            temporary << recordLine << '\n'
                      << studentClass << '\n'
                      << studentGPA << '\n'
                      << studentSeparator << endl;
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
        cout << "\nPress enter to return ...";
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
/***************************************************************
        Function to modify record of file
***************************************************************/

/***************************************************************
        END OF PROJECT
***************************************************************/