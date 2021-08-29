#include <cstdio> // For Test
#include <stack>
#include <iostream>
using namespace std;

int n, arr[1000000], lis[1000000];
// first: pos, second: value
pair<int, int> ans[1000000];
stack<int> s;

int lower_bound(int left, int right, int target)
{
    int mid;
    while (left < right)
    {
        mid = (right + left) / 2;

        if (lis[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return right + 1;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    /* Process */
    int pLis = 0, pArr = 0;
    lis[0] = arr[0];
    ans[0] = {0, arr[0]};

    while (++pArr < n)
        if (lis[pLis] < arr[pArr])
        {
            lis[++pLis] = arr[pArr];
            ans[pArr] = {pLis, arr[pArr]};
        }
        else
        {
            int pos = lower_bound(0, pLis, arr[pArr]) - 1;
            lis[pos] = arr[pArr];
            ans[pArr] = {pos, arr[pArr]};
        }

    for (int i = n - 1; i >= 0; i--)
        if (ans[i].first == pLis)
        {
            s.push(ans[i].second);
            pLis--;
        }

    /* Output */
    cout << s.size() << '\n';
    for (; !s.empty(); s.pop())
        cout << s.top() << ' ';
    return 0;
}