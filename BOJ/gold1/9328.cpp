#include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

int h, w;
char map[100][100];
bool visited[100][100] = {0};
vector<pair<int, int>> door[26];

const pair<int, int> dirs[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int solve()
{
    int ans = 0;
    queue<pair<int, int>> q;

    // 맵 테두리에 길, 문서, 열쇠 모두 큐에 추가
    vector<pair<int, int>> boundary;
    for (int i = 0; i < h; i++)
    {
        boundary.push_back({i, 0});
        boundary.push_back({i, w - 1});
    }
    for (int j = 1; j < w - 1; j++)
    {
        boundary.push_back({0, j});
        boundary.push_back({h - 1, j});
    }
    for (auto p : boundary)
    {
        char &c = map[p.first][p.second];
        if (c == '.' || c == '$' || (c >= 'a' && c <= 'z'))
            q.push(p);
    }

    // 모든 노드 파악
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        char &c = map[p.first][p.second];

        // 방문 여부 파악
        if (visited[p.first][p.second])
            continue;
        visited[p.first][p.second] = true;

        // 문서일 경우 정답 추가
        if (c == '$')
            ans++;

        // 열쇠일 경우 문 따고 가본적 있는 곳이면 좌표 추가
        else if (c >= 'a' && c <= 'z')
            for (auto dp : door[c - 'a'])
            {
                map[dp.first][dp.second] = '.';
                for (auto dir : dirs)
                {
                    int ni = dp.first + dir.first;
                    int nj = dp.second + dir.second;
                    if (ni < 0 || nj < 0 || ni >= h || nj >= w || visited[ni][nj])
                    {
                        q.push(dp);
                        break;
                    }
                }
            }

        // 길일 경우 갈 수 있는 모든 방향 입력
        for (auto dir : dirs)
        {
            int ni = p.first + dir.first;
            int nj = p.second + dir.second;
            if (ni < 0 || nj < 0 || ni >= h || nj >= w)
                continue;

            char &nc = map[ni][nj];
            if (nc == '*' || (nc >= 'A' && nc <= 'Z'))
                continue;

            q.push({ni, nj});
        }

        // 내 위치 길로 변경
        c = '.';
    }

    return ans;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    int tc;
    cin >> tc;
    while (tc--)
    {
        /* Input */
        cin >> h >> w;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
                if (map[i][j] >= 'A' && map[i][j] <= 'Z')
                    door[map[i][j] - 'A'].push_back({i, j});
            }

        // 최초 열쇠로 문 열기
        string keyStr;
        cin >> keyStr;
        if (keyStr != "0")
            for (char keyChar : keyStr)
                for (auto p : door[keyChar - 'a'])
                    map[p.first][p.second] = '.';

        /* Process & Output */
        // for (int i = 0; i < h; i++)
        // {
        //     for (int j = 0; j < w; j++)
        //         cout << map[i][j];
        //     cout << '\n';
        // }
        cout << solve() << '\n';
        // for (int i = 0; i < h; i++)
        // {
        //     for (int j = 0; j < w; j++)
        //         cout << map[i][j];
        //     cout << '\n';
        // }

        /* Clear */
        fill_n(&map[0][0], 10000, 0);
        fill_n(&visited[0][0], 10000, 0);
        for (int i = 0; i < 26; i++)
            door[i].clear();
    }
    return 0;
}