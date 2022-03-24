#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, W, L;  // 트럭 수, 다리의 길이, 최대 하중
int time = 0;
vector<int> v;
queue<int> q;
int main() {
	cin >> N >> W >> L;
	for (int i = 0; i < N; i++) {
		int num; cin >> num;
        v.push_back(num);
	}
    int sum = 0;  // 다리에 올라가있는 트럭 무게
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        while(1) {
            if(q.size() == W) {  // 첫번째 트럭이 다리 끝에 도착하면 해당 트럭을 빼준다.
                sum -= q.front();
                q.pop();
            }
            if(sum + v[i] <= L) break;  // 현재 다리에 있는 트럭 수가 최대 하중보다 크다면 0으로 채운다.
            q.push(0);
            cnt+=1;
        }
        q.push(v[i]);
        sum += v[i];
        cnt+=1;
    }
    cnt += W;
    cout << cnt << endl;
}