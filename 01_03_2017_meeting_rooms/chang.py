# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def canAttendMeetings(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: bool
        """
        if intervals is None or len(intervals) == 0:
            return True
        
        intervals = sorted(intervals, key = lambda interval: interval.start)
        
        endTime = 0
        
        for interval in intervals:
            if endTime > interval.start:
                return False
            else:
                endTime = interval.end
                
        return True
