#include <cstdio> // For Test
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int n, bound = 2e9 + 1, potion[100000];
pair<int, int> ans;

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> potion[i];

    /* Process */
    int sum, left = 0, right = n - 1;
    while (left < right)
    {
        sum = abs(potion[left] + potion[right]);
        if (sum < bound)
        {
            ans = {potion[left], potion[right]};
            bound = sum;
        }

        if (abs(potion[left]) > abs(potion[right]))
            left++;
        else
            right--;
    }

    /* Output */
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}