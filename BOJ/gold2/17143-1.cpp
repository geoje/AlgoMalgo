#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct sh
{
    int v;
    int dir;
    int s_size;
};
struct cmp
{
    bool operator()(sh a, sh b)
    {
        if (a.s_size < b.s_size)
            return true;
        else
            return false;
    }
};

int n_r, n_c, m;

vector<sh> shark[101][101];
priority_queue<sh, vector<sh>, cmp> after_shark[101][101];

// 1 : 위  2: 아래 3 : 오른쪽 4 : 왼
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
int cnt[101][101];

void move_all();
void move(sh, int, int);

int inverse(int dir)
{
    if (dir == 1)
    {
        return 2;
    }
    else if (dir == 2)
    {
        return 1;
    }
    else if (dir == 3)
    {
        return 4;
    }
    else if (dir == 4)
    {
        return 3;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n_r >> n_c >> m;

    for (int i = 0; i < m; i++)
    {
        int r, c, s, d, z;

        cin >> r >> c >> s >> d >> z;
        if (d <= 2)
            s %= (n_r - 1) * 2;
        else
            s %= (n_c - 1) * 2;
        shark[r][c].push_back({s, d, z});
    }

    int ans = 0;
    for (int i = 1; i <= n_c; i++)
    {

        //낚시왕 낚시함.
        for (int j = 1; j <= n_r; j++)
        {
            if (!shark[j][i].empty())
            {
                ans += shark[j][i].at(0).s_size;
                shark[j][i].pop_back();
                break;
            }
        }

        //상어들의 이동
        move_all();
    }

    cout << ans;
    //낚은 상어 총합 구하기.
}

void move_all()
{

    //모든 맵을 순회하며 상어 있으면 추가함.
    for (int i = 1; i <= n_r; i++)
    {
        for (int j = 1; j <= n_c; j++)
        {
            if (!shark[i][j].empty())
            {
                sh tmp = shark[i][j].at(0);
                move(tmp, i, j);
                shark[i][j].pop_back();
            }
        }
    }

    for (int i = 1; i <= n_r; i++)
    {
        for (int j = 1; j <= n_c; j++)
        {

            if (!after_shark[i][j].empty())
            {
                //제일 무거운 물고기만 shark[i][j]에 push하고 나머지는 사라짐.
                shark[i][j].push_back(after_shark[i][j].top());
                while (!after_shark[i][j].empty())
                {
                    after_shark[i][j].pop();
                }
            }
        }
    }
}

void move(sh tmp, int x, int y)
{

    int time = tmp.v;
    int dir = tmp.dir;
    for (int t = 0; t < time; t++)
    {

        // 상어의 이동.
        x += dx[dir];
        y += dy[dir];

        //만약 이동했는데 범위를 넘어간다면, 방향을 바꾸고 다시 되돌리기 필요함.
        if (x <= 0 || x > n_r || y <= 0 || y > n_c)
        {
            x -= dx[dir];
            y -= dy[dir];
            dir = inverse(dir);
            x += dx[dir];
            y += dy[dir];
        }
    }
    after_shark[x][y].push({time, dir, tmp.s_size});
}