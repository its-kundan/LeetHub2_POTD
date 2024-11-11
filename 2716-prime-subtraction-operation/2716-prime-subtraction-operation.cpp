

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int max_e = *max_element(nums.begin(), nums.end());
        vector<int> primes = generate_primes(max_e);

        int a = nearest(primes, nums[0]);
        if (a != -1) {
            nums[0] -= primes[a];
        }

        for (int i = 1; i < nums.size(); i++) {
            int b = nearest(primes, nums[i]);
            if (b == -1) {
                continue;
            }
            for (int j = b; j >= 0; j--) {
                int temp = nums[i] - primes[j];
                if (temp > nums[i - 1]) {
                    nums[i] = temp;
                    break;
                }
            }
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] >= nums[i]) {
                return false;
            }
        }
        return true;
    }

private:
    vector<int> generate_primes(int a) {
        vector<bool> checks(a + 1, true);
        checks[0] = checks[1] = false;

        for (int i = 2; i * i <= a; i++) {
            if (checks[i]) {
                for (int j = i * i; j <= a; j += i) {
                    checks[j] = false;
                }
            }
        }

        vector<int> primes;
        for (int i = 2; i <= a; i++) {
            if (checks[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

    int nearest(const vector<int>& primes, int target) {
        auto it = upper_bound(primes.begin(), primes.end(), target - 1);
        if (it == primes.begin()) {
            return -1;
        }
        return distance(primes.begin(), it - 1);
    }
};