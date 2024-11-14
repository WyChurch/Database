//
//  Database.h
//  Knit Stuff
//
//  Created by Anthony Cook on 4/2/24.
//

#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm> // for std::sort

template<typename T>
class Database {
private:
    std::vector<std::string> names;
    std::vector<T> price;

public:
    // Constructor
    Database() {}

    // Method to add data to the database
    void addData(const std::string& name, const T& num) {
        names.push_back(name);
        price.push_back(num);
    }

    // Method to print the contents of the database
    void printDatabase() const {
        for (size_t i = 0; i < names.size(); ++i) {
            std::cout << "Name: " << names[i] << ", Price: $" << price[i] << std::endl;
        }
    }

    // Method to sort the database by name
    void sortByName() {
        std::vector<std::pair<std::string, T>> tempData;
        for (size_t i = 0; i < names.size(); ++i) {
            tempData.push_back(std::make_pair(names[i], price[i]));
        }

        std::sort(tempData.begin(), tempData.end(), [](const auto& left, const auto& right) {
            return left.first < right.first;
        });

        for (size_t i = 0; i < tempData.size(); ++i) {
            names[i] = tempData[i].first;
            price[i] = tempData[i].second;
        }
    }

    // Method to sort the database by price
    void sortByPrice() {
        std::vector<std::pair<std::string, T>> tempData;
        for (size_t i = 0; i < names.size(); ++i) {
            tempData.push_back(std::make_pair(names[i], price[i]));
        }

        std::sort(tempData.begin(), tempData.end(), [](const auto& left, const auto& right) {
            return left.second < right.second;
        });

        for (size_t i = 0; i < tempData.size(); ++i) {
            names[i] = tempData[i].first;
            price[i] = tempData[i].second;
        }
    }
};

#endif // DATABASE_H
