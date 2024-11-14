#ifndef CONTAINER_H
#define CONTAINER_H

class Container {
private:
    struct {
        int data_type; // can be queried to indicate which value to access

        // could hold any of these types
        // but if used properly only ONE will get a value
        bool bool_val;
        int int_val;
        double double_val;
        char char_val;
        std::string string_val;
    } data_types;
public:
    // Constructors
    // Default constructor
    Container();
    // You can give a container any data type and it will
    // call the appropriate constructor
    Container(bool b);
    Container(int i);
    Container(double d);
    Container(char c);
    Container(const char* s);

    // "Getters"
    // Precondition: The Container actually holds something
    // Postcondition: Returns the integer corresponding to
    // which data type the Container holds. These integers
    // are defined as constants in Database.h
    int whichType();

    // Precondition: The function you call corresponds to
    // the data type the Container holds
    // Postcondition: Returns the value held in the Container
    bool boolVal();
    int intVal();
    double doubleVal();
    char charVal();
    std::string stringVal();

    // Print function
    // Precondition: None
    // Postcondition: Sends a text representation of the
    // Container's contents to the standard output
    void print();

    /*
    * The following are all overloads of various
    * comparison operators to allow any searching and
    * sorting algorithm to driectly compare Containers
    */

    // Overload == operator
    bool operator == (Container& cont);

    // Overload < operator
    bool operator < (Container& cont);

    // Overload > operator
    bool operator > (Container& cont);

    // Overload <= operator
    bool operator <= (Container& cont);

    // Overload >= operator
    bool operator >= (Container& cont);

    // Overload <<
    // Code from:
    // https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
    friend std::ostream& operator<<(std::ostream& os, const Container& cont);
};

std::ostream& operator<<(std::ostream& os, const Container& cont);

#endif