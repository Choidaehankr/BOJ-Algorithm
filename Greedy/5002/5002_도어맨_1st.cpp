#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
stack<char> s;

// 'W'면 wCnt를 증가, 'M'이면 mCnt를 증가.
// W와 M의 차이가 X보다 크거나 같아질 떄
// 1) {남자가 여자보다 / 여자가 남자보다} 많다면
// 1-1) 현재 줄을 선 사람이 {여자라면  / 남자라면} 성별 그대로 스택에 넣어주고 continue
// 1-2) 현재 줄을 선 사람이 {남자라면 / 여자라면} 그 다음의 성별을 확인. 확인했을 때 X를 초과하지 않을 수 있다면 str에서 지워주고 그대로 진행 

// 코드가 좀 지저분하다.

int main() {
	int X;
	string str;
	cin >> X >> str;
	int wCnt = 0, mCnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (abs(mCnt - wCnt) >= X) {
			if (mCnt > wCnt) {
				if (str[i] == 'W') {
					wCnt++;
					s.push(str[i]);
					continue;
				}
				else {
					if (str[i + 1] == 'W') {
						s.push(str[i + 1]);
						str.erase(str.begin() + i + 1);
						wCnt++;
						i--;
						continue;
					}
					else {
						break;
					}
				}
				
			}
			else if(wCnt > mCnt){
				if (str[i] == 'M') {
					mCnt++;
					s.push(str[i]);
					continue;
				}
				else {
					if (str[i + 1] == 'M') {
						s.push(str[i + 1]);
						str.erase(str.begin() + i + 1);
						mCnt++;
						i--;
						continue;
					}
					else {
						break;
					}
				}
			}
		}
		if (str[i] == 'W') {
			wCnt++;
		}
		else if (str[i] == 'M') {
			mCnt++;
		}
		s.push(str[i]);
	}
	cout << s.size() << endl;
}