#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// n: 보드 크기
//
int n, dir = 0, progCount = 1;
// 우, 상, 좌, 하
const pair<int, int> dirs[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
// ...[0]: 사과
// ...[1]: 뱀 몸통 위치
bool map[101][101][2] = {false};
// 뱀이 방향을 바꾸는 리스트
priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
// 뱀 몸통의 위치들
// front: 꼬리
// back: 머리
queue<pair<int, int>> snake;

void move()
{
    while (true)
    {
        pair<int, int> dest =
            make_pair(snake.back().first + dirs[dir].first,
                      snake.back().second + dirs[dir].second);

        // 다음 경로가 맵 밖이면 종료
        if (dest.first <= 0 || dest.second <= 0 || dest.first > n || dest.second > n)
            return;

        // 다음 경로가 몸통이면 종료
        if (map[dest.first][dest.second][1])
            return;

        // 머리를 늘려 목적지로 이동
        map[dest.first][dest.second][1] = true;
        snake.push(dest);

        // 목적지에 사과가 있다면
        if (map[dest.first][dest.second][0])
            // 사과 먹기
            map[dest.first][dest.second][0] = false;
        // 목적지에 사과가 없다면 꼬리 줄이기
        else
        {
            map[snake.front().first][snake.front().second][1] = false;
            snake.pop();
        }

        // 시간 추가 한 뒤 방향을 바꿔야 한다면 바꾸기
        pair<int, char> turn = pq.top();
        if (turn.first == progCount++)
        {
            pq.pop();
            // 왼쪽
            if (turn.second == 'L')
                dir = dir == 3 ? 0 : dir + 1;
            // 오른쪽
            else
                dir = dir == 0 ? 3 : dir - 1;
        }
    }
}

int main()
{
    // Input
    int k, l;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    { // 사과 입력
        int r, c;
        cin >> r >> c;
        map[r][c][0] = true;
    }
    cin >> l;
    for (int i = 0; i < l; i++)
    { // 방향 변환 입력
        int x;
        char c;
        cin >> x >> c;
        pq.push({x, c});
    }
    map[1][1][1] = true;
    snake.push({1, 1});

    // Process
    move();

    // Output
    cout << progCount << '\n';
    return 0;
}