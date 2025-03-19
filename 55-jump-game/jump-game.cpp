class Solution {
public:
    bool canJump(vector<int>& nums) {
        int scope = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > scope) return false;
            scope = max(scope, i + nums[i]);
        }
        return true;
    }
};