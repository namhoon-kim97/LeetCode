class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ret = INT_MAX;
        
        for (int i = 0; i < landStartTime.size(); i++) {
            int landStart = landStartTime[i];
            int landLen = landDuration[i];
            int landEnd = landStart + landLen;

            for (int j = 0; j < waterStartTime.size(); j++) {
                int waterStart = waterStartTime[j];
                int waterLen = waterDuration[j];
                int waterEnd = waterStart + waterLen;

                // 시나리오 1: Land 먼저 수행 후 Water 수행
                int case1_waterStart = max(landEnd, waterStart);
                int case1_end = case1_waterStart + waterLen;

                // 시나리오 2: Water 먼저 수행 후 Land 수행
                int case2_landStart = max(waterEnd, landStart);
                int case2_end = case2_landStart + landLen;

                int cur = min(case1_end, case2_end);
                ret = min(ret, cur);
            }
        }
        return ret;
    }
};