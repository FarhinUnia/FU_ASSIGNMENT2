#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Create a structure to store student information
struct STUDENT_DATA
{
    string firstName;
    string lastName;
};

int main()
{
    // Open the StudentData.txt file
    ifstream inputFile("StudentData.txt");

    // Check if the file opened successfully
    if (!inputFile)
    {
        cout << "Error opening StudentData.txt" << endl;
        return 1;
    }

    // Create a vector to store all students
    vector<STUDENT_DATA> students;

    string line;

    // Read the file one line at a time
    while (getline(inputFile, line))
    {
        // Create a string stream from the line
        stringstream studentStream(line);

        string firstName;
        string lastName;

        // Get the first name before the comma
        getline(studentStream, firstName, ',');

        // Get the last name after the comma
        getline(studentStream, lastName);

        // Create a student object
        STUDENT_DATA student;

        student.firstName = firstName;
        student.lastName = lastName;

        // Add the student to the vector
        students.push_back(student);
    }

    // Close the file
    inputFile.close();

    cout << "Students loaded successfully." << endl;
    cout << "Number of students: " << students.size() << endl;

    return 0;
}
