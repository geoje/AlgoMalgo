#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int r, c, m;
};

const pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (auto place : places)
    {
        // 초기 사람 위치 전부 넣기
        queue<node> q;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (place[i][j] == 'P')
                    q.push({i, j, 0});

        // 노드 전부 보기
        while (!q.empty())
        {
            node virus = q.front();
            q.pop();
        }
    }

    return answer;
}

int main()
{
    vector<int> result = solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
                                   {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
                                   {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
                                   {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
                                   {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});

    for (int n : result)
        cout << n << ' ';
    cout << '\n';
}