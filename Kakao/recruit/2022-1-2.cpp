#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(long long num)
{
    if (num == 0 || num == 1)
        return false;
    else if (num == 2 || num == 3)
        return true;

    for (long long i = 2; i <= num / 2; i++)
        if (num % i == 0)
            return false;
    return true;
}

int solution(int n, int k)
{
    int answer = 0;
    vector<long long> nums;

    // k진수로 변환
    while (n)
    {
        nums.push_back(n % k);
        n /= k;
    }
    reverse(nums.begin(), nums.end());

    // 0으로 분리하면서 소수 판별
    for (long long i : nums)
    {
        if (i == 0 && n > 0)
        {
            if (isPrime(n))
                answer++;
            n = 0;
        }
        else
            n = n * 10 + i;
    }

    // 마지막 숫자 체크
    if (n > 0)
    {
        if (isPrime(n))
            answer++;
        n = 0;
    }

    return answer;
}

int main()
{
    cout << solution(1000000, 3) << '\n';
    cout << solution(437674, 3) << '\n';
    cout << solution(110011, 10) << '\n';
    return 0;
}