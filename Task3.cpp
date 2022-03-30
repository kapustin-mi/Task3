#include <string.h>
#include <iostream>
using namespace std;

int readLength() {
    int length;
    cout << "Enter the number of characters: ";
    
    cin >> length;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(999, '\n');

        cout << "Invalid value! Please, try again...\n";
        return readLength();
    }

    if (length < 0) {
        cout << "Invalid value! The number of characters must be greater than 0. Please, try again...\n";
        return readLength();
    }

    cin.ignore(999, '\n');
    return length;
}

char* convertToCharArr(char* arr, const string& line, int length) {
    char* p = arr;

    for (int i = 0; i < length; i++) {
        *p = line[i];
        p++;
    }

    return arr;
}

char* readLine(char* arr, int length) {
    string line;
    cout << "Enter the line: ";
    cin >> line;

    return convertToCharArr(arr, line, length);
}

void printExcludingPairs(char* arr, int length) {
    char *p = arr;
    
    for (int i = 0; i < length; i++) {
        if (i % 4 == 0 || i % 4 == 1) {
            cout << *p;
        }
        p++;
    }
}

int main() {
    int length = readLength();
    char* arr = new char[length];
    arr = readLine(arr, length);
  

    printExcludingPairs(arr, length);
}
