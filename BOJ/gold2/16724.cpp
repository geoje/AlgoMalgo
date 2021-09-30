#include <cstdio> // For Test
#include <iostream>
using namespace std;
typedef pair<int, int> pii;

int n, m, groups;
char map[1000][1000];
pii parent[1000][1000];

pii find(pii x)
{
    pii &pp = parent[x.first][x.second];
    return pp == x ? x : pp = find(pp);
}
void join(pii x, pii y)
{
    x = find(x);
    y = find(y);

    parent[x.first][x.second] = y;
    groups--;
}

int main(int argc, char *argv[])
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen(argv[1], "r", stdin); // For Test

    /* Input */
    cin >> n >> m;
    groups = n * m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            parent[i][j] = {i, j};
        }

    /* Process */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            int ni = i, nj = j;
            if (map[i][j] == 'U')
                ni--;
            else if (map[i][j] == 'D')
                ni++;
            else if (map[i][j] == 'L')
                nj--;
            else if (map[i][j] == 'R')
                nj++;

            pii p = {i, j}, np = {ni, nj};
            if (find(p) != find(np))
                join(p, np);
        }

    /* Output */
    cout << groups << '\n';
    return 0;
}