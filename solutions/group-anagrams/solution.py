from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        anagramGroups = defaultdict(list)
        
        for str in strs:
            sortedStr = ''.join(sorted(str))
            anagramGroups[sortedStr].append(str)
            
        return list(anagramGroups.values())