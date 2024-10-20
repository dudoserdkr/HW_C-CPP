#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);

    double num;
    char comma;
    while (ss >> num) {
        if (num > 0) {
            cout << scientific << log(num) << "  " <<fixed << setprecision(5) << log(num) << endl;
        }
        else {
            cout << "None";
        }
        if (ss.peek() == EOF) {
            break;
        }
        ss >> comma;
    }
}