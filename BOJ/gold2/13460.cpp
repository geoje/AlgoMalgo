// #include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

struct point
{
    int r, c;
    point operator+(point const &a)
    {
        return {r + a.r, c + a.c};
    }
    bool operator==(point const &a)
    {
        return r == a.r && c == a.c;
    }
    bool operator!=(point const &a)
    {
        return r != a.r || c != a.c;
    }
};

struct node
{
    int count;
    point red, blue;
};

struct compare
{
    bool operator()(node const &a, node const &b)
    {
        return a.count > b.count;
    }
};

int n, m;
char board[10][10];
// [Red Row][Red Col][Blue Row][Blue Col]
bool visited[10][10][10][10] = {0};
priority_queue<node, vector<node>, compare> pq;

const point dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    point red, blue, next;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            // board[i][j] 에는 R 과 B 를 기록하지 않고 . 으로 기록함
            // 나중 체크할 때는 board와 공 위치를 다 고려함
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                board[i][j] = '.';
                red = {i, j};
            }
            else if (board[i][j] == 'B')
            {
                board[i][j] = '.';
                blue = {i, j};
            }
        }

    // Process && Success Output
    pq.push({0, red, blue});
    while (!pq.empty())
    {
        node cur = pq.top();
        pq.pop();

        // 일단 횟수 1 증가 시키고 만약 11회차일 경우 그만하기
        if (++cur.count > 10)
            break;

        // 이미 계산한 위치일 경우 패스
        if (visited[cur.red.r][cur.red.c][cur.blue.r][cur.blue.c])
            continue;
        visited[cur.red.r][cur.red.c][cur.blue.r][cur.blue.c] = true;

        // 모든 방향 보기
        for (auto dir : dirs)
        {
            bool crash = false, success = false;
            red = cur.red;
            blue = cur.blue;

            // 우선 빨간공 부터 빈 공간인 곳을 계속 움직임
            while ((next = red + dir) != blue && board[next.r][next.c] == '.')
                red = next;

            // 빨간공이 구멍으로 갔으면 끝 하지만, 동시에 빠져도 실패니 파란공도 보기위해 success 변수 씀
            if (board[next.r][next.c] == 'O')
            {
                red = {0, 0};
                success = true;
            }
            // 빨간공이 파란공과 충돌 했으면 파란공 보내고 다시 이동하기 위해 충돌했다고 표시
            else if (next == blue)
                crash = true;

            // 이제 파란공 움직임
            while ((next = blue + dir) != red && board[next.r][next.c] == '.')
                blue = next;

            // 파란공이 구멍으로 들어갈 경우 망함
            if (board[next.r][next.c] == 'O')
                continue;
            // 만약 파란공 구멍 안들어가고 아까 빨간공 구멍에 들어갔을 경우 성공!!!!
            else if (success)
            {
                cout << cur.count << '\n';
                return 0;
            }

            // 아까 빨간공이 파란공이랑 충돌했을 경우 빨간공 다시 보냄
            // 이 때, 빨간공은 파란공이 이동한 경로를 움직이므로 구멍에 들어갔는지는 체크안함
            if (crash)
                while ((next = red + dir) != blue && board[next.r][next.c] == '.')
                    red = next;

            // 이동한 공들과 count를 1 증가한 값(뽑을떄 증가 시켜 둠)으로 큐에 추가
            pq.push({cur.count, red, blue});
        }
    }

    // Fail Output
    cout << "-1\n";
    return 0;
}