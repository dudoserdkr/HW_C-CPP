#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void input_vector(vector<string> &v1, string vector_number) {
    cout << "Input " << vector_number <<" vector:" << endl;
    string line, number;
    getline(cin, line);

    stringstream ss;
    ss << line;

    while (ss >> number) {
        v1.push_back(number);
    }
}

int main() {
    vector<string> v1, v2;

    input_vector(v1, "first");
    input_vector(v2, "second");

    set<string> set_v1 = set(v1.begin(), v1.end());
    set<string> set_v2 = set(v2.begin(), v2.end());
    set<string> union_v1_v2;

    set_union(set_v1.begin(), set_v1.end(), set_v2.begin(), set_v2.end(), inserter(union_v1_v2, union_v1_v2.begin()));

    map<string, int> dict;

    vector<string> keys;

    for (string elem: union_v1_v2) {
        keys.push_back(elem);
        int count_v1 = count(v1.begin(), v1.end(), elem);
        int count_v2 = count(v2.begin(), v2.end(), elem);
        dict[elem] = max(count_v1, count_v2);
    }

    sort(keys.begin(), keys.end(), [](const string &a,const string &b) {
        return stoi(a) > stoi(b);
    });

    for (string key: keys) {
        for (int i = 0; i < dict[key]; i++) {
            cout << key << " ";
        }
        cout << endl;
    }


}