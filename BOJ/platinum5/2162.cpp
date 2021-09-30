#include <cstdio> // For Test
#include <iostream>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> line;

int n, parent[3000], count[3000], maxCounts = 1, groups;
line lines[3000];

int ccw(pii p1, pii p2, pii p3)
{
    int res = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second -
              p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;
    return res == 0 ? 0 : (res > 0 ? 1 : -1);
}
bool isIntersect(line l1, line l2)
{
    pii a = l1.first, b = l1.second, c = l2.first, d = l2.second;

    int r1 = ccw(a, b, c) * ccw(a, b, d),
        r2 = ccw(c, d, a) * ccw(c, d, b);

    if (r1 == 0 && r2 == 0)
    {
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        return a <= d && c <= b;
    }
    return r1 <= 0 && r2 <= 0;
}

int find(int x)
{
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}
void join(int x, int y)
{
    x = find(x);
    y = find(y);
    // if (x == y)
    //     return;

    count[y] += count[x];
    parent[x] = y;

    maxCounts = max(maxCounts, count[y]);
    groups--;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    int x1, y1, x2, y2;
    cin >> n;
    groups = n;
    fill_n(count, n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = {{x1, y1}, {x2, y2}};
        parent[i] = i;
    }

    /* Process */
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (find(i) != find(j) && isIntersect(lines[i], lines[j]))
                join(i, j);

    /* Output */
    cout << groups << '\n'
         << maxCounts << '\n';
    return 0;
}