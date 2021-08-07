// #include <cstdio> // For Test
#include <iostream>
using namespace std;

const int divisor = 1000000007;
long long n, temp[2][2];
long long basis[2][2] = {{1, 1}, {1, 0}};
long long fibo[2][2] = {{1, 0}, {0, 1}};

void fiboMul(long long (*a)[2], long long (*b)[2])
{
    temp[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % divisor;
    temp[1][0] = temp[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % divisor;
    temp[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % divisor;
    copy(&temp[0][0], &temp[0][0] + 4, &a[0][0]);
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
    for (; n; n /= 2)
    {
        // 결과 값에 추가
        if (n & 1)
            fiboMul(fibo, basis);

        // 기저 연산
        fiboMul(basis, basis);
    }

    // Output
    cout << fibo[1][0] << '\n';
    return 0;
}