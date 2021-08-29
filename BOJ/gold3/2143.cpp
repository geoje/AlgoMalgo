#include <cstdio> // For Test
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int t, n, m;
int a[1000], b[1000];
vector<int> sA, sB;
long long ans = 0;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> t >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    /* Process */
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int s = 0;
            for (int k = i; k <= j; k++)
                s += a[k];
            sA.push_back(s);
        }
    for (int i = 0; i < m; i++)
        for (int j = i; j < m; j++)
        {
            int s = 0;
            for (int k = i; k <= j; k++)
                s += b[k];
            sB.push_back(s);
        }
    sort(sA.begin(), sA.end());
    sort(sB.begin(), sB.end());

    // n 과 m을 포인팅 인덱스로 재사용
    n = 0;
    m = sB.size() - 1;
    while (n < sA.size() && m >= 0)
        if (sA[n] + sB[m] < t)
            n++;
        else if (sA[n] + sB[m] > t)
            m--;
        else
        {
            long long cntA = 1, cntB = 1;
            while (++n < sA.size() && sA[n - 1] == sA[n])
                cntA++;
            while (--m >= 0 && sB[m] == sB[m + 1])
                cntB++;
            ans += cntA * cntB;
        }

    /* Output */
    cout << ans << '\n';
    return 0;
}