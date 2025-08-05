class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1, n = nums.size();

        // Step 1: Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse and return
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;  // ✅ CRITICAL: must return here to avoid out-of-bounds access
        }

        // Step 3: Swap with next greater element
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
