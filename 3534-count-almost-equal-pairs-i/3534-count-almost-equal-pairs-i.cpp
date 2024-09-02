#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isValidPair(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);

        while (sa.length() < sb.length()) {
            sa = "0" + sa;
        }
        while (sb.length() < sa.length()) {
            sb = "0" + sb;
        }

        int diff_count = 0;
        int first_diff = -1;
        int second_diff = -1;

        for (int i = 0; i < sa.length(); ++i) {
            if (sa[i] != sb[i]) {
                diff_count += 1;
                if (diff_count == 1) {
                    first_diff = i;
                } else if (diff_count == 2) {
                    second_diff = i;
                } else {
                    return false;  // More than 2 differences
                }
            }
        }

        if (diff_count == 2) {
            swap(sa[first_diff], sa[second_diff]);
            if (sa == sb) {
                return true;
            }
        }

        return false;
    }

    int countPairs(std::vector<int>& nums) {
        int n = nums.size();
        int count_pairs = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j] || isValidPair(nums[i], nums[j])) {
                    count_pairs += 1;
                }
            }
        }

        return count_pairs;
    }
};
