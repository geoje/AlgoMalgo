/*
 * @lc app=leetcode id=1768 lang=java
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
    public String mergeAlternately(String word1, String word2) {
        String answer = "";
        int maxLen = Math.max(word1.length(), word2.length());

        for (int i = 0; i < maxLen; i++) {
            if (i < word1.length()) {
                answer += word1.charAt(i);
            }
            if (i < word2.length()) {
                answer += word2.charAt(i);
            }
        }

        return answer;
    }
}
// @lc code=end

