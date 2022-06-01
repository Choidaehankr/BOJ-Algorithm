// 단순한 bfs문제인데 메모리 아낄 겸 방문표시를 picture[x][y] = -1로 하고, 
// BFS 함수에서 파라미터로 'vector<vector<int>> &v'와 같이 참조로 넘겨서 실행하니 계속 core dump 오류 발생
// 걍 visited 배열 선언해서 방문 체크해줌

#include <vector>
#include <queue>
#include<iostream>
#include <cstring>
using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool visited[100][100];
 
int BFS(int a, int b, int m, int n, vector<vector<int>> v)
{
    int num = v[a][b];
    int cnt = 1;
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    visited[a][b] = true;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0 ; i < 4; i++)
        {
            int nx = x +dx[i];
            int ny = y+ dy[i];
            if(nx>=0 && ny>=0 && nx < m && ny < n)
            {
                if(v[nx][ny] == num && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) 
{
    memset(visited, false, sizeof(visited));
    int number_of_area = 0;
    int max_size_of_one_area = 0;  
    for(int i = 0; i < m; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(picture[i][j] != 0 && !visited[i][j])
            {
                int Size = BFS(i, j, m, n, picture);
                max_size_of_one_area = max(max_size_of_one_area, Size);
                number_of_area+=1;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
