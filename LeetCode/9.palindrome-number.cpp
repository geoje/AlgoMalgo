// @before-stub-for-debug-begin
#include <vector>
#include <string>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        // Edge case
        if (x < 0) return false;

        // Init
        long rev = 0;
        int it = x;

        for (; it; it /= 10) {
            rev *= 10;
            rev += it % 10;
        }

        return x == rev;
    }
};
// @lc code=end

