// #include <cstdio> // For Test
#include <iostream>
using namespace std;

int n;
bool stars[3072][6144] = {
    0,
};

void star(int m, int x, int y)
{
    if (m == 3)
    {
        stars[y][x + 2] = stars[y + 1][x + 1] = stars[y + 1][x + 3] = true;
        for (int i = 0; i < 5; i++)
            stars[y + 2][x + i] = true;
        return;
    }

    m /= 2;
    star(m, x + m, y);         // 중상
    star(m, x, y + m);         // 좌하
    star(m, x + m * 2, y + m); // 우하
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen(argv[1], "r", stdin); // For Test

    // Input
    cin >> n;

    // Process
    star(n, 0, 0);

    // Output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n * 2; j++)
            cout << (stars[i][j] ? '*' : ' ');
        cout << '\n';
    }
    return 0;
}