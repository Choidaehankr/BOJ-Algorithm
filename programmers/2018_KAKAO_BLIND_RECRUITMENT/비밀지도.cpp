#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

string solve(int num) {
    string tmp;
    while (num != 0) {
        tmp += (num % 2 == 0 ? "0" : "1");
        num /= 2;
    }
    return tmp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> vec1, vec2;
    // string str1 = "", str2 = "";
    for(int i = 0; i < arr1.size(); i++) {
        string str1 = solve(arr1[i]);
        while(str1.size() == 5) {
            str1.insert(str1.begin(), '0');
        }
        cout << "Str1: " << str1 << endl;
        vec1.push_back(str1);
    }
    for(int i = 0; i < arr2.size(); i++) {
        string str2 = solve(arr2[i]);
        while(str2.size() == 5) {
            str2.insert(str2.begin(), '0');
        }
        cout << "str2: " << str2 << endl;
        vec2.push_back(str2);
    }
    for(int i = 0; i < n; i++) {
        string tmp = "";
        for(int j = 0; j < n; j++) {
            if(vec1[i][j] == '1' || vec2[i][j] == '1') {
                tmp += '#';
            } else if(vec1[i][j] == '0' && vec2[i][j] == '0') {
                tmp += ' ';
            }
        }
        answer.push_back(tmp);  
    }
    return answer;
}