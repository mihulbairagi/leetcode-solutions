class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals.sort(key=lambda x: x[0])

        merged = []
        merged.append(intervals[0])

        for i in range(1, len(intervals)):
            current_interval = intervals[i]
            last_merged_interval = merged[-1]

            if current_interval[0] <= last_merged_interval[1]:
                last_merged_interval[1] = max(last_merged_interval[1], current_interval[1])
            else:
                merged.append(current_interval)
        
        return merged