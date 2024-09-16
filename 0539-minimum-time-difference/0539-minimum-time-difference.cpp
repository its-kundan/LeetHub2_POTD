class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        std::vector<bool> buckets(1440, false);
        int minTime = 1440, maxTime = -1;

        for (const auto& time : timePoints) {
            int hour = (time[0] - '0') * 10 + (time[1] - '0');
            int minute = (time[3] - '0') * 10 + (time[4] - '0');
            int minuteOfDay = hour * 60 + minute;

            if (buckets[minuteOfDay]) {
                return 0;
            }

            buckets[minuteOfDay] = true;
            minTime = min(minTime, minuteOfDay);
            maxTime = max(maxTime, minuteOfDay);
        }

        int minDiff = min(1440 - maxTime + minTime, maxTime - minTime);
        int prev = minTime;

        for (int i = minTime + 1; i <= maxTime; ++i) {
            if (buckets[i]) {
                minDiff = min(minDiff, i - prev);
                prev = i;
            }
        }

        return minDiff;
    }
};