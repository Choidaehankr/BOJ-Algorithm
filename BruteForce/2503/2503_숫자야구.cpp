#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool check[1000];

vector<pair<int, pair<int, int> > > v;

void init() {
	fill(check, check + 1000, true);
	for (int i = 123; i <= 987; i++) {
		string str = to_string(i);
		if (str[0] == str[1] || str[1] == str[2] || str[2] == str[0]) check[i] = false;
		if (str[0] - '0' == 0 || str[1] - '0' == 0 || str[2] - '0' == 0) check[i] = false;
	}
}

int main() {
	int N; cin >> N;
	init();
	for (int i = 0; i < N; i++) {
		int number, strike, ball;
		cin >> number >> strike >> ball;
		v.push_back(make_pair(number, make_pair(strike, ball)));
	}
	for (int i = 0; i < v.size(); i++) {
		int number = v[i].first;
		int strike = v[i].second.first;
		int ball = v[i].second.second;
		string tmp = to_string(number);
		for (int j = 123; j <= 987; j++) {
			int expStrike = 0;
			int expBall = 0;
			if (check[j]) {
				string str = to_string(j);
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						if (x == y && tmp[x] == str[y]) expStrike += 1;
						if (x != y && tmp[x] == str[y]) expBall += 1;
					}
				}
				if (strike != expStrike || ball != expBall) 
					check[j] = false;
			}
		}
	}
	int result = 0;
	for (int i = 123; i <= 987; i++) {
		if (check[i]) result += 1;
	}
	cout << result << endl;
}