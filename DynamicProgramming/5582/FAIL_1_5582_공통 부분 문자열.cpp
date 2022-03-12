#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 문자열 A와 B를 일일히 비교하면서 일치하는 만큼 CNT변수 증가. A와 B가 달라지는 순간 break 후 cnt값 갱신.. 100퍼 시간초과 각

string A,B;
int main() {
    cin >> A >> B;
    int result = 0;
     for(int i = 0; i < A.size(); i++) {
        //cout << "First A[i] is " << A[i] << endl;
        for(int j = 0; j < B.size(); j++) {
            //cout << "First B[j] is " << B[j] << endl;
             if(A[i] == B[j]) {
                int cnt = 1;  // 2번째 loop로 옮겨보기
                int idx = 1;
                 while(i+idx <= A.size() && j+idx <= B.size()) {
                  //  cout << "i+idx is " << i+idx << " j+idx is " << j+idx << endl;
                    if(A[i+idx] == B[j+idx]) {
                       // cout << "A[i+idx] is " << A[i+idx] << " B[j+idx] is " << B[j+idx] << endl;
                        cnt+=1;
                    } else {
                       // cout << "result is " << result << " cnt is " << cnt << endl;
                        result = max(result, cnt);
                        break;
                    }
                    idx+=1;
                 }
             }
         }
     }
    cout << result << endl;
}