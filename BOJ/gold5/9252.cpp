// #include <cstdio> // For Test
#include <algorithm>
#include <iostream>
using namespace std;

string s1, s2, ans;
int dp[1001][1001] = {0};

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> s1 >> s2;

    /* Process */
    // DP 테이블 완성
    int i, j;
    for (i = 1; i <= s1.length(); i++)
        for (j = 1; j <= s2.length(); j++)
            // 같을 경우 두 문자가 각각이 없을 때 s1과 s2의 길이에 1 더하기
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            // 다를 경우 s1 또는 s2 한쪽이 문자 1개 없을 경우 중 최대값을 가져오기
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    // 문자열 역추적
    i--;
    j--;
    while (dp[i][j])
        // 위로 이동
        if (dp[i][j] == dp[i - 1][j])
            i--;
        // 왼쪽으로 이동
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        // 문자열 추가하고 대각선으로 이동
        else
        {
            i--;
            j--;
            ans.push_back(s1[i]);
        }
    reverse(ans.begin(), ans.end());

    /* Output */
    cout << dp[s1.length()][s2.length()] << '\n'
         << ans << '\n';
    return 0;
}