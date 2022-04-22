#include <iostream>
#include <string>
using namespace std;

int num[10];
int n, d;
int main() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		string str = to_string(i);
		for (int j = 0; j < str.size(); j++) {
			num[str[j] - '0']++;
		}
	}
	cout << num[d];
}