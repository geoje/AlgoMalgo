// #include <cstdio> // For Test
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

struct node
{
    int time, pos;
};

int n, k, prevTime = -1, counts[2][100001] = {0};

queue<node> nodes;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> k;

    // Process
    int *curCounts, *futureCounts;
    counts[0][n] = 1;
    nodes.push({0, n});
    while (!nodes.empty())
    {
        auto node = nodes.front();
        nodes.pop();

        // 새로운 시간을 탐색 시작할 때
        if (node.time > prevTime)
        {
            // 새로 채울 곳 횟수 초기화
            curCounts = counts[node.time % 2];
            futureCounts = counts[!(node.time % 2)];
            fill_n(futureCounts, 100001, 0);

            // 이전 시간 업데이트
            prevTime = node.time;

            // 찾았을 경우 탐색 종료
            if (curCounts[k] > 0)
                break;
        }

        // 걷기
        node.time++;
        if (node.pos > 0)
        {
            if (futureCounts[node.pos - 1] == 0)
                nodes.push({node.time, node.pos - 1});
            futureCounts[node.pos - 1] += curCounts[node.pos];
        }
        if (node.pos < k && node.pos < 100000)
        {
            if (futureCounts[node.pos + 1] == 0)
                nodes.push({node.time, node.pos + 1});
            futureCounts[node.pos + 1] += curCounts[node.pos];
        }
        // 순간이동
        if (node.pos < k && node.pos <= 50000)
        {
            if (futureCounts[node.pos * 2] == 0)
                nodes.push({node.time, node.pos * 2});
            futureCounts[node.pos * 2] += curCounts[node.pos];
        }
    }

    // Output
    cout << prevTime << '\n'
         << curCounts[k] << '\n';
    return 0;
}