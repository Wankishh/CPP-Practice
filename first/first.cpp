#include <iostream>
#include <string>
#include <vector>
using namespace std;


string parsePhone(string phone) {

    if(phone.length() < 3) {
        return "";
    }

    int findOpenBrace = phone.find("(");
    int findClosedBrace = phone.find(")");


    if(findOpenBrace == -1 || findClosedBrace == -1) {
        return "";
    }


    int posOfPLus = phone.find("+");

    string cutPhoneOnly = phone.substr(posOfPLus, findClosedBrace - 1);

    return cutPhoneOnly;
}


int main(int argc, char** argv) {
    // read input

    vector<string> stdIn;

    for (std::string line; std::getline(std::cin, line);) {
        stdIn.push_back(line);
    }

    for(vector<string>::iterator itr=stdIn.begin();itr!=stdIn.end();++itr) {
        cout << parsePhone(*itr) << endl;
    }

    return 0;
}
