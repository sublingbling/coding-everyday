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
private:
    struct compare{
        bool operator()(Interval &a, Interval &b){return a.start<b.start;}
    };

public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare());
        vector<Interval> v;
        for(auto a:intervals){
            if(v.empty()) v.push_back(a);
            else{
                if(v.back().end < a.start) v.push_back(a);
                else {
                    int start = v.back().start;
                    int end = max(v.back().end, a.end);
                    v.pop_back();
                    v.push_back(Interval(start,end));
                }
            }
        }
        return v;
    }
};
