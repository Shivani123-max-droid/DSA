class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue <int> pq ( piles.begin(), piles.end() );
        int stoneSum = 0;
        while( k-- ){
            int biggest = pq.top();
            pq.pop();
            pq.push( biggest - floor( biggest / 2 ) );
        }
        while( !pq.empty() ){
            stoneSum += pq.top();
            pq.pop();
        }
        return stoneSum;
    }
};