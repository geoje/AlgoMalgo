#include <cstdio> // For Test
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

int k, n;
ll lan[10000];

bool isMakeable(ll length)
{
    ll num = 0;
    for (int i = 0; i < k; i++)
        num += lan[i] / length;
    return num >= n;
}

ll ParametricSearchLowerBound()
{
    ll left = 1, right = pow(2, 31) - 1, mid;
    while (left < right)
    {
        mid = (left + right + 1) / 2;
        if (isMakeable(mid))
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
    cin >> k >> n;
    for (int i = 0; i < k; i++)
        cin >> lan[i];

    /* Process & Output */
    cout << ParametricSearchLowerBound() << '\n';
    return 0;
}