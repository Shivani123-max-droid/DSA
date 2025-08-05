class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // this is taking time complexity O((m+n) log(m+n))
        // for (int j = 0, i = m; j<n; j++){  
        //     nums1[i] = nums2[j];
        //     i++;
        // }
        // sort(nums1.begin(),nums1.end());

        // this will take O(m+n) time
        int i=m-1;
        int j=n-1;
        int idx=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[idx]=nums1[i];
                idx--;
                i--;
            } else{
                nums1[idx]=nums2[j];
                idx--;
                j--;
            }
        }
        while(j>=0){
            nums1[idx]=nums2[j];
            idx--;
            j--;
        }
    }
};