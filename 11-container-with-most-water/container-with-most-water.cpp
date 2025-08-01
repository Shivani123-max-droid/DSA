class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater=0;
        int s=0;
        int e=height.size()-1;
        while(s<e){
            int w = e-s;
            int ht = min(height[s],height[e]);
            int currWater = w *ht;
            maxWater = max(maxWater,currWater);
                        if (height[s] < height[e]) {
                s++;
            } else {
                e--;
            }
        }
        return maxWater;
    }
};
