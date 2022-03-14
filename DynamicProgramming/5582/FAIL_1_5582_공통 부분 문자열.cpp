#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 문자열 A와 B를 일일히 비교하면서 일치하는 만큼 CNT변수 증가. A와 B가 달라지는 순간 break 후 cnt값 갱신.. 100퍼 시간초과 각
int dp[4000];
string A,B;
int main() {
    cin >> A >> B;
    int result = 0;
     for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < B.size(); j++) {
            // int cnt = 1;
             if(A[i] == B[j]) {
                //  cout << "A[i] is " << A[i] << " B[j] is " << B[j] << endl;
                 dp[j] = max(dp[j], 1);
                 for(int k = 1; (i+k < A.size() && j+k < B.size()); k++) {
                     if(A[i+k] == B[j+k]) {
                        // cout << "A[i+k] is \"" << A[i+k] << "\" B[j+k] is \"" << B[i+k] << "\" (k) is \"" << k << "\"" << endl;
                        // dp[j+k] = max(dp[j+k, k);
                        dp[j+k] = max(dp[j+k], k+1);
                     } else {
                         break;
                     }
                 }
             }
         }
     }
     for (int i = 0; i < B.size(); i++) {
         result = max(dp[i], result);
     }
    cout << result << endl;
}