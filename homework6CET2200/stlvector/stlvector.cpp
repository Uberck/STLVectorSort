//--------------------------------------------------------------------
// STL List Exercise
// file: main.cpp
//
// Reads a list of student names, sorts the list according to a key, and
// prints the sorted list.
//
//	Modified by: Alex Clarke -- November 5, 2014
//  Modified by: Catherine Song -- October 30, 2015
//  Modified by: Christos Kokkalis -- June 27th, 2020
//--------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

struct DataType
{
	string lastname;	// Student's Last Name
	string firstname;	// Student's First Name

	string getKey() const
	{
		return lastname;
	}   // Returns the key field
};

//---------Need to add code to overload operator <<
void operator << (ostream& out, struct DataType student) {
	cout << student.firstname << " " << student.lastname;
}


//------- Need to add code to fix error C2784: 'bool __cdecl std::operator <

bool operator < (DataType lhs, DataType rhs)
{
	return lhs.getKey() < rhs.getKey();
}

void showStudentList(list<DataType>stuList)
{
	list<DataType>::iterator itr;
	for (itr = stuList.begin(); itr != stuList.end(); itr++)
	{
		cout << "\n" << *itr; //this calls the overloaded << operator
	}
	cout << "\n";
}

int main()

{
	ifstream studentFile("input.txt");  // Student file
	list <DataType> students;            // Students
	DataType currStudent;              // One Student (has firstname,lastname)

	// Read each line from input.txt:
	//Store the firstname and the lastname into 
	//the temporary student structure "currStudent".

	while (studentFile >> currStudent.firstname >> currStudent.lastname)

	// Push the current student into the list ("students")

	{
		students.push_back(currStudent);
	}

	// Use an iterator to print the unsorted list of students.

	showStudentList(students);

	// Sort the list of students.

	students.sort();
	cout << "\nSorting by last name...\n";

	// Use an iterator to print the sorted list of students.

	showStudentList(students);

	return 0;
}
