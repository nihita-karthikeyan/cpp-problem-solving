class Solution {
  public:
        bool isVowel (char c ) {
            c = tolower(c);
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        }
        
        vector <int> countVowels (string &s, vector <vector<int>> &queries) {
            int n = s.length();
            vector<int> prefix(n + 1 , 0);
            
            for (int i = 0; i < n ; i++) {
                prefix [i +1 ] = prefix[i] + (isVowel(s[i])? 1 : 0);
            }
            vector<int> ans;
            ans.reserve(queries.size());
            
            for (const auto &q : queries) {
                int l = q[0];
                int r = q[1];
                ans.push_back(prefix[r + 1] - prefix[l]);
            }
            return ans;
        }
    };
