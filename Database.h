#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <ostream>
#include <string>
#include "DynamicArray.h"
#include "Container.h"
#include <stdio.h>
#include <algorithm>
using namespace std;

class Database {
private:
    // Holds strings that name the fields
    DynamicArray<string> field_names; 

    // Indicates what data type each field can hold
    // using constants defined in the public section
    DynamicArray<int> field_types; 

    // This is the database proper
    // Each inner DynamicArray is one *field* (vertical)
    DynamicArray<DynamicArray<Container> > fields;  

    int num_records;
public:
    // Constants for the data types
    const int type_bool = 1;
    const int type_int = 2;
    const int type_double = 3;
    const int type_char = 4;
    const int type_string = 5;

    // Constructors
    // Default constructor
    Database();
    // Parameterized constructor with field names and types
    Database(DynamicArray<string> names, DynamicArray<int> types);

    // Print function
    // Precondition: None
    // Postcondition: Sends a text representation of the
    // Database's contents to the standard output
    void printDatabase();

    // Add a record
    // Precondition: record input has the correct number
    // of fields and they contain the correct data types
    // Postcondition: Info from record is appended to
    // the end of the Database
    void addRecord(DynamicArray<Container> record);

    // Remove a record at the specified index
    // Precondition: Database is not empty
    // Postcondition: The row at the specified index
    // is removed
    void removeRecord(int i);

    // Sorting method
    // Sorts based on the specified field in the Database
    // Precondition: The Database is not empty AND the
    // specified field exists in the Database
    // Postcondition: The Database is sorted based on the
    // specified field from low to high
    void sortByField(Database& db, string fieldName);

    // Searching method
    // Precondition: The Database is not empty AND is sorted 
    // from low to high
    // Postcondition: Returns all rows containing the specified
    // value in the specified field
    DynamicArray<DynamicArray<Container> > searchByField(
        const string& fieldName, Container& value);
};

#endif
