#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int N1, N2;
    cin >> N1 >> N2;

    if (N1 - N2 == 0) {
        cout << "Зміни внести неможливо\n" << endl;
        return 0;
    }

    ifstream f_input("HW_14_CPP/t14_20.txt");
    if (!f_input) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    ofstream f_output("HW_14_CPP/t14_20_output.txt");

    string line;

    int counter = 1;

    while (getline(f_input, line)) {
        if (N1 < counter && counter < N2) {
            counter++;
            continue;
        }
        f_output << line << endl;
        counter++;
    }
    f_input.close();
    f_output.close();
}