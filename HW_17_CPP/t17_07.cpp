#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
#include <fstream>
#include <cassert>

using namespace std;

class FileManager {
protected:
    string file_path;
    int numbers_num = 0; // number of numbers in file
    int lines_num = 0; // number of lines in file

    [[nodiscard]] ifstream open_file_for_input() const {

        ifstream file(file_path);

        if (!file) {
            cerr << "Error opening file" << endl;
            exit(1);
        }
        return file;
    }
    [[nodiscard]] ofstream open_file_for_output(ios::openmode const mode = ios::out) const {

        ofstream file(file_path, mode);

        if (!file) {
            cerr << "Error opening file" << endl;
            exit(1);
        }
        return file;
    }

    void calc_file_parameters() {
        ifstream file = open_file_for_input();

        string line;
        while(getline(file, line)) {
            this->lines_num++;

            istringstream iss(line);
            double number;

            while(iss >> number) {
                this->numbers_num++;
            }
        }
        file.close();
    }

public:
    explicit FileManager(string file_path): file_path(std::move(file_path)) {
        calc_file_parameters();
    }

    void print_file_parameters() const {
        cout << "Number of numbers: " << this->numbers_num << endl;
        cout << "Number of lines: " << this->lines_num << endl;
    }

    int get_numbers_num() const {
        return numbers_num;
    }

    int get_lines_num() const {
        return lines_num;
    }

    void input_numbers() {
        // You need to input numbers until you type "exit"

        ofstream file = open_file_for_output();

        string line;
        while(true) {
            getline(cin, line);
            if (line == "exit") {
                break;
            }
            file << line << endl;
        }
        file.close();
        calc_file_parameters();
    }

    void input_numbers(const vector<vector<int>>& arr) {

         cout << 'You need to input numbers until you type "exit"' << endl;

        ofstream file = open_file_for_output();

        for (auto & i : arr) {
            for (int j : i) {
                file << j << " ";
            }
            file << endl;
        }
        file.close();
        calc_file_parameters();
    }

    void output_file() {
        ifstream file = open_file_for_input();

        string line;
        while(getline(file, line)) {
            cout << line << endl;
        }

        file.close();
        calc_file_parameters();
    }

    [[nodiscard]] double find_number(int n) const {
        ifstream file = open_file_for_input();

        int counter = 0;
        double number;

        while(file >> number) {
            counter++;
            if (counter == n) {
                file.close();
                return number;
            }
        }
        cerr << "There is no number with this index" << endl;
        exit(1);
    }



    void add_to_end(const vector<int>& arr) {
        ofstream file = open_file_for_output(ios::app);

        for (int i : arr) {
            file << i << " ";
        }
        file.close();
        calc_file_parameters();
    }

    void delete_number(int n, int line_n) {

        assert(n <= numbers_num || line_n <= lines_num);

        ifstream file = open_file_for_input();

        vector<string> lines;
        string line;
        int line_count = 0;

        bool is_deleted = false;

        while (getline(file, line)) {
            if (++line_count == line_n) {
                istringstream iss(line);
                ostringstream oss;
                int numbers_count = 0;
                double number_double;

                while(iss >> number_double) {
                    if (++numbers_count == n) {
                        is_deleted = true;
                        continue;
                    }
                    oss << number_double << " ";
                }
                lines.push_back(oss.str());
            }
            else {
                lines.push_back(line);
            }
        }
        file.close();

        if (!is_deleted) {
            cerr << "There is no number with this index" << endl;
            exit(1);
        }

        ofstream file_out = open_file_for_output();

        for (const auto& l : lines) {
            file_out << l << endl;
        }
        calc_file_parameters();
    }
};


//region tests_________________________________________________________

void test_input_numbers() {
    FileManager fm("HW_17_CPP/test_file.txt");
    vector<vector<int>> input_data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    fm.input_numbers(input_data);

    ifstream file("HW_17_CPP/test_file.txt");
    string line;
    getline(file, line);
    assert(line == "1 2 3 ");
    getline(file, line);
    assert(line == "4 5 6 ");
    getline(file, line);
    assert(line == "7 8 9 ");
    file.close();
    cout << "test_input_numbers passed" << endl;
}


void test_add_to_end() {
    FileManager fm("HW_17_CPP/test_file.txt");
    vector<int> additional_numbers = {10, 11, 12};
    fm.add_to_end(additional_numbers);

    ifstream file("HW_17_CPP/test_file.txt");
    string line;
    vector<string> lines;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    assert(lines.back() == "10 11 12 ");
    cout << "test_add_to_end passed" << endl;
}

void test_find_number() {
    FileManager fm("HW_17_CPP/test_file.txt");
    double found_number = fm.find_number(5);
    assert(found_number == 5);
    cout << "test_find_number passed" << endl;
}

void test_delete_number() {
    FileManager fm("HW_17_CPP/test_file.txt");
    fm.delete_number(2, 1);

    ifstream file("HW_17_CPP/test_file.txt");
    string line;
    getline(file, line);
    file.close();

    assert(line == "1 3 ");
    cout << "test_delete_number passed" << endl;
}


//endregion_________________________________________________________

int main() {
    ofstream test_file("HW_17_CPP/test_file.txt");
    test_file << "1 2 3\n4 5 6\n7 8 9\n";
    test_file.close();

    test_input_numbers();
    test_add_to_end();
    test_find_number();
    test_delete_number();
    cout << "All tests passed!" << endl;
}