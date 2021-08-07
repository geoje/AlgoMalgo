// #include <cstdio> // For Test
#include <queue>
#include <iostream>
using namespace std;

const int MAX = 1e6;
int n, k, dist[MAX + 1] = {0};
int times = -1, count = 0;
queue<int> q;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n >> k;

    // Process
    q.push(n);
    while (!count)
    {
        int size = q.size();
        while (size--)
        {
            int x = q.front();
            q.pop();

            if (x == k)
                count++;
            for (int nx : {x - 1, x + 1, x * 2})
            {
                if (nx < 0 || nx > MAX)
                    continue;
                if (dist[nx] && dist[nx] != dist[x] + 1)
                    continue;

                q.push(nx);
                dist[nx] = dist[x] + 1;
            }
        }
        times++;
    }

    cout << times << '\n'
         << count << '\n';
    // Output
    return 0;
}