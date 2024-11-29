#include <iostream>
#include <map>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<char, int> dict;
    vector<char> keys;

    for(char c = 'a'; c <= 'z'; c++) {
        dict[c] = 0;
        keys.push_back(c);
    }

    vector<string> words;
    string word;
    while (cin >> word) {
        if (word == "exit") {break;}
        words.push_back(word);
    }

    for (string el : words) {
        dict[tolower(el[0])] += el.length();
    }

    for (char key : keys) {
        if (dict[key] != 0) {
            cout << key << " " << dict[key] << endl;
        }
    }

}