#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const string DELIMITER = " ";


vector<int> castStringToVector(string &value) {
    vector<int> dynArray;

    size_t pos = 0;
    string cutString; // define a string variable

    std::cout << value << std::endl;

    while (( pos = value.find (DELIMITER)) != std::string::npos)
    {
        cutString = value.substr(0, pos);
        dynArray.push_back (stoi(cutString));
        value.erase(0, pos + DELIMITER.length());
    }
    // Push whats left over, we cant split without delimiter
    dynArray.push_back(stoi(value));
    cout << value << endl;

    return dynArray;

}

void debugVector(vector<int> debug) {
    for(const auto i: debug) {
        cout << i << endl;
    }
}


int main(int argc, char** argv) {
    // read input

    vector<int> in;
    in.push_back(33);
    in.push_back(44);
    in.push_back(54);
    in.push_back(5);
    in.push_back(55);
    vector<string> stdIn;

    for (std::string line; std::getline(std::cin, line);) {
        stdIn.push_back(line);
    }

    int insertLength =  stoi(stdIn[0]);
    string valueToInsert = stdIn[1];
    int posToInsert = stoi(stdIn[2]);

    int maxLengthToInsert = insertLength + posToInsert;
    int currentLengthInsert = posToInsert;

    vector<int> toVector = castStringToVector(valueToInsert);

    std::cout << "Old" << std::endl;

    debugVector(in);
    in.insert(in.begin() + posToInsert - 1, toVector.begin(), toVector.end());

    std::cout << "New" << std::endl;
    debugVector(in);

    return 0;
}
