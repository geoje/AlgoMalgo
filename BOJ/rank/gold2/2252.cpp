// #include <cstdio> // For Test
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int n, m;
vector<vector<int>> tall;
vector<int> inDegree, answer;

void TopologySort()
{
    queue<int> q;

    // 처음에 진입 차수가 0인 수를 넣음
    for (int i = 1; i <= n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    // 큐가 빌 때 까지 pop한 것을 결과에 넣고 쭉 진행
    while (!q.empty())
    {
        // 큐에서 뺀 뒤 정답에 넣기
        int x = q.front();
        q.pop();
        answer.push_back(x);

        // 연결되어있는 다음 노드들의 차수를 1 감소 후 0 이 되었을 경우 큐에 넣기
        for (int next : tall[x])
            if (--inDegree[next] == 0)
                q.push(next);
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> m;
    tall.resize(n + 1);
    inDegree.assign(n + 1, 0);

    int a, b;
    while (m--)
    {
        cin >> a >> b;
        tall[a].push_back(b);
        inDegree[b]++;
    }

    // Process
    TopologySort();

    // Output
    for (int ans : answer)
        cout << ans << ' ';
    cout << '\n';
    return 0;
}