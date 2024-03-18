// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int n, ans = 0, sum = 2, l = 1, r = 2;
bool parr[4000001];

int next(int num)
{
    do
        num++;
    while (num <= n && !parr[num]);
    return num;
}

void Eratos()
{
    if (n <= 1)
        return;

    fill_n(parr, 4000001, true);

    for (int i = 2; i * i <= n; i++)
        if (parr[i])
            for (int j = i * i; j <= n; j += i)
                parr[j] = false;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n;

    /* Process */
    Eratos();

    while (true)
    {
        if (sum < n)
        {
            r = next(r);
            if (r > n)
                break;

            sum += r;
        }
        else if (sum > n)
        {
            l = next(l);
            sum -= l;
        }
        else
        {
            ans++;
            l = next(l);
            r = next(r);
            if (r > n)
                break;

            sum = sum + r - l;
        }
    }

    /* Output */
    cout << ans << '\n';
    return 0;
}