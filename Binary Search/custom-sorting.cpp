#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(char char1, char char2, string order) {
    return (order.find(char1) < order.find(char2));
}

string customSortString(string order, string s) {
    sort(s.begin(), s.end(), [&](char a, char b) {
        return compare(a, b, order);
    });
    return s;
}

int main() {
    string order = "cba";
    string s = "abcd";
    cout << "Sorted String: " << customSortString(order, s) << endl;
    return 0;
}
