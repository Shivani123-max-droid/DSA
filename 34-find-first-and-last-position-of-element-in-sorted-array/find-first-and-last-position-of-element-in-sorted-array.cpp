class Solution {
public:
    int first_position(vector<int> nums, int target, int n) {
        int result = -1;
        int start = 0, end = n;

        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] == target) {
                result = mid;
                end = mid - 1;
            }else if(nums[mid] < target) {
                start = mid + 1;
            }else end = mid - 1;
        }
        return result;
    }

    int last_position(vector<int> nums, int target, int n) {
        int result = -1;
        int start = 0, end = n;

        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] == target) {
                result = mid;
                start = mid + 1;
            }else if(nums[mid] > target) {
                end = mid - 1;
            }else start = mid + 1;
        }
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int fp = first_position(nums, target, n);
        int lp = last_position(nums, target, n);
        return {fp, lp};
    }
};