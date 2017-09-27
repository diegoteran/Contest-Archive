/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    Interval temp = Interval();
    bool merged = false;
    for (int i = 0; i < intervals.size(); i++) {
        if (newInterval.start > intervals[i].end) {
            res.push_back(intervals[i]);
            continue;
        }
        
        if (!merged && newInterval.end < intervals[i].start) {
            res.push_back(newInterval);
            i--;
            merged = true;
            continue;
        }
        
        int s = intervals[i].start;
        int e = intervals[i].end;
        if (!merged) {
            s = min(s, newInterval.start);
            e = max(e, newInterval.end);
            merged = true;
        }
        while (i + 1 < intervals.size() && e >= intervals[i+1].start) {
            e = max(e, intervals[++i].end);
        }
        res.push_back(Interval(s, e));
    }
    if (!merged)
        res.push_back(newInterval);
    return res;
}