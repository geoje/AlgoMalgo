#include <cstdio> // For Test
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

struct line
{
    int from, to;
    double dis;
};

struct compareLine
{
    bool operator()(const line &a, const line &b)
    {
        return a.dis > b.dis;
    }
};

int n, par[100];
pair<double, double> stars[100];
priority_queue<line, vector<line>, compareLine> pq;
double dis, ans = 0;

int findUnion(int x)
{
    return par[x] == x ? x : (par[x] = findUnion(par[x]));
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> stars[i].first >> stars[i].second;
        for (int j = 0; j < i; j++)
            pq.push({j, i, sqrt(pow(stars[j].first - stars[i].first, 2) + pow(stars[j].second - stars[i].second, 2))});
        par[i] = i;
    }

    /* Process */
    while (--n)
    {
        while (findUnion(pq.top().from) == findUnion(pq.top().to))
            pq.pop();

        par[pq.top().from] = findUnion(pq.top().to);
        ans += pq.top().dis;
        pq.pop();
    }

    /* Output */
    cout.precision(2);
    cout << fixed << ans << '\n';
    return 0;
}