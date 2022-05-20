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

struct StudentInfo
{
    string studentID;
    string studentName;
    string studentClass;
    string studentSeparator;
    double studentGPA;
};
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
        Function to write student in file
***************************************************************/
void write_database()
{
    ofstream data;
    StudentInfo info;

    data.open("database.dat", ios_base::app); // ios_base::app <--- this add data at the end of the opened file
    if (!data)
    {
        cout << "No record found!" << endl;
        cout << "\nPress enter to return ...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "ID #: ";
    cin >> info.studentID;
    data << info.studentID << endl;
    cin.ignore();

    cout << "Name: ";
    getline(cin, info.studentName);
    data << info.studentName << endl;

    cout << "Class: ";
    getline(cin, info.studentClass);
    data << info.studentClass << endl;

    cout << "Overall GPA: ";
    cin >> info.studentGPA;
    data << fixed << setprecision(2) << info.studentGPA << endl;

    // Divider between students
    data << "#" << endl;

    data.close();
}
/***************************************************************
        Function to write multiple students in file
***************************************************************/
void writeMultipleStudent()
{
    int numberOfRecord;
    int count = 0; // Counter for number of multiple record to add into the database
    
    cout << "How many record do you want to add? ";
    cin >> numberOfRecord;

    cout << "\n\n\t\tENTER STUDENT'S DETAILS\n\n"<< endl;
    cout << "\t\t-----------------------\n"<< endl;

    while (count != numberOfRecord)
    {
        write_database();
        count++;
    }
    if (count == 0)
    {
        return;
    }

    cout << "Record Saved... Press any key to continue ...";
    cin.get();
}
/***************************************************************
        Function to retrieve data from the disk
***************************************************************/
vector<StudentInfo> getData()
{
    StudentInfo info;
    vector<StudentInfo> students;
    ifstream database;

    database.open("database.dat", ios_base::in);
    if (!database)
    {
        cout << "No record found!" << endl;
    }

    while (getline(database, info.studentID))
    {
        getline(database, info.studentName);
        getline(database, info.studentClass);
        database >> info.studentGPA;
        database.ignore();
        getline(database, info.studentSeparator);
        students.push_back(info);
    }

    database.close();
    return students;
}
/***************************************************************
        Function to read all records from file
***************************************************************/
void display_menu()
{
    StudentInfo info;
    vector<StudentInfo> students = getData();

    cout << "\n\n\n\t\tDISPLAY ALL RECORD\n";
    cout << "\t\t------------------\n"
         << endl;

    for (int i = 0; i < students.size(); i++)
    {
        cout << setw(9) << left << "ID #: " << students[i].studentID << '\n'
             << setw(9) << left << "Name: " << students[i].studentName << '\n'
             << setw(9) << left << "Class: " << students[i].studentClass << '\n'
             << setw(13) << left << "Overall GPA: " << students[i].studentGPA << '\n'
             << "------------" << endl;
    }

    cin.get();
    cout << "\nPress enter to return ...";
    cin.get();
}
/***************************************************************
        Function to read specific record from file
***************************************************************/
void display_individual()
{
    string theStudent;
    StudentInfo info;
    vector<StudentInfo> students = getData();

    cout << "Who's file would you want to see [Student ID or Student Name]: ";
    cin.ignore();
    getline(cin, theStudent);

    cout << "\n\n\t\tDISPLAY INDIVIDUAL RECORD"
         << endl;
    cout << "\t\t-------------------------\n"
         << endl;

    for (int i = 0; i < students.size();i++)
    {
        if ((theStudent == students[i].studentID) || (theStudent == students[i].studentName))
        {
            cout << setw(9) << left << "ID #: " << students[i].studentID << '\n'
                << setw(9) << left << "Name: " << students[i].studentName << '\n'
                << setw(9) << left << "Classes: " << students[i].studentClass << '\n'
                << setw(13) << left << "Overall GPA: " << students[i].studentGPA << endl;

            cout << "\nPress enter to return ...";
            cin.get();
            return;
        }
    }
    cout << "Record No Found!" << endl;
    cout << "\nPress enter to return ...";
    cin.get();
}
/***************************************************************
        Function to display all students grade report
***************************************************************/
void display_grades()
{
    StudentInfo info;
    vector<StudentInfo> students = getData();

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

    for (int i = 0; i < students.size(); i++)
    {
        studentCounter++;
        if (highestGPA < students[i].studentGPA)
        {
            highestGPA = students[i].studentGPA;
            highestName = students[i].studentName;
        }
        if (lowestGPA > students[i].studentGPA)
        {
            lowestGPA = students[i].studentGPA;
            lowestName = students[i].studentName;
        }

        // print the name and GPA of all students from the database
        cout << setw(25) << left << students[i].studentName << setprecision(2) << fixed << setw(4) << right << students[i].studentGPA << endl;

        // get the sum of all the student's GPA
        sum = sum + students[i].studentGPA;
    }

    // get the average of all student's GPA.
    average = sum / studentCounter;
    cout << "\nAverage / Highest / Lowest\n"
         << "-------   -------   ------" << endl;
    cout << "\nGPAs average: " << average << endl;
    cout << "Highest GPA: " << highestName << " / " << highestGPA << endl;
    cout << "Lowest GPA: " << lowestName << " / " << lowestGPA << endl;

    cin.ignore();
    cout << "\nPress enter to return ...";
    cin.get();
}
/***************************************************************
        Function to delete single record of file
***************************************************************/
void delete_individual_record()
{
    ofstream temporary;
    string student_id;
    vector<StudentInfo> students = getData();

    temporary.open("temporary.dat", ofstream::out);

    cin.ignore();
    cout << "Who's record would you want to remove? [Enter Student ID#]: ";
    getline(cin, student_id);

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].studentID == student_id)
        {
            if (students[i].studentID == students[i].studentSeparator)
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
            temporary << students[i].studentID << '\n'
                      << students[i].studentName << '\n'
                      << students[i].studentClass << '\n'
                      << students[i].studentGPA << '\n'
                      << students[i].studentSeparator << endl;
        }
    }

    temporary.close();
    
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
    // ifstream data;
    char deleteDatabase;

    // data.open("database.dat");
    // if (!data)
    // {
    //     cout << "No record found!" << endl;
    //     cout << "\nPress enter to return ...";
    //     cin.ignore();
    //     cin.get();
    //     return;
    // }
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
    // data.close();
    cout << "\nPress enter to return ...";
    cin.get();
}
/***************************************************************
        Function to modify record of file
***************************************************************/
void modify_individual_record()
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
    StudentInfo info;

    temporary.open("temporary.dat", ofstream::out);

    cin.ignore();
    
    cout << "Who's record would you want to modify? [Enter Student's ID#]: ";
    getline(cin, student_id);

    while (getline(data, info.studentID))
    {
        getline(data, info.studentName);
        getline(data, info.studentClass);
        data >> info.studentGPA;
        data.ignore();
        getline(data, info.studentSeparator);

        if (info.studentID == student_id)
        {
            if (info.studentID == info.studentSeparator)
            {
                break;
            }
            else
            {
                cout << "ID#: ";
                getline(cin, info.studentID);
                temporary << info.studentID << endl;

                cout << "Name: ";
                getline(cin, info.studentName);
                temporary << info.studentName << endl;

                cout << "Class: ";
                getline(cin, info.studentClass);
                temporary << info.studentClass << endl;

                cout << "Overall GPA: ";
                cin >> info.studentGPA;
                temporary << fixed << setprecision(2);
                temporary << info.studentGPA << endl;

                // Divider between students
                temporary << "#" << endl;
            }
        }
        else
        {
            temporary << info.studentID << '\n'
                      << info.studentName << '\n'
                      << info.studentClass << '\n'
                      << info.studentGPA << '\n'
                      << info.studentSeparator << endl;
        }
    }

    temporary.close();
    data.close();
    remove("database.dat");
    rename("temporary.dat", "database.dat");
    if (student_id != info.studentID) cout << student_id << " isn't in the database..." << endl;
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
    string studentID;
    int studentCount = 0;
    vector<StudentInfo> students = getData();

    for(int i = 0; i < students.size(); i++)
    {
        studentCount++;
        if(i == students.size()-1)
        {
            break;
        }
    }

    cout << "\n\n\t\tNUMBER OF STUDENTS" << endl;
    cout << "\t\t------------------\n" << endl;
    if (studentCount < 1) cout << "Currently no record in the database." << endl;
    if (studentCount > 0) cout << "Currently " << studentCount << " student's record in the database." << endl;

    cin.ignore();
    cout << "\nPress enter to return ...";
    cin.get();
}
/**************************************************************
        END OF PROJECT
***************************************************************/