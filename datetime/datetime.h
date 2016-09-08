#ifndef __DateTime_Inc_H__
#define __DateTime_Inc_H__

#include <cstring>
#include <iostream>
#include <string>

class DateTime
{
public:
  /*
  * default constructor with system time
  */
  DateTime();

  /*
  * constructor with unixstamp
  */
  DateTime(unsigned int unixstamp);

  /*
  * constructor with year/month/day hour/min/sec
  */
  DateTime(int year, int month, int day,
    int hour, int min, int sec);

  /*
  * current datetime's unixstamp
  */
  unsigned unixstamp();

  /*
  * add year on current datetime, success return true, otherwise false
  */
  bool addYear(int year);

  /*
  * add day on current datetime, success return true, otherwise false
  */
  bool addDay(int day);

  /*
  * add hour on current datetime, success return true, otherwise false
  */
  bool addHour(int hour);

  /*
  * add minute on current datetime, success return true, otherwise false
  */
  bool addMinute(int min);

  /*
  * add second on current datetime, success return true, otherwise false
  */
  bool addSecond(int sec);

  /*
  * the year of current datetime
  */
  int year();

  /*
  * the month of current datetime
  */
  int month();

  /*
  * the day of current datetime
  */
  int day();

  /*
  * the hour of current datetime
  */
  int hour();

  /*
  * the minute of current datetime
  */
  int minute();

  /*
  * the second of current datetime
  */
  int second();

  /*
  * the week day of current datetime
  */
  int wday();

  /*
  * the week day of current datetime, china week of day
  */
  int cwday();

  /*
  * as datetime to a string with format[yyyy-mm-dd hh:mm:ss]
  */
  std::string asString();

  /*
  * one minute's seconds
  */
  static int oneMinute() {
    return 60;
  }

  /*
  * one hour's seconds
  */
  static int oneHour() {
    return 60 * oneMinute();
  }

  /*
  * one day's seconds
  */
  static int oneDay() {
    return 24 * oneHour();
  }

  /*
  * one week's seconds
  */
  static int oneWeek() {
    return 7 * oneDay();
  }

  /*
  * compare the two time is different day on offset
  */
  static bool diffDay(time_t t1, time_t t2, time_t offset = 0);

  /*
  * compare the two time is different week on offset
  */
  static bool diffWeek(time_t t1, time_t t2, time_t offset = 0);

  /*
  * compare the two time is different week on offset
  */
  static bool diffMonth(time_t t1, time_t t2, time_t offset = 0);

  /*
  * compare the two time is different year on offset
  */
  static bool diffYear(time_t t1, time_t t2, time_t offset = 0);

private:
  time_t unixstamp_;
  tm* tm_;
};

#endif // __DateTime_Inc_H__
