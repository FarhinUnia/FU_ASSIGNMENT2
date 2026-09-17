#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Define the PRE_RELEASE compiler directive to enable pre-release functionality.
// Remove or comment out this line when running the standard version.
#define PRE_RELEASE

using namespace std;

// Create a structure to store student information
struct STUDENT_DATA
{
    string firstName;
    string lastName;

#ifdef PRE_RELEASE

    // Email information is only included in the Pre-Release version.
    string email;

#endif
};

int main()
{
#ifdef PRE_RELEASE
    cout << "Running Pre-Release version" << endl << endl;

    // Open the file containing student names and email addresses.
	ifstream inputFile("StudentData_Emails.txt");
#else

    cout << "Running Standard version" << endl << endl;

    // Open the file containing student names.
    ifstream inputFile("StudentData.txt");
#endif

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

     #ifdef PRE_RELEASE

        // Read and store the student's email address.
        // This functionality is only available in the Pre-Release version.
        getline(studentStream, student.email);
     #endif

        // Add the student to the vector
        students.push_back(student);
    }

 // Display student information when the program is compiled in Debug mode.
#ifdef _DEBUG

    for (const STUDENT_DATA& student : students)
    {
        cout << student.firstName << " " << student.lastName;


 // Display the email address in the Pre-Release version.
#ifdef PRE_RELEASE
        cout << " " << "," << student.email;
#endif
            
        cout<< endl;
    }

#endif

    // Close the file after all student records have been processed.
    inputFile.close();



    return 0;
}
