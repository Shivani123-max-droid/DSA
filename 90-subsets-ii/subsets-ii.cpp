class Solution {
public:
    void printSubset(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets) {
        int n = nums.size();
        if (i == n) {
            allSubsets.push_back(ans);
            return;
        }

        // ✅ Include nums[i]
        ans.push_back(nums[i]);
        printSubset(nums, ans, i + 1, allSubsets);
        ans.pop_back();

        // ✅ Exclude nums[i] and skip all its duplicates
        int j = i + 1;
        while (j < n && nums[j] == nums[i]) {
            j++;
        }
        printSubset(nums, ans, j, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort so duplicates are adjacent
        vector<int> ans;
        vector<vector<int>> allSubsets;
        printSubset(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};
