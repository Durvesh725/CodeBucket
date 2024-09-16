class Solution {
public:
    int parseTime(string &s){
        int hr = stoi(s.substr(0, 2));
        int min = stoi(s.substr(3, 2));
        return (hr * 60) + min;
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();

        int firstTime = parseTime(timePoints[0]);
        int prevTime = firstTime;
        int currTime = 0;
        int minDiff = INT_MAX;

        for(int i = 1; i < n; i++){
            currTime = parseTime(timePoints[i]);
            minDiff = min(minDiff, currTime - prevTime);
            prevTime = currTime;
        }

        int lastTime = parseTime(timePoints.back());
        int cyclic_time = (firstTime + 1440) - lastTime;
        minDiff = min(minDiff, cyclic_time);

        return minDiff;
    }
};