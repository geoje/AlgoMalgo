#include <cstdio> // For Test
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> point;
typedef pair<point, point> line;

int n;

int ccw(point p1, point p2, point p3)
{
    ll res = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second -
             p1.second * p2.first - p2.second * p3.first - p3.second * p1.first;
    return res == 0 ? 0 : (res > 0 ? 1 : -1);
}
bool isIntersect(line l1, line l2)
{
    point a = l1.first, b = l1.second, c = l2.first, d = l2.second;
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

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    line l[2];
    int a, b, c, d;
    for (int i = 0; i < 2; i++)
    {
        cin >> a >> b >> c >> d;
        l[i] = {{a, b}, {c, d}};
    }

    /* Process && Output */
    cout << isIntersect(l[0], l[1]) << '\n';
    return 0;
}