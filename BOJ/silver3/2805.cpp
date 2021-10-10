#include <cstdio> // For Test
#include <iostream>
using namespace std;
typedef long long ll;

int n;
ll m, tree[1000000];

bool promising(int height)
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
        if (tree[i] > height)
            sum += tree[i] - height;
    return sum >= m;
}

ll ParametricSearchLowerBound()
{
    int left = 0, right = 1e9, mid;
    while (left < right)
    {
        mid = (left + right + 1) / 2;
        if (promising(mid))
            left = mid;
        else
            right = mid - 1;
    }
    return left;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> tree[i];

    /* Process & Output */
    cout << ParametricSearchLowerBound() << '\n';
    return 0;
}