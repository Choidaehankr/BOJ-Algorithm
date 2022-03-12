#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int tmp = 1;
	while (1) {
		int num = 0;
		if (tmp >= N) {
			cout << 0 << endl;
			break;
		}
		string str = to_string(tmp);
		for (int i = 0; i < str.size(); i++) {
			num += str[i]-48;
		}
		if (tmp + num == N) {
			cout << tmp << endl;
			break;
		}
		tmp += 1;
	}
}