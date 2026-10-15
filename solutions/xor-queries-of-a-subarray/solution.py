class Solution:
    def xorQueries(self, arr: list[int], queries: list[list[int]]) -> list[int]:
        n = len(arr)
        prefix_xor = [0] * (n + 1)
        for i in range(n):
            prefix_xor[i + 1] = prefix_xor[i] ^ arr[i]
            
        result = []
        for query in queries:
            left, right = query
            result.append(prefix_xor[right + 1] ^ prefix_xor[left])
            
        return result