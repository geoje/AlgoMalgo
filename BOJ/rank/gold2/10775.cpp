#include <cstdio> // For Test
#include <algorithm>
#include <iostream>
using namespace std;

int g, p, airplane[100001], par[100001], ans = 0;

int findUnion(int x)
{
    return par[x] == x ? x : (par[x] = findUnion(par[x]));
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> g >> p;
    fill_n(par, 100001, g);
    for (int i = 0; i <= g; i++)
        par[i] = i;
    for (int i = 1; i <= p; i++)
        cin >> airplane[i];

    /* Process */
    for (int i = 1; i <= p; i++)
    {
        // 비행기가 착륙할 수 있는 위치를 알려주는데 1이상이면 가능한 것
        int gate = findUnion(airplane[i]);
        if (gate)
        {
            ans++;
            par[gate] = findUnion(gate - 1);
        }
        else
            break;
    }

    /* Output */
    cout << ans << '\n';
    return 0;
}