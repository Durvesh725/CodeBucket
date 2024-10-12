class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        start_times = sorted(i[0] for i in intervals)
        end_time = sorted(i[1] for i in intervals)
        end, grp = 0, 0

        for start in start_times:
            if start > end_time[end]:
                end += 1;
            else:
                grp += 1;

        return grp;
        