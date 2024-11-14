#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <string>
#include "Container.h"

template <class T>

class DynamicArray {
private:
    
    // Pointer to store array created
    // using new keyword
    T* array = NULL;
    
    // Container size
    int capacity;

public:
    // Size of array
    int size;
    
    // Default constructor with size 1
    DynamicArray()
    {
        capacity = 1;
        size = 0;
        array = new T[capacity];
    }

    // Taking size from the user
    DynamicArray(int capacity)
    {
        this->capacity = capacity;
        array = new T[capacity];
        size = 0;
    }

    // Returns the size of Array
    // i.e Total elements stored currently
    int getSize() { return size; }

    // Returns the size of container
    int getCapacity() { return capacity; }

    // Inserting element after last stored index
    void pushBack(T value)
    {
        // check is array having size to store element or
        // not
        if (size == capacity) {

            // if not then grow the array by double
            growArray();
        }

        // insert element
        array[size] = value;
        // increment the size or last_index+1
        size++;
    }

    // Deleting element at last stored index
    void popBack(int value)
    {
        // Replace the input index by 0
        array[value] = '0';

        // Decrement the array size
        size--;

        // Reduce if the container half element of its
        // capacity
        if (size == (capacity / 2)) {
            shrinkArray();
        }
    }

    // Increase the array size by double of current capacity
    void growArray()
    {

        // Creating new array of double size
        T* temp = new T[capacity * 2];

        capacity = capacity * 2;
        // copy element of old array in newly created array
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }

        // Delete old array
        delete[] array;

        // Assign newly created temp array to original array
        array = temp;
    }

    // Reduce the size of array by half
    void shrinkArray()
    {

        // Creating new array of half size
        capacity = size;
        T* temp = new T[capacity];

        // copy element of old array in newly created array
        for (int i = 0; i < size; i++) {
            temp[i] = array[i];
        }

        // Delete old array
        delete[] array;

        // Assign newly created temp array to original array
        array = temp;
    }

    // Searching element in the given array
    int search(T key)
    {
        for (int i = 0; i < size; i++) {
            if (array[i] == key) {
                // If element found return its index
                return i;
            }
        }

        // Return -1 if element not found;
        return -1;
    }

    T& searchByIndex(int index)
    {
        //A check to see if index is out of bounds
        if (index < 0 || index >= size) 
        {
            std::cout << "Index out of bounds \n";
        }
        return array[index];
    }

    // Insert element at given index
    void insertAt(int index, T value)
    {
        // check is array having size to store element or
        // not
        if (size == capacity) {

            // if not then grow the array by double
            growArray();
        }

        for (int i = size - 1; i >= index; i--) {
            array[i + 1] = array[i];
        }

        array[index] = value;
        size++;
    }

    // Delete element at given index
    void deleteAt(int index)
    {
        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        // Replace the last index by 0
        array[size - 1] = '0';

        // Decrement the array size
        size--;

        // Reduce if the container half element of its
        // capacity
        if (size == (capacity / 2 + 1)) {
            shrinkArray();
        }
    }

    // To Print Array
    void printArrayDetails()
    {
        std::cout << "Elements of array : ";
        for (int i = 0; i < size; i++) {
           std::cout << array[i] << ", ";
        }
        std::cout << std::endl << "No of elements in array : " << size
             << ", Capacity of array : " << capacity << std::endl;
    }

    bool isEmpty()
    {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    // override to allow cout to work
    // where i got this code:
    // https://learn.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-170
    // https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-class-template
    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray<U>& da);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& da)
{
    os << "[";
        for (int i = 0; i < da.size; i++) {
           os << da.array[i] << ", ";
        }
    os << "]";
    return os;
}

#endif