class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double numSum = accumulate(nums.begin(), nums.end(), 0.0);

        double currSum = numSum;
        for(int &n: nums){
            pq.push(static_cast<double>(n));
        }

        double half = numSum/2;
        int k = 0;

        while(currSum > half){
            double top = pq.top();
            pq.pop();

            double op = top/2;
            pq.push(op);
            currSum -= top;
            currSum += op;
            k++;
        }

        return k;
    }
};