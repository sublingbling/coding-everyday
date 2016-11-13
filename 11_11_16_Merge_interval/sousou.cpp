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
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> reval;
        if (0 == intervals.size()) return reval;
        
        sort(intervals.begin(),intervals.end(),compare());
        for (int i=0; i<intervals.size(); i++)
        {
            if(reval.empty() || reval[reval.size()-1].end<intervals[i].start)
            {
                reval.push_back(intervals[i]);
            }
            else
            {
                reval[reval.size()-1].end = std::max(reval[reval.size()-1].end,intervals[i].end);
            }
        }
        return reval;
    }

    struct compare{
        bool operator()(Interval &interval1, Interval &interval2)
        {
            return interval1.start < interval2.start;
        }    
    };
};
