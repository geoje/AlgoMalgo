#include <cstdio> // For Test
#include <iostream>
using namespace std;

const int INF = 2500;

string str;
bool isPalindrome[2500][2500];
int dp[2500] = {0};

int palindrome(int a, int b)
{
    // 메모이제이션 (a와 b가 같을 때와 1 차이 나서 범위 밖일 때는 Boundary Condition)
    if (dp[a][b] != -1)
        return dp[a][b];

    // 내가 팰린드롬 일 경우
    if (str[a] == str[b] && palindrome(a + 1, b - 1) == 1)
        return dp[a][b] = 1;

    // 아닐 경우 2개로 쪼갠 모든 경우를 보고 최소값 반환
    int result = INF;
    for (int m = a; m < b; m++)
        result = min(result, palindrome(a, m) + palindrome(m + 1, b));

    return dp[a][b] = result;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> str;

    // Boundary Condition
    isPalindrome[0][0] = 1;
    for (int i = 1; i < str.length(); i++)
        isPalindrome[i][i - 1] = isPalindrome[i][i] = 1;

    /* Process */

    /* Output */
    cout
        << palindrome(0, str.length() - 1);
    return 0;
}