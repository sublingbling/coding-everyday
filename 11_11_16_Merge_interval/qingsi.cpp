/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    static bool _lt(Interval a, Interval b) {
        return a.start < b.start;
    }
    void _sortIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), _lt);
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int sz = intervals.size();
        if (sz <= 1) {
            return intervals;
        }
        _sortIntervals(intervals);
        vector<Interval> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < sz; i++) {
            if ((res.back()).end >= intervals[i].start) {
                (res.back()).end = max((res.back()).end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
