#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixGcd(n);

        long long current_max = 0;

        for (int i = 0; i < n; ++i) {
            current_max = max(current_max, (long long)nums[i]);
            prefixGcd[i] = std::gcd((long long)nums[i], current_max);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        long long total_sum = 0;
        int left = 0;
        int right = n-1;

        while(left < right) {
            total_sum += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return total_sum;
    }
};
