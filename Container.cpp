#include <string>
#include <iostream>
#include "Container.h"
using namespace std;

// Constructors
// Default constructor
Container::Container() {
    ;
}
// Parameterized constructors
Container::Container(bool b) {
    data_types.data_type = 1; 
    data_types.bool_val = b;
}
Container::Container(int i) {
    data_types.data_type = 2; 
    data_types.int_val = i;
}
Container::Container(double d) {
    data_types.data_type = 3; 
    data_types.double_val = d;
}
Container::Container(char c) {
    data_types.data_type = 4; 
    data_types.char_val = c;
}
Container::Container(const char* s) {
    data_types.data_type = 5; 
    data_types.string_val = s;
}

// "Getters"
int Container::whichType() {
    return data_types.data_type;
}

bool Container::boolVal() {
    return  data_types.bool_val;
}
int Container::intVal() {
    return data_types.int_val;
}
double Container::doubleVal() {
    return data_types.double_val;
}
char Container::charVal() {
    return data_types.char_val;
}
std::string Container::stringVal() {
    return data_types.string_val;
}

// Print function
void Container::print() {
    switch (data_types.data_type) {
    case 1:
        if (data_types.bool_val) {
            std::cout << "True";
        } else {
            std::cout << "False";
        }
        break;
    case 2:
        std::cout << data_types.int_val;
        break;
    case 3:
        std::cout << data_types.double_val;
        break;
    case 4:
        std::cout << data_types.char_val;
        break;
    case 5:
        std::cout << data_types.string_val;
        break;
    }
}

// Overload == operator
bool Container::operator == (Container& cont) {
    switch (this->whichType()) {
    case 0:
        return true;
    case 1:
        if (this->boolVal() != cont.boolVal()) {
            return false;
        }
        return true;
    case 2:
        if (this->intVal() != cont.intVal()) {
            return false;
        }
        return true;
    case 3:
        if (this->doubleVal() != cont.doubleVal()) {
            return false;
        }
        return true;
    case 4:
        if (this->charVal() != cont.charVal()) {
            return false;
        }
        return true;
    case 5:
        if (this->stringVal() != cont.stringVal()) {
            return false;
        }
        return true;
    default:
        return false;
    }
}

// Overload < operator
bool Container::operator < (Container& cont) {
    switch (this->whichType()) {
    case 0:
        return false;
    case 1:
        return (this->boolVal() < cont.boolVal());
    case 2:
        return (this->intVal() < cont.intVal());
    case 3:
        return (this->doubleVal() < cont.doubleVal());
    case 4:
        return (this->charVal() < cont.charVal());
    case 5:
        if (this->stringVal().compare(cont.stringVal()) < 0) {
            return true;
        }
        return false;
    default:
        return false;
    }
}

// Overload > operator
bool Container::operator > (Container& cont) {
    switch (this->whichType()) {
    case 0:
        return false;
    case 1:
        return (this->boolVal() > cont.boolVal());
    case 2:
        return (this->intVal() > cont.intVal());
    case 3:
        return (this->doubleVal() > cont.doubleVal());
    case 4:
        return (this->charVal() > cont.charVal());
    case 5:
        if (this->stringVal().compare(cont.stringVal()) > 0) {
            return true;
        }
        return false;
    default:
        return false;
    }
}

// Overload <= operator
bool Container::operator <= (Container& cont) {
    if (this > &cont) {
        return false;
    }
    return true;
}

// Overload >= operator
bool Container::operator >= (Container& cont) {
    if (this < &cont) {
        return false;
    }
    return true;
}

// Overload <<
// Code from:
// https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
std::ostream& operator<<(std::ostream& os, const Container& cont)
{
    switch(cont.data_types.data_type){
        case 1:
            if (cont.data_types.bool_val) {
                os << "True";
            } else {
                os << "False";
            }
            break;
        case 2:
            os << cont.data_types.int_val;
            break;
        case 3:
            os << cont.data_types.double_val;
            break;
        case 4:
            os << cont.data_types.char_val;
            break;
        case 5:
            os << cont.data_types.string_val;
            break;
    } 
    return os;
}