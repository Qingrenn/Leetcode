class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // 1971-1-1 -> day 1 -> Friday
        int month2day[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string num2week[8] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        
        for (int y = 1971; y < year; y++) {
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                day += 366;
            else 
                day += 365;
        }

        bool isrun = false;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            isrun = true;

        for (int m = 1; m < month; m++) {
            if (isrun && m == 2)    day += month2day[0];
            else
                day += month2day[m];
        }

        int weekday = ((day - 1) % 7 + 5) % 7;
        return num2week[weekday];
    }
};

/*
第一个周一：0000-1-1
*/