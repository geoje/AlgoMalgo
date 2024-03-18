#include <iostream>
using namespace std;

int LCS(string s1, string s2)
{
    // BOundary Condition
    int dp[2][1001] = {0};

    // Recursive Property
    for (int i = 1; i <= s1.length(); i++)
    {
        int cur = i & 1, prev = (i + 1) & 1;
        for (int j = 1; j <= s2.length(); j++)
            // 같을 경우 두 문자가 각각이 없을 때 s1과 s2의 길이에 1 더하기
            if (s1[i - 1] == s2[j - 1])
                dp[cur][j] = dp[prev][j - 1] + 1;
            // 다를 경우 s1 또는 s2 한쪽이 문자 1개 없을 경우 중 최대값을 가져오기
            else
                dp[cur][j] = max(dp[prev][j], dp[cur][j - 1]);
    }

    // Answer
    return dp[s1.length() & 1][s2.length()];
}

int main()
{
    // Input
    string s1, s2;
    cin >> s1 >> s2;

    // Process & Output
    cout << LCS(s1, s2);
    return 0;
}