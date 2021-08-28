// #include <cstdio> // For Test
#include <tuple>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, ans = 0, par[100001];
// tuple { 가중치, 큰번호, 작은번호 }
vector<tuple<int, int, int>> roads;

int find(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = find(par[x]);
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        par[i] = i;

    int a, b, c;
    while (m--)
    {
        cin >> a >> b >> c;
        roads.push_back({c, a, b});
    }
    sort(roads.begin(), roads.end());

    /* Process */
    for (auto road : roads)
    {
        if (n == 2)
            break;
        tie(c, a, b) = road;

        // 서로 연결되어 있을 경우 패스
        if (find(a) == find(b))
            continue;

        // 서로 연결
        par[find(a)] = find(b);

        // 정답 갱신
        ans += c;
        n--;
    }

    /* Output */
    cout << ans << '\n';
    return 0;
}