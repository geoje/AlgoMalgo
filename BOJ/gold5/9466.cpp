// #include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

int n, ans, want[100001];
bool visitied[100001];
queue<int> q;

void dfs(int s)
{
    visitied[s] = true;
    q.push(s);

    // 내가 좋아하는 사람이 탐색 선택이 안되었을 때 탐색 시작
    if (!visitied[want[s]])
        dfs(want[s]);
    // 내가 좋아하느 사람이 현재 사이클에서 탐색중이면 그사람을 기점으로 그룹 생성
    else
    {
        // 내가 원하는 학생 즉, 사이클의 시작이 나올 때 까지 기존 연결 학생 제거 후
        // 원하는 학생이 발견 되면 사이클이 되는거니 정답에 반영
        // 아닐 경우 그냥 끝까지 큐 빼서 원상복귀 시킴
        while (!q.empty())
        {
            if (q.front() == want[s])
            {
                ans -= q.size();
                // 이 코드는 없어도 되지만 q.front() == want[s] 비교를 q 개수만큼 진행하지 않기 위해 둠
                while (!q.empty())
                    q.pop();
                return;
            }
            q.pop();
        }
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    int t;
    cin >> t;
    while (t--)
    {
        /* Input */
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> want[i];
        fill_n(visitied, n + 1, 0);
        ans = n;

        /* Process */
        for (int i = 1; i <= n; i++)
            if (!visitied[i])
                dfs(i);

        /* Output */
        cout << ans << '\n';
    }
    return 0;
}