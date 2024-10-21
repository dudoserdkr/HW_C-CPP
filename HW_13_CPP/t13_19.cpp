#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    string word;

    getline(cin, line);
    istringstream stream(line);

    while (stream >> word) {
        if (word.find("ings") != string::npos) {
            cout << word << " ";
        }
    }
}