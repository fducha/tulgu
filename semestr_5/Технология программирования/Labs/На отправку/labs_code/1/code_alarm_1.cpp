#include <iostream>
#include <time.h>

using namespace std;

class Alarm
{
//    time_t alarm_t;
public:
    static void currentTime();
};

void Alarm::currentTime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    cout << tm.tm_hour << " : " << tm.tm_min << " : " << tm.tm_sec << endl;
}

int main()
{
    Alarm::currentTime();
    return 0;
}

