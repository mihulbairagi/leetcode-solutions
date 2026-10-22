#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramGroups;
        
        for (const std::string& str : strs) {
            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(str);
        }
        
        std::vector<std::vector<std::string>> result;
        for (auto const& [key, val] : anagramGroups) {
            result.push_back(val);
        }
        
        return result;
    }
};