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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        bool placed = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.end) {
                placed = true;
            }
            
            if (placed) {
                result.push_back(intervals[i]);
            } else if (intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
            } else if (intervals[i].start > newInterval.end) {
                result.push_back(newInterval);
                result.push_back(intervals[i]);
                placed = true;
            } else if (newInterval.start <= intervals[i].start && newInterval.end < intervals[i].end) {
                newInterval.end = intervals[i].end;
            } else if (newInterval.start > intervals[i].start && newInterval.end >= intervals[i].end) {
                newInterval.start = intervals[i].start;
            }
        }
        
        if (!placed) {
            result.push_back(newInterval);
        }
        
        return result;
    }
};