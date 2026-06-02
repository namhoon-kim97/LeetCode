class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ret = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            for (int j = 0; j < waterStartTime.size(); j++) {
                int cur = 0;
                if (landStartTime[i] < waterStartTime[j]) {
                    if (landStartTime[i] + landDuration[i] > waterStartTime[j])
                        cur = min(waterStartTime[j] + waterDuration[j] +
                              landDuration[i], landStartTime[i] + landDuration[i] + waterDuration[j]);
                    else
                        cur = waterStartTime[j] + waterDuration[j];

                } else {
                    if (waterStartTime[j] + waterDuration[j] > landStartTime[i])
                        cur = min(landStartTime[i] + landDuration[i] +
                              waterDuration[j], waterStartTime[j] + waterDuration[j] + landDuration[i]);
                    else
                        cur = landStartTime[i] + landDuration[i];
                }
                ret = min(ret, cur);
            }
        }
        return ret;
    }
};