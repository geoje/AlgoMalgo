#include <cstdio> // For Test
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

struct planet
{
    int num;
    ll pos[3];
};

struct turnnel
{
    int a, b;
    ll cost;
};

int n, posType = 0, par[100000];
planet planets[100000];
ll ans = 0;

bool cmpPlanet(const planet &a, const planet &b)
{
    return a.pos[posType] < b.pos[posType];
}
struct cmpTurnnel
{
    bool operator()(turnnel &a, turnnel &b)
    {
        return a.cost > b.cost;
    }
};

priority_queue<turnnel, vector<turnnel>, cmpTurnnel> pq;

int findUnion(int x)
{
    if (par[x] == x)
        return x;
    else
        return par[x] = findUnion(par[x]);
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    int x, y, z;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        planets[i] = {par[i] = i, x, y, z};
    }

    /* Process */
    for (; posType < 3; posType++)
    {
        sort(planets, planets + n, cmpPlanet);
        for (int i = 1; i < n; i++)
            pq.push({planets[i].num, planets[i - 1].num, planets[i].pos[posType] - planets[i - 1].pos[posType]});
    }

    while (n > 1)
    {
        turnnel t = pq.top();
        pq.pop();
        if (pq.empty())
            break;

        // 이미 연결되어 있을 경우 패스
        if (findUnion(t.a) == findUnion(t.b))
            continue;
        par[findUnion(t.a)] = findUnion(t.b);

        // 연결 후 정답 갱신
        ans += t.cost;
        n--;
    }

    /* Output */
    cout << ans << '\n';
    return 0;
}