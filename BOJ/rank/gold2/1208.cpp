#include <cstdio> // For Test
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
long long ans = 0;
vector<int> nums[2], sums[2];

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    int a;
    cin >> n >> s;
    for (int i = 0; i < n / 2; i++)
    {
        cin >> a;
        nums[0].push_back(a);
    }
    for (int i = n / 2; i < n; i++)
    {
        cin >> a;
        nums[1].push_back(a);
    }

    /* Process */
    // 2^n 가지의 부분 수열의 합 배열 만들기
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < (1 << nums[k].size()); i++)
        {
            int sum = 0;
            for (int j = 0; j < nums[k].size(); j++)
                if (i & (1 << j))
                    sum += nums[k][j];
            sums[k].push_back(sum);
        }
        sort(sums[k].begin(), sums[k].end());
    }

    // 연산
    int left = 0, right = sums[1].size() - 1, count[2] = {0};
    while (left < sums[0].size() && right >= 0)
    {
        int sum = sums[0][left] + sums[1][right];
        if (sum < s)
            left++;
        else if (sum > s)
            right--;
        else
        {
            long long s1 = sums[0][left++], c1 = 1;
            long long s2 = sums[1][right--], c2 = 1;
            for (; left < sums[0].size() && sums[0][left] == s1; c1++)
                left++;
            for (; right >= 0 && sums[1][right] == s2; c2++)
                right--;

            ans += c1 * c2;
        }
    }

    /* Output */
    if (s == 0)
        ans--;
    cout << ans << '\n';
    return 0;
}