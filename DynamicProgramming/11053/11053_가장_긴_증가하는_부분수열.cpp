#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int result = 0;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)  {
        int cur = arr[i];
        int num = 0;
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                if(num < dp[j]) {
                    num = dp[j];
                }
            }
        }
        dp[i] = num + 1;
        result = max(result, dp[i]);
    }
    cout << result << endl;
}
    