#include <iostream>
#include <ostream>
#include <string>
#include "DynamicArray.h"
#include "Database.h"
#include "Container.h"
#include <stdio.h>
#include <algorithm>
using namespace std;

// Constructors
// Default constructor
Database::Database() {
    ;
}
// Parameterized constructor
Database::Database(DynamicArray<string> names, DynamicArray<int> types) {
    // If you pass an unequal number of names/types, throw exception
    if (names.getSize() != types.getSize()) {
            throw "names and types size mismatch";
        }
    field_names = names;
    field_types = types;
    // Adds the fields (columns)
    for (int i = 0; i < types.getSize(); i++) {
        fields.pushBack(DynamicArray<Container>());
    }
}

// Print function
void Database::printDatabase() {

    for (int i = 0; i < fields.getSize(); i++) {

        string type;
        switch (field_types.searchByIndex(i)) {
        case 1:
            type = "Bool";
            break;
        case 2:
            type = "Integer";
            break;
        case 3:
            type = "Double";
            break;
        case 4:
            type = "Character";
            break;
        case 5:
            type = "String";
            break;
        }
        
        cout << "Name: " << field_names.searchByIndex(i) << " " << "Type: " << type << " (" << field_types.searchByIndex(i) << ") " << endl;
        
        fields.searchByIndex(i).printArrayDetails();
    }
}

// Add a record
void Database::addRecord(DynamicArray<Container> record) {
    // record argument contains multiple data types, it is a row on the table
    // it gets distributed into the field columns

    // check that each data is of the correct type *before* storing anything
    for (int i = 0; i < record.getSize(); i++) {
        if (record.searchByIndex(i).whichType() != field_types.searchByIndex(i)) {
            throw i;
        } // throws the index of the field where the mismatch is
    }

    // store the data
    for (int i = 0; i < record.getSize(); i++) {

        fields.searchByIndex(i).pushBack(record.searchByIndex(i));
    }
    num_records++;
}

// Remove a record at the specified index
void Database::removeRecord(int i) {
    
    for (int j = 0; j < fields.getSize(); j++) {
        fields.searchByIndex(j).deleteAt(i);
        }
    num_records--;
}


// Sorting method
// Sorts based on the specified field in the Database
void Database::sortByField(Database& db, string fieldName) {
    // Find the index of the specified field
    int fieldIndex = -1;
    for (int i = 0; i < db.field_names.getSize(); ++i) {
        if (db.field_names.searchByIndex(i) == fieldName) {
            fieldIndex = i;
            break;
        }
    }

    // If the field doesn't exist, return
    if (fieldIndex == -1) {
        cout << "Field not found." << endl;
        return;
    }

    // Selection sort based on the field
    int numRecords = db.fields.searchByIndex(fieldIndex).getSize();
    for (int i = 0; i < numRecords - 1; ++i) {
        // Find the index of the minimum value from i to numRecords - 1
        int minIndex = i;
        for (int j = i + 1; j < numRecords; ++j) {
            // Retrieve values from the specified field
            Container currentValue = db.fields.searchByIndex(fieldIndex).searchByIndex(j);
            Container minValue = db.fields.searchByIndex(fieldIndex).searchByIndex(minIndex);

            // Compare values based on data type
            if (currentValue.whichType() == db.type_int && minValue.whichType() == db.type_int) {
                if (currentValue.intVal() < minValue.intVal()) {
                    minIndex = j;
                }
            } else if (currentValue.whichType() == db.type_bool && minValue.whichType() == db.type_bool) {
                if (currentValue.boolVal() < minValue.boolVal()) {
                    minIndex = j;
                }
            } else if (currentValue.whichType() == db.type_string && minValue.whichType() == db.type_string) {
                if (currentValue.stringVal() < minValue.stringVal()) {
                    minIndex = j;
                }
            }
            else if (currentValue.whichType() == db.type_double && minValue.whichType() == db.type_double) {
                if (currentValue.doubleVal() < minValue.doubleVal()) {
                    minIndex = j;
                }
            }
            else if (currentValue.whichType() == db.type_char && minValue.whichType() == db.type_char) {
                if (currentValue.charVal() < minValue.charVal()) {
                    minIndex = j;
                }
            }
        }
        // Swap records
        if (minIndex != i) {
            for (int k = 0; k < db.fields.getSize(); ++k) {
                // Swap records in each field
                Container temp = db.fields.searchByIndex(k).searchByIndex(i);
                db.fields.searchByIndex(k).searchByIndex(i) = db.fields.searchByIndex(k).searchByIndex(minIndex);
                db.fields.searchByIndex(k).searchByIndex(minIndex) = temp;
            }
        }
    }
}

// Searching method
DynamicArray<DynamicArray<Container> > Database::searchByField(
    const string& fieldName, Container& value) {
// Find the index of the specified field
    int fieldIndex = -1;
    for (int i = 0; i < field_names.getSize(); ++i) {
        if (field_names.searchByIndex(i) == fieldName) {
            fieldIndex = i;
            break;
        }
    }

// If the field doesn't exist, return an empty result
    if (fieldIndex == -1) {
        cout << "Field not found." << endl;
        return DynamicArray<DynamicArray<Container> >();
     }

// Search for records with the specified value in the specified field
DynamicArray<DynamicArray<Container> > result;
    for (int i = 0; i < fields.searchByIndex(fieldIndex).getSize(); ++i) {
        Container fieldValue = fields.searchByIndex(fieldIndex).searchByIndex(i);
        // Compare values based on data type
        if (fieldValue == value) {
            // If the value matches, add the corresponding record to the result
            DynamicArray<Container> record;
            for (int j = 0; j < fields.getSize(); ++j) {
                record.pushBack(fields.searchByIndex(j).searchByIndex(i));
            }
        result.pushBack(record);
        }
    }
    return result;
}