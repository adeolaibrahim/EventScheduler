#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
public:
    void set(int h, int m) {
        hours = h;
        if (m < 0) m = 0;
        if (m > 59) m = m % 60; // correct minutes
        minutes = m;
    }
    void print() {
        cout << setw(2) << setfill('0') << hours << ":"
             << setw(2) << setfill('0') << minutes;
    }
};

class Date {
private:
    int year, month, day;
    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    int daysInMonth(int m, int y) {
        if (m == 2) return isLeapYear(y) ? 29 : 28;
        if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
        return 31;
    }
public:
    void set(int y, int m, int d) {
        if (y < 1970) y = 1970;
        if (y > 2050) y = 2050;
        if (m < 1) m = 1;
        if (m > 12) m = 12;
        int maxDay = daysInMonth(m, y);
        if (d < 1) d = 1;
        if (d > maxDay) d = maxDay;
        year = y; month = m; day = d;
    }
    void print() {
        cout << year << "-"
             << setw(2) << setfill('0') << month << "-"
             << setw(2) << setfill('0') << day;
    }
};

class Event {
private:
    string title;
    Date date;
    Time startTime, endTime;
public:
    void setTitle(string t) { title = t; }
    void setDate(int y, int m, int d) { date.set(y, m, d); }
    void setStart(int h, int m) { startTime.set(h, m); }
    void setEnd(int h, int m) { endTime.set(h, m); }
    void print() {
        cout << "Event: " << title << endl;
        cout << "Date: "; date.print(); cout << endl;
        cout << "Start: "; startTime.print(); cout << endl;
        cout << "End: "; endTime.print(); cout << endl;
    }
};

int main() {
    // Demonstrate Time
    Time t;
    t.set(2, 65); // minutes corrected to 05
    cout << "Time: "; t.print(); cout << endl;

    // Demonstrate Date
    Date d;
    d.set(2026, 1, 32); // corrected to 2026-01-31
    cout << "Date: "; d.print(); cout << endl;

    // Demonstrate Event
    Event e;
    e.setTitle("Project Meeting");
    e.setDate(2026, 2, 4);
    e.setStart(10, 30);
    e.setEnd(12, 0);
    e.print();

    return 0;
}
