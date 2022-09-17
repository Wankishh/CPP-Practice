#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const string DELIMITER = " ";


const char searchables[4] = {'a', 'e', 'i', 'o' };


void castStringToCharArr(string &value, int size, char* returnArr) {
    vector<char> dynArray;

    size_t pos = 0;
    // define a string variable
    string cutString;

    char cutChar;

    int index = 0;


    while (( pos = value.find (DELIMITER)) != std::string::npos)
    {
        cutString = value.substr(0, pos);
        cutChar = cutString[0];
        returnArr[index] = cutChar;
        index++;
        value.erase(0, pos + DELIMITER.length());
    }

    // Push whats left over, we cant split without delimiter
    cutChar = value[0];
    returnArr[index] = cutChar;
}

void printArray(char* arr, int size) {

    for(int i = 0; i < size; i++) {
        cout << arr[i];
        cout << " ";
    }

    cout << "" << endl;

}

int countSearchablesInVector(char* row, int size) {
    int counter = 0;
    for(int i = 0; i< size; i++) {
       for(const char c: searchables)  {
            if(c == row[i]) {
                counter++;
            }
       }
    }

    return counter;
}

string join(char* arr) {
    string result = "";
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i< arrSize; i++) {
        result += arr[i];
        result += " ";
    }


    return result;
}


int main(int argc, char** argv) {
    // read input

    vector<string> stdIn;

    for (std::string line; std::getline(std::cin, line);) {
        stdIn.push_back(line);
    }

    int matrixLength =  stoi(stdIn[0]);
    int matrixRows = matrixLength + 1;

    int rowNum = 0;
    string maxCountRow;
    int currentCount = 0;


    for(int i = 1; i < matrixRows; i++) {
        string row = stdIn[i];
        char parsedRowToChar[matrixLength];

        castStringToCharArr(row, matrixLength, parsedRowToChar);
        int countSearchables = countSearchablesInVector(parsedRowToChar, matrixLength);

        if(countSearchables > currentCount) {
            rowNum = i;
            currentCount = countSearchables;
            maxCountRow = join(parsedRowToChar);
        }
    }

    cout << maxCountRow << endl;


    return 0;
}
