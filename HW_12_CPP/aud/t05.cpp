#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("HW_12_C/aud/outputt05.txt");
    if (!file) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    unsigned long num;
    while (file >> num) {
        cout << fixed << setprecision(3) << sqrt(num) << endl;
    }

    file.close();
}