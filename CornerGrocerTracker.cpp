/*
Sean Zamastil
12/14/2024
An application that tracks itemized goods
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;


class ItemSearch {
private:
    map<string, int> itemFrequency; // To store item frequencies
    string inputFileName = "CS210_Project_Three_Input_File.txt";
    string outputFileName = "frequency.dat";

    void readInputFile() {
        ifstream inputFile(inputFileName);
        if (!inputFile) {
            cerr << "Error: Unable to open file " << inputFileName << endl;
            return;
        }

        string item;
        while (inputFile >> item) {
            itemFrequency[item]++;
        }

        inputFile.close();
    }

    void writeOutputFile() {
        ofstream outputFile(outputFileName);
        if (!outputFile) {
            cerr << "Error: Unable to create file " << outputFileName << endl;
            return;
        }

        for (const auto& item : itemFrequency) {
            outputFile << item.first << " " << item.second << endl;
        }

        outputFile.close();
    }

public:
    ItemSearch() {
        readInputFile();
        writeOutputFile();
    }

    void searchItem() {
        string item;
        cout << "Enter the item to search for: ";
        cin >> item;
        if (itemFrequency.count(item)) {
            cout << "Frequency of " << item << " is " << itemFrequency[item] << endl;
        }
        else {
            cout << item << " not found." << endl;
        }
    }

    void printList() {
        cout << "Item Frequency List:" << endl;
        for (const auto& item : itemFrequency) {
            cout << item.first << " " << item.second << endl;
        }
    }

    void printHistogram() {
        cout << "Item Frequency Histogram:" << endl;
        for (const auto& item : itemFrequency) {
            cout << item.first << " ";
            for (int i = 0; i < item.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {

    ItemSearch itemSearch;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Search for an item\n";
        cout << "2. Print item frequency list\n";
        cout << "3. Print item frequency histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            itemSearch.searchItem();
            break;
        case 2:
            itemSearch.printList();
            break;
        case 3:
            itemSearch.printHistogram();
            break;
        case 4:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid input. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}