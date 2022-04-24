/***************************************************************
      HEADER FILE USED IN THE PROJECT
***************************************************************/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
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
            exit(1);
        default : cout << "Error!";
        }
    } while (true);
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
        cout << "====== STUDENT DATABASE MANAGEMENT SYSTEM ======\n"
             << endl;

        cout << "\t\t\t< MULTIPLE RECORDS MENU >\n"
             << "\t\t1. Add Records\n"
             << "\t\t2. List Records\n"
             << "\t\t3. Delete Records\n"
             << "\t\t4. Return\n"
             << "\n\tPlease enter your choice [1-4]\n"
             << endl;
        cin >> selection;
        switch (selection)
        {
        case '1':
            writeMultipleStudent();
            break;
        case '2':
            cout << "\n\t[1]Display All Record /\n\t[2]Display Student GPA" << endl;
            cin >> option;
            if (option == 1)
                display_menu();
            else if (option == 2)
                display_grades();
            break;
        case '3':
            delete_database();
            break;
        case '4':
            startProgram();
        default : cout << "Error!";
        }
    } while (true);
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
            modify_individual_record();
            break;
        case '4':
            delete_individual_record();
            break;
        case '5':
            startProgram();
        default:
            cout << "Error!";
        }
    } while (true);
}
/***************************************************************
        Function to write a single student in file
***************************************************************/
void write_database()
{
    ofstream data;
    int id;
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
    cout << "\t\t-----------------------\n"
         << endl;

    cout << "ID #: ";
    cin >> id;
    data << id << endl;
    cin.ignore();

    cout << "Name: ";
    getline(cin, student_record);
    data << student_record << endl;

    cout << "Class: ";
    getline(cin, studentClass);
    data << studentClass << endl;

    cout << "Overall GPA: ";
    cin >> studentGPA;
    data << fixed << setprecision(2);
    data << studentGPA << endl;

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
    int id;
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

    cout << "\n\n\t\tENTER STUDENT'S DETAILS\n\n"<< endl;
    cout << "\t\t-----------------------\n"<< endl;

    while (count != numberOfRecord)
    {
        cout << "ID #: ";
        cin >> id;
        data << id << endl;
        cin.ignore();

        cout << "Name: ";
        getline(cin, student_record);
        data << student_record << endl;

        cout << "Class: ";
        getline(cin, studentClass);
        data << studentClass << endl;

        cout << "Overall GPA: ";
        cin >> studentGPA;
        data << fixed << setprecision(2);
        data << studentGPA << endl;
        count++;

        // Divider between students
        data << "#" << endl;
        cin.ignore();
        cout << endl;
    }
    if (count == 0)
    {
        return;
    }

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

    vector<string> vstudentID;
    vector<string> vstudentName;
    vector<string> vstudentClasses;
    vector<string> vstudentGPA;

    database.open("database.dat", ios_base::in);
    if (!database)
    {
        cout << "No record found!" << endl;
        cout << "\nPress enter to return ...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "\n\n\n\t\tDISPLAY ALL RECORD\n";
    cout << "\t\t------------------\n"
         << endl;

    while (getline(database, studentID))
    {
        vstudentID.push_back(studentID);
        getline(database, studentName);
        vstudentName.push_back(studentName);
        getline(database, studentClasses);
        vstudentClasses.push_back(studentClasses);
        getline(database, studentGPA);
        vstudentGPA.push_back(studentGPA);
        getline(database, studentSeparator);
    }

    for (int i = 0; i < vstudentID.size();i++)
    {
        cout << setw(9) << left << "ID #: " << vstudentID[i] << '\n'
             << setw(9) << left << "Name: " << vstudentName[i] << '\n'
             << setw(9) << left << "Class: " << vstudentClasses[i] << '\n'
             << setw(13) << left << "Overall GPA: " << vstudentGPA[i] << '\n'
             << "------------" << endl;
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

    vector<string> vstudentID;
    vector<string> vstudentName;
    vector<string> vstudentClasses;
    vector<string> vstudentGPA;

    database.open("database.dat", ios_base::in);
    if (!database)
    {
        cout << "No record found!" << endl;
        cout << "\nPress enter to return ...";
        cin.ignore();
        cin.get();
        return;
    }

    while (getline(database, studentID))
    {
        vstudentID.push_back(studentID);
        getline(database, studentName);
        vstudentName.push_back(studentName);
        getline(database, studentClasses);
        vstudentClasses.push_back(studentClasses);
        getline(database, studentGPA);
        vstudentGPA.push_back(studentGPA);
        getline(database, studentSeparator);
    }
    database.close();

    cout << "Who's file would you want to see [Student ID or Student Name]: ";
    cin.ignore();
    getline(cin, theStudent);

    cout << "\n\n\t\tDISPLAY INDIVIDUAL RECORD"
         << endl;
    cout << "\t\t-------------------------\n"
         << endl;

    for (int i = 0; i < vstudentID.size();i++)
    {
        if (theStudent == vstudentID[i])
        {
            cout << setw(9) << left << "ID #: " << vstudentID[i] << '\n'
                << setw(9) << left << "Name: " << vstudentName[i] << '\n'
                << setw(9) << left << "Classes: " << vstudentClasses[i] << '\n'
                << setw(13) << left << "Overall GPA: " << vstudentGPA[i] << endl;

            cout << "\nPress enter to return ...";
            cin.get();
            return;
        }
        if (theStudent == vstudentName[i])
        {
            cout << setw(9) << left << "ID #: " << vstudentID[i] << '\n'
                 << setw(9) << left << "Name: " << vstudentName[i] << '\n'
                 << setw(9) << left << "Classes: " << vstudentClasses[i] << '\n'
                 << setw(13) << left << "Overall GPA: " << vstudentGPA[i] << endl;

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

    cout << "\n\n\t\tDISPLAY All GPAs"
         << endl;
    cout << "\t\t----------------\n"
         << endl;

    cout << setw(25) << left << "Name" << setw(4) << left << "GPA" << endl;
    cout << setw(25) << left << "----" << setw(4) << left << "---" << endl;

    while (getline(database, studentID))
    {
        double convertedGPA;
        getline(database, studentName);
        getline(database, studentClasses);
        getline(database, studentGPA);
        getline(database, studentSeparator);
        studentCounter++;
        
        // convert the GPA string into double.
        convertedGPA = atof(studentGPA.c_str());
        if (highestGPA < convertedGPA) 
        {
            highestGPA = double(convertedGPA);
            highestName = studentName;
        }
        if (lowestGPA > convertedGPA) 
        {
            lowestGPA = double(convertedGPA);
            lowestName = studentName;
        }

        // print the name and GPA of all students from the database
        cout << setw(25) << left << studentName << setprecision(2) << fixed << setw(4) << right << convertedGPA << endl;

        // get the sum of all the student's GPA
        sum = sum + convertedGPA;

    }

    // get the average of all student's GPA.
    average = sum / studentCounter;
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
    string student_id;
    string studentID;
    string studentName;
    string studentClass;
    string studentGPA;
    string studentSeparator;

    temporary.open("temporary.dat", ofstream::out);

    cin.ignore();
    cout << "Who's record would you want to remove? [Enter Student ID#]: ";
    getline(cin, student_id);
    
    while (getline(data, studentID))
    {
        getline(data, studentName);
        getline(data, studentClass);
        getline(data, studentGPA);
        getline(data, studentSeparator);

        if (studentID == student_id)
        {
            if (studentID == studentSeparator)
            {
                break;
            }
            else
            {
                temporary << "";
            }

            cout << "Record ID# " << student_id << " Deleted !" << endl;
        }
        else
        {
            temporary << studentID << '\n'
                      << studentName << '\n'
                      << studentClass << '\n'
                      << studentGPA << '\n'
                      << studentSeparator << endl;
        }
    }

    temporary.close();
    data.close();
    remove("database.dat");
    rename("temporary.dat", "database.dat");

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
void modify_individual_record()
{
    ifstream data;
    string studentID;

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
    string studentName;
    string student_id;
    string studentClass;
    string studentGPA;
    string studentSeparator;

    temporary.open("temporary.dat", ofstream::out);

    cin.ignore();
    
    cout << "Who's record would you want to modify? [Enter Student's ID#]: ";
    getline(cin, student_id);

    while (getline(data, studentID))
    {
        getline(data, studentName);
        getline(data, studentClass);
        getline(data, studentGPA);
        getline(data, studentSeparator);

        if (studentID == student_id)
        {
            if (studentID == studentSeparator)
            {
                break;
            }
            else
            {
                cout << "ID#: ";
                getline(cin, studentID);
                temporary << studentID << endl;

                cout << "Name: ";
                getline(cin, studentName);
                temporary << studentName << endl;

                cout << "Class: ";
                getline(cin, studentClass);
                temporary << studentClass << endl;

                cout << "Overall GPA: ";
                cin >> studentGPA;
                temporary << fixed << setprecision(2);
                temporary << studentGPA << endl;

                // Divider between students
                temporary << "#" << endl;
            }
        }
        else
        {
            temporary << studentID << '\n'
                      << studentName << '\n'
                      << studentClass << '\n'
                      << studentGPA << '\n'
                      << studentSeparator << endl;
        }
    }

    temporary.close();
    data.close();
    remove("database.dat");
    rename("temporary.dat", "database.dat");
    if (student_id != studentID) cout << student_id << " isn't in the database..." << endl;
    else
    {
        cout << student_id << " Record Edited!" << endl;
    }
    cout << "\nPress enter to return...";
    cin.get();
}
/***************************************************************
        Function that count number of students
***************************************************************/
void countStudent()
{
    ifstream database;
    string studentID;
    string studentName;
    string studentClasses;
    string studentGPA;
    string studentSeparator;
    int studentCount = 0;

    database.open("database.dat", ios_base::in);
    if (!database)
    {
        cout << "No record found!" << endl;
        cout << "\nPress enter to return ...";
        cin.ignore();
        cin.get();
        return;
    }

    while (getline(database, studentID))
    {
        getline(database, studentName);
        getline(database, studentClasses);
        getline(database, studentGPA);
        getline(database, studentSeparator);
        studentCount++;
    }

    cout << "\n\n\t\tNUMBER OF STUDENTS" << endl;
    cout << "\t\t------------------\n" << endl;
    if (studentCount < 1) cout << "Currently no record in the database." << endl;
    if (studentCount == 1) cout << "Currently " << studentCount << " student's record is in the database." << endl;
    if (studentCount > 1) cout << "Currently " << studentCount << " student's record are in the database." << endl;

    database.close();
    cin.ignore();
    cout << "\nPress enter to return ...";
    cin.get();
}
/**************************************************************
        END OF PROJECT
***************************************************************/