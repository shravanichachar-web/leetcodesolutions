#include <vector>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();

        if ( n < 3) {
            return n;
        }
        
        int bit_length = 0;
        int temp = n;
        while (temp > 0) {
            bit_length++;
            temp >>= 1;
        }

        return 1 << bit_length;
    }
};
