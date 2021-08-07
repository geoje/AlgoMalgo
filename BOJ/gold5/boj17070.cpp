// #include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

struct pipe
{
    // dir // 0: 가로, 1: 세로, 2: 대각선
    int r, c, dir;
};

int n, ans = 0, map[17][17];
queue<pipe> nodes;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];

    // Process
    int r, c, dir;
    nodes.push({1, 2, 0});
    while (!nodes.empty())
    {
        pipe node = nodes.front();
        nodes.pop();
        r = node.r;
        c = node.c;
        dir = node.dir;

        // 파이프가가 집 밖을 나갔거나 벽과 곂쳤다면 진행 불가
        if (r > n || c > n || map[r][c])
            continue;
        // 대각선 파이프는 위 아래까지 봐주기
        if (dir == 2 && (map[r - 1][c] || map[r][c - 1]))
            continue;

        // 도착했다면 경우의 수 1 증가
        if (r == n && c == n)
            ans++;

        // 가로 이동 (-, \)
        if (dir == 0 || dir == 2)
            nodes.push({r, c + 1, 0});

        // 세로 이동 (|, \)
        if (dir == 1 || dir == 2)
            nodes.push({r + 1, c, 1});

        // 대각선 이동 (-, |, \)
        nodes.push({r + 1, c + 1, 2});
    }

    // Output
    cout << ans << '\n';
    return 0;
}