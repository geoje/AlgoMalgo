#include <cstdio> // For Test
#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1e9;

// dp[length: 길이][value: 시작하는 수][visible: 0~9까지 사용된 수 비트마스킹]
ll n, dp[101][10][1 << 10];

ll func(int len, int val, int vis)
{
    // 0또는 9에서 호출 되었을 때 OutOfRange 방지
    if (val < 0 || val > 9)
        return 0;

    if (len == 1)
        return (vis | (1 << val)) == ((1 << 10) - 1) ? 1 : 0;

    ll &ret = dp[len][val][vis];
    if (ret != -1)
        return ret;

    vis |= (1 << val);
    return ret = (func(len - 1, val + 1, vis) + func(len - 1, val - 1, vis)) % MOD;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    fill_n(&dp[0][0][0], sizeof(dp) / sizeof(ll), -1);

    /* Process */
    int ans = 0;
    for (int i = 1; i <= 9; i++)
        ans = (ans + func(n, i, 0)) % MOD;

    /* Output */
    cout << ans << '\n';
    return 0;
}