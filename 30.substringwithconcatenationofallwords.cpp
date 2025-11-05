#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty())
            return result;
        int m = s.size();
        int n = words.size();
        int k = words[0].size();
        if (k == 0)
            return result;
        long long totalLen = 1LL * n * k;
        if (totalLen > m)
            return result;

        unordered_map<string, int> target;
        target.reserve(n * 2);
        for (auto& w : words)
            target[w]++;

        for (int offset = 0; offset < k; ++offset) {
            int left = offset, right = offset;
            unordered_map<string, int> window;
            window.reserve(n * 2);
            while (right + k <= m) {
                string w = s.substr(right, k);
                right += k;
                if (target.find(w) == target.end()) {
                    window.clear();
                    left = right;
                } else {
                    window[w]++;
                    while (window[w] > target[w]) {
                        string w2 = s.substr(left, k);
                        window[w2]--;
                        left += k;
                    }
                    if (right - left == totalLen) {
                        result.push_back(left);
                        string w2 = s.substr(left, k);
                        window[w2]--;
                        left += k;
                    }
                }
            }
        }
        return result;
    }
};
