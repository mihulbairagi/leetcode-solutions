class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        int n = arr.size();
        std::vector<int> prefixXor(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }
        
        std::vector<int> result;
        result.reserve(queries.size());
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            result.push_back(prefixXor[right + 1] ^ prefixXor[left]);
        }
        
        return result;
    }
};