/***************************************************************
        Function to delete single record of file
***************************************************************/
void delete_individual_record()
{
    ifstream data;
    string recordLine;

    data.open("database.dat", ios::in);
    if (!data)
    {
        cout << "No record found!" << endl;
        cin.ignore();
        cin.get();
        return;
    }

    ofstream temporary;
    string student_record;
    string studentClass;
    string studentGPA;
    

    temporary.open("temporary.dat", ofstream::out);

    cin.ignore();
    cout << "Which Student Record do you want to remove?";
    cout << "Name: ";
    getline(cin, student_record);
    student_record = ("Name: " + student_record);
    
    // Need to work on this part. I can delete the first record from the database, 
    // but cannot delete the second or any other one after the first
    while(getline(data, recordLine))
    {
        getline(data, studentClass);
        getline(data, studentGPA);
      
      if (recordLine == student_record)
      {
        while(getline(data, recordLine))
        {
          if (recordLine == "#")
          {
            break;
          }
          else
          {
            temporary << "";
          }
        }
        temporary << "";
      }
      else
      {
        temporary << recordLine << '\n' << studentClass << '\n' << studentGPA << endl;
      }
    }

    temporary.close();
    data.close();
    // rename("temporary.dat", "database.dat");
    cout << "\nPress enter to return ...";
    cin.get();
}