#include <cstdio> // For Test
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n;
// first: A전봇대, second: B전봇대
pii line[100000];
int seq[100000] = {0};
int ans[100000];
stack<int> s;

int lower_bound(int left, int right, int target)
{
    int mid;
    while (left < right)
    {
        mid = (right + left) / 2;

        if (seq[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return right + 1;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> line[i].first >> line[i].second;
    sort(line, line + n);

    /* Process */
    int idx = 0;
    seq[0] = line[0].second;
    ans[0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (seq[idx] < line[i].second)
        {
            seq[++idx] = line[i].second;
            ans[i] = idx;
        }
        else
        {
            int m = lower_bound(0, idx, line[i].second) - 1;
            seq[m] = line[i].second;
            ans[i] = m;
        }
    }

    // 정답 도출해내기
    for (int i = n - 1; i >= 0; i--)
        if (ans[i] == idx)
            idx--;
        else
            s.push(line[i].first);

    /* Output */
    cout << s.size() << '\n';
    for (; !s.empty(); s.pop())
        cout << s.top() << '\n';
    return 0;
}