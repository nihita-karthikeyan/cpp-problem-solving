class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
       int maxFactor = 0;
        long long minPrice = LLONG_MAX;
        
        for (const auto& item : items) {
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, (long long)item[1]);
        }
        
        // 1. Count frequency of each factor
        vector<int> multCount(maxFactor + 1, 0);
        for (const auto& item : items) {
            multCount[item[0]]++;
        }
        
        // 2. Sieve-style accumulation: multCount[f] = total items whose factor is a multiple of f
        for (int f = 1; f <= maxFactor; ++f) {
            if (multCount[f] == 0) continue;
            for (int m = 2 * f; m <= maxFactor; m += f) {
                multCount[f] += multCount[m];
            }
        }
        
        // 3. Sort items by price ascending
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        long long rem = budget;
        long long ans = 0;
        
        // 4. Greedily take 2-for-1 deals cheaper than buying 2 single cheapest items
        for (const auto& item : items) {
            long long price = item[1];
            if (price >= 2 * minPrice) break;
            
            long long cap = multCount[item[0]] - 1; // exclude item i itself (i != j)
            long long take = min(cap, rem / price);
            ans += take * 2;
            rem -= take * price;
        }
        
        // 5. Spend leftover budget on the cheapest item
        ans += rem / minPrice;
        
        return (int)ans;  
    }
};