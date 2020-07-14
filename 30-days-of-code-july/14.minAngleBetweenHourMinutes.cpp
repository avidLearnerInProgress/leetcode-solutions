class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour < 0 or minutes < 0 or hour > 12 or minutes > 60) return 0.0;
        
        if(hour == 12) hour = 0;
        if(minutes == 60) {
            minutes = 0;
            hour += 1;
            if(hour > 12) hour -= 12;
        }
        
        /*
        Minute hand moves => 6 degree per minute
        Hour hand moves => 0.5 degree per minute
        
        In h hour and m minutes;
        Hour hand moves => (hour * 60 + minutes) * 0.5
        Minute hand moves => (hour * 60 + minutes) * 6
        */
        auto hour_angle = 0.5 * (hour * 60 + minutes);
        auto minute_angle = 6 * minutes;
        auto angle = abs(hour_angle - minute_angle);
        
        return min(360 - angle, angle);
    }
};
