/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

bool cmp(const Interval& a, const Interval& b) {
            if (a.end != b.end)
                return a.end < b.end;
            return a.start < b.start;
    }
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        for(int i = 1; i < n; i++){
            Interval prev = intervals[i - 1];
            Interval curr = intervals[i];
            cout << curr.start << ' ' << prev.end << endl;
            if(curr.start < prev.end) return false;
        }
        return true;
    }
};
