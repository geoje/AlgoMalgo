#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> set;
    for (int num : nums)
        set.insert(num);
    return min(nums.size() / 2, set.size());
}

int main()
{
    int n;
    vector<int> nums;
    while (cin >> n)
        nums.push_back(n);

    cout << solution(nums) << '\n';
    return 0;
}