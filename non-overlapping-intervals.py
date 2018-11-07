# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e
import operator

class Solution:
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        ans=0
        prev=0
        intervals.sort(key=lambda x: x.start)
        for i in range(1, len(intervals)):
            if intervals[i].start<intervals[prev].end:
                if intervals[i].end<intervals[prev].end:
                    prev=i
                ans+=1
            else:
                prev=i
        return ans
                
        
