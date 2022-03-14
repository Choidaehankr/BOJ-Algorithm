#include <iostream>
#include <algorithm>
#include <string>
#define MAX 4001
using namespace std;

// LCS(Longest Common Subsequence/Substring) 참고
// https://katfun.tistory.com/entry/Longest-Common-Subsequence-LCS-Algorithm

int arr[MAX][MAX];

string A,B;
int main() {
    cin >> A >> B;
    int result = 0;

    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < B.size(); j++) {
            arr[i][j] = 0;
        }
    }

    for(int i = 1; i <= A.size(); i++) {
        for(int j = 1; j <= B.size(); j++) {
            if(A[i-1] == B[j-1]) {
                arr[i][j] = arr[i-1][j-1] + 1;
                result = max(arr[i][j], result);
            }
        }
    }
    cout << result << endl;
}