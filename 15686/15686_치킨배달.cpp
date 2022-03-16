#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int city[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
vector<pair<int, int>> house;  // 치킨집과의 최단 거리를 찾기위해 집의 위치들을 vector에 넣음.
vector<pair<int, int>> chick;


vector<pair<int, int>> comb;
// vector<pair<int, int>> combination(vector<pair<int, int>> v, int n, int r, int index, int target, vector<pair<int, int>> comb) {
void combination(vector<pair<int, int>> v, int n, int r, int index, int target) {
    comb.clear();
    if(r == 0) {
        for(int i = 0; i < index; i++) {
            cout << comb[i].first << ' ' << comb[i].second << ' ';
        }
        cout << endl;
    } else if(target == n) {
        return;
        // comb.clear();
    } else {
        comb.push_back({v[target].first , v[target].second});
        combination(v, n, r-1, index+1, target+1);
        combination(v, n, r, index, target+1);
    }
} 

int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int num; cin >> num;
            if(num == 1) {
                house.push_back({i, j});
            } else if(num == 2) {
                chick.push_back({i, j});
                continue;
            }
            city[i][j] = num;
        }
    }
    cout << "--------------chick test-----------" << endl;
    for(int i = 0; i < chick.size(); i++) {
        cout << chick[i].first << ' ' << chick[i].second << endl;
    }
    cout << endl;
    vector<pair<int, int>> res;
    combination(chick, 5, 2, 0, 0);
}