class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinishTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                // Land first, then water
                int finishLand = landStartTime[i] + landDuration[i];
                int startWater = max(finishLand, waterStartTime[j]);
                int finishWater = startWater + waterDuration[j];
                minFinishTime = min(minFinishTime, finishWater);

                // Water first, then land
                int finishWaterFirst = waterStartTime[j]+ waterDuration[j];
                int startLand = max(finishWaterFirst, landStartTime[i]);
                int finishLandAfter = startLand + landDuration[i];
                minFinishTime = min(minFinishTime, finishLandAfter);
            }
        }
        return minFinishTime;
    }
};