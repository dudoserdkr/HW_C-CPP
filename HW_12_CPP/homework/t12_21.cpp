#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("HW_12_CPP/homework/input12_21.txt");

    int day, month, year;
    int min_date[] = {40, 0, 800000};
    int max_date[] = {0, 0, 0};
    char slash1, shlash2;

    while (file >> day >> slash1 >> month >> shlash2 >> year) {
        if (year < min_date[2] || (year == min_date[2] && month < min_date[1]) || (year == min_date[2] && month == min_date[1] && day < min_date[0])) {
            min_date[0] = day;
            min_date[1] = month;
            min_date[2] = year;
        }
        if (year > max_date[2] || (year == max_date[2] && month > max_date[1]) || (year == max_date[2] && month == max_date[1] && day > max_date[0])) {
            max_date[0] = day;
            max_date[1] = month;
            max_date[2] = year;
        }
    }

    file.close();

    ofstream f("HW_12_CPP/homework/output12_21.txt");
    if (!f) {
        cerr << "Error opening output file" << endl;
        return 1;
    }

    f << min_date[0] << slash1 << min_date[1] << shlash2 << min_date[2] << endl;
    f << max_date[0] << slash1 << max_date[1] << shlash2 << max_date[2];
}