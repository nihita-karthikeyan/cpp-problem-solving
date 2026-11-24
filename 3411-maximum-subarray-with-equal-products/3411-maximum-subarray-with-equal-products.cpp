#include <numeric>
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;

        for(int i =0; i < n; i++) {
            long long prod = 1;
            int g = 0 ;
            long long l =1;

            for(int j =i; j < n ;j++) {
                prod *= nums[j];
                g = std::gcd(g, nums[j]);
                l = std::lcm<long long>(l, nums[j]);
                if (prod == l * g) {
                    ans = max (ans,j - i + 1);
                 }

                 if (prod > 1000000000000LL) break;
            }
        }
        return ans;
    }
};