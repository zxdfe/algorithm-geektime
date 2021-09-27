// https://leetcode-cn.com/problems/plus-one/
// 末尾加1不进位 : 直接加
// 末尾为9加1 进位 : 上一位继续判断是否加1进位;
// 如果首位也加1进位, 注意数组长度加1;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--)
        {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0) return digits;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};