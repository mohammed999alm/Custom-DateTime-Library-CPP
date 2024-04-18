#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include "MyString.h"
#include <string>
#include <iomanip>
#include <vector>
using namespace std;


class DateTime
{

private:

	short _year;
	short _month;
	short _day;


public:


	DateTime()
	{
		getSystemDate();
	}


	DateTime(string fullDate)
	{
		vector <string> vDate = MyString::splitString(fullDate, "/");

		_day = stoi(vDate[0]);
		_month = stoi(vDate[1]);
		_year = stoi(vDate[2]);
	}

	DateTime(short day, short month, short year)
	{
		_day = day;
		_month = month;
		_year = year;
	}


	DateTime(short numberOfDays, short year)
	{
		_year = year;
		getDateOfDayFromTheBeginningOfTheYear(numberOfDays);
	}


	void setDay(short day) 
	{
		_day = day;
	}

	short getDay() 
	{
		return _day;
	}

	__declspec(property(get = getDay, put = setDay)) short day;

	void setMonth(short month)
	{
		_month = month;
	}

	short getMonth()
	{
		return _month;
	}

	__declspec(property(get = getMonth, put = setMonth)) short month;


	void setYear(short year)
	{
		_year = year;
	}

	short getYear()
	{
		return _year;
	}

	__declspec(property(get = getYear, put = setYear)) short year;


	//   void getSystemDate() 
	   //{
	   //	time_t t = time(0);

	   //	tm* local = localtime(&t);

	   //	_year = local->tm_year + 1900;
	   //	_month = local->tm_mon + 1;
	   //	_day = local->tm_mday;
	   //}

	static DateTime getSystemDate(DateTime date)
	{
		time_t t = time(0);

		tm* local = localtime(&t);

		date._year = local->tm_year + 1900;
		date._month = local->tm_mon + 1;
		date._day = local->tm_mday;

		return date;
	}


	void  getSystemDate()
	{
		DateTime date = getSystemDate(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}



	static bool isLeapYear(short year)
	{
		return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
	}

	bool isLeapYear()
	{
		return isLeapYear(_year);
	}

	static short numberOfDaysInYear(short year)
	{
		return (isLeapYear(year)) ? 366 : 365;
	}

	short numberOfDaysInYear()
	{
		return numberOfDaysInYear(_year);
	}


	static short numberOfHoursInYear(short year) 
	{
		return numberOfDaysInYear(year) * 24;
	}

	short numberOfHoursInYear() 
	{
		return numberOfHoursInYear(_year);
	}

	static int numberOfMinutesInYear(short year) 
	{
		return numberOfHoursInYear(year) * 60;
	}

	int numberOfMinutesInYear() 
	{
		return numberOfMinutesInYear(_year);
	}

	static int numberOfSecondsInYear(short year) 
	{
		return numberOfMinutesInYear(year) * 60;
	}

    int numberOfSecondsInYear()
	{
		return numberOfSecondsInYear(_year);
	}

	static short numberOfDaysInMonth(short year, short month)
	{
		if (month < 1 || month > 12)
			return 0;

		bool is30Days = (month == 4 || month == 6 || month == 9 || month == 11);

		return (month == 2) ? (isLeapYear(year)) ? 29 : 28 : (is30Days) ? 30 : 31;
	}


	short numberOfDaysInMonth()
	{
		return numberOfDaysInMonth(_year, _month);
	}


	static short numberOfHoursInMonth(short year, short month)
	{
		return numberOfDaysInMonth(year, month) * 24;
	}

	short numberOfHoursInMonth() 
	{
		return numberOfHoursInMonth(_year, _month);
	}

	static int numberOfMinutesInMonth(short year, short month) 
	{
		return numberOfHoursInMonth(year, month) * 60;
	}

	int numberOfMinutesInMonth() 
	{
		return numberOfMinutesInMonth(_year, _month);
	}

	static int numberOfSecondsInMonth(short year, short month) 
	{
		return numberOfMinutesInMonth(year, month) * 60;
	}

	int numberOfSecondsInMonth() 
	{
		return numberOfSecondsInMonth(_year, _month);
	}

	short numberOfHoursInDay() 
	{
		return 24;
	}

	short numberOfMinutesInDay() 
	{
		return numberOfHoursInDay() * 60;
	}

	int numberOfSecondsInDay() 
	{
		return numberOfMinutesInDay() * 60;
	}

	static bool isValid(DateTime date)
	{
		return (date._month >= 1 && date._month <= 12) && (date._day <= date.numberOfDaysInMonth(date._year, date._month));
	}

	bool isValid()
	{
		return isValid(*this);
	}

	static bool isLastDayInMonth(DateTime date)
	{
		return date._day == numberOfDaysInMonth(date._year, date._month);
	}

	bool isLastDayInMonth()
	{
		return isLastDayInMonth(*this);
	}

	static bool isLastMonthInYear(short month)
	{
		return month == 12;
	}

	bool isLastMonthInYear()
	{
		return isLastMonthInYear(_month);
	}

	static bool isDateBeforeDate2(DateTime date1, DateTime date2)
	{
		return (date1._year < date2._year) ? true : ((date1._year == date2._year) ? (date1._month < date2._month) ? true : ((date1._month == date2._month) ? date1._day < date2._day : false) : false);
	}

	bool isDateBeforeDate2(DateTime date)
	{
		return isDateBeforeDate2(*this, date);
	}

	static bool isDateEqualToDate2(DateTime date1, DateTime date2)
	{
		return ((date1._year == date2._year) ? ((date1._month == date2._month) ? (date1._day == date2._day) : false) : false);
	}

	bool isDateEqualToDate2(DateTime date)
	{
		return isDateEqualToDate2(*this, date);
	}


	static bool isDateAfterDate2(DateTime date1, DateTime date2)
	{
		return !(isDateBeforeDate2(date1, date2) || isDateEqualToDate2(date1, date2));
	}

	bool isDateAfterDate2(DateTime date)
	{
		return isDateAfterDate2(*this, date);
	}


	static short dayFromBeginningOfTheYear(DateTime date)
	{
		short daysCounter = 0;

		for (short i = 1; i < date._month; i++)
		{
			daysCounter += numberOfDaysInMonth(date._year, i);
		}

		return daysCounter + date._day;
	}

	short dayFromBeginningOfTheYear()
	{
		return dayFromBeginningOfTheYear(*this);
	}

	static DateTime getDateOfDayFromTheBeginningOfTheYear(short dayYearOrder, short year)
	{
		short remainingDays = dayYearOrder;
		DateTime date;
		date._year = year;
		date._month = 1;

		while (true)
		{
			short monthDays = numberOfDaysInMonth(date._year, date._month);
			if (remainingDays >= monthDays)
			{
				remainingDays -= monthDays;

				date._month++;
			}
			else
			{
				date._day = remainingDays;
				break;
			}
		}

		return date;
	}

	void getDateOfDayFromTheBeginningOfTheYear(short numberOfDays)
	{
		DateTime date = getDateOfDayFromTheBeginningOfTheYear(numberOfDays, _year);

		this->_year = date._year;
		this->_month = date._month;
		this->_day = date._day;
	}

	static string getMonthShortName(short month)
	{
		string monthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return monthNames[month - 1];
	}

	string getMonthShortName()
	{
		return getMonthShortName(_month);
	}

	static string getDayShortName(short day)
	{
		string dayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

		return dayNames[day];
	}


	string getDayShortName()
	{
		return getDayShortName(dayOfWeekOrder());
	}

	static void printMonthCalender(short year, short month)
	{

		cout << "\n __________________" << getMonthShortName(month) << "__________________\n";

		cout << "   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
		short i;

		short currentDay = dayOfWeekOrder(year, month, 1);

		for (i = 0; i < currentDay; i++)
			cout << "     ";


		short monthDays = numberOfDaysInMonth(year, month);
		for (short j = 1; j <= monthDays; j++)
		{
			cout << setw(5) << j;

			if (++i == 7)
			{
				i = 0;
				cout << "\n";
			}
		}

		cout << "\n _______________________________________\n";

	}

	void printMonthCalender()
	{
		printMonthCalender(_year, _month);
	}

	static void printYearCalender(short year)
	{
		for (short i = 1; i <= 12; i++)
		{
			printMonthCalender(year, i);
		}
	}

	void printYearCalender()
	{
		printYearCalender(_year);
	}

	static short dayOfWeekOrder(short year, short month, short day)
	{
		short d, m, y, a;

		a = (14 - month) / 12;
		y = year - a;

		m = month + (12 * a) - 2;

		d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((m * 31) / 12)) % 7;

		return d;
	}

	static short dayOfWeekOrder(DateTime date)
	{
		return dayOfWeekOrder(date._year, date._month, date._day);
	}


	static DateTime increaseDateByOneDay(DateTime date)
	{
		if (isLastDayInMonth(date))
		{
			if (isLastMonthInYear(date._month))
			{
				date._year++;
				date._month = 1;
				date._day = 1;
			}

			else
			{
				date._month++;
				date._day = 1;
			}
		}

		else
		{
			date._day++;
		}

		return date;
	}


	void increaseDateByOneDay()
	{
		DateTime date = increaseDateByOneDay(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}

	static DateTime increaseDateByDays(DateTime date, int days)
	{

		for (int i = 1; i <= days; i++)
		{
			date = increaseDateByOneDay(date);
		}

		return date;
	}


	void increaseDateByDays(int days)
	{
		DateTime date = increaseDateByDays(*this, days);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime increaseDateByOneWeek(DateTime date)
	{
		for (short i = 1; i <= 7; i++)
		{
			date = increaseDateByOneDay(date);
		}

		return date;
	}


	void increaseDateByOneWeek()
	{
		DateTime date = increaseDateByOneWeek(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime increaseDateByWeeks(DateTime date, short weeks)
	{
		for (short i = 1; i <= weeks; i++)
		{
			date = increaseDateByOneWeek(date);
		}

		return date;
	}

	void increaseDateByWeeks(short weeks)
	{
		DateTime date = increaseDateByWeeks(*this, weeks);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}

	static DateTime increaseDateByOneMonth(DateTime date)
	{
		short monthDays = numberOfDaysInMonth(date._year, date._month + 1);

		if (date.isLastMonthInYear()) 
		{
			date._year++;
			date._month = 1;
		}

		else if (date._day > monthDays)
		{
			date._month++;
			date._day = date.numberOfDaysInMonth();
		}

		else
		{
			date._month++;
		}

		return date;
	}


	void increaseDateByOneMonth()
	{
		DateTime date = increaseDateByOneMonth(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime increaseDateByMonths(DateTime date, short months)
	{
		for (short i = 1; i <= months; i++)
		{
			date.increaseDateByOneMonth();
		}

		return date;
	}

	void increaseDateByMonths(short months)
	{
		DateTime date = increaseDateByMonths(*this, months);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime increaseDateByOneYear(DateTime date)
	{
		date._year++;

		return date;
	}

	void increaseDateByOneYear()
	{
		DateTime date = increaseDateByOneYear(*this);

		this->_year = date._year;
	}


	static DateTime increaseDateByYears(DateTime date, short years)
	{
		for (short i = 1; i <= years; i++) 
		{
			date.increaseDateByOneYear();
		}

		return date;
	}

	void increaseDateByYears(short years)
	{
		DateTime date = increaseDateByYears(*this , years);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime increaseDateByOneDecade(DateTime date)
	{
		for (short i = 1; i <= 10; i++)
		{
			date.increaseDateByOneYear();
		}

		return date;
	}

	void increaseDateByOneDecade()
	{
		DateTime date = increaseDateByOneDecade(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}

	static DateTime increaseDateByDecades(DateTime date, short decades) 
	{
		for (short i = 1; i <= decades; i++) 
		{
			date.increaseDateByOneDecade();
		}

		return date;
	}

	void increaseDateByDecades(short decades)
	{
		DateTime date = increaseDateByDecades(*this, decades);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime increaseDateByOneCentury(DateTime date) 
	{
		date._year += 100;

		return date;
	}

	void increaseDateByOneCentury() 
	{
		DateTime date = increaseDateByOneCentury(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}

	
	static DateTime increaseDateByOneMillennium(DateTime date) 
	{
		date._year += 1000;

		return date;
	}


	void increaseDateByOneMillennium() 
	{
		DateTime date = increaseDateByOneMillennium(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime decreaseDateByOneDay(DateTime date) 
	{
		if (date._day == 1)
		{
			if (date._month == 1) 
			{
				date._year--;
				date._month = 12;
				date._day = 31;
			} 
			else 
			{
				date._month--;
				date._day = date.numberOfDaysInMonth();
			}
		}

		else 
		{
			date._day--;
		}

		return date;
	}

	
	void decreaseDateByOneDay() 
	{
		DateTime date = decreaseDateByOneDay(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	DateTime decreaseDateByDays(DateTime date, int days) 
	{
		for (int i = 1; i <= days; i++)
		{
			date.decreaseDateByOneDay();
		}

		return date;
	}

	void decreaseDateByDays(int days)
	{
		DateTime date = decreaseDateByDays(*this, days);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}

	static DateTime decreaseDateByOneWeek(DateTime date)
	{
		for (short i = 1; i <= 7; i++)
		{
			date = decreaseDateByOneDay(date);
		}

		return date;
	}


	void decreaseDateByOneWeek()
	{
		DateTime date = decreaseDateByOneWeek(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime decreaseDateByWeeks(DateTime date, short weeks)
	{
		for (short i = 1; i <= weeks; i++)
		{
			date = decreaseDateByOneWeek(date);
		}

		return date;
	}

	void decreaseDateByWeeks(short weeks)
	{
		DateTime date = decreaseDateByWeeks(*this, weeks);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}

	static DateTime decreaseDateByOneMonth(DateTime date) 
	{
		short monthDays = date.numberOfDaysInMonth(date._year, date._month - 1);

		if (date._month == 1) 
		{
			date._year--;
			date._month = 12;
		}

		else if (date._day > monthDays)
		{
			date._month--;
			date._day = date.numberOfDaysInMonth();
		}

		else 
		{
			date._month--;
		}

		return date;
	}


	void decreaseDateByOneMonth()
	{
		DateTime date = decreaseDateByOneMonth(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime decreaseDateByMonths(DateTime date, short months)
	{
		for (short i = 1; i <= months; i++)
		{
			date.decreaseDateByOneMonth();
		}

		return date;
	}

	void decreaseDateByMonths(short months)
	{
		DateTime date = decreaseDateByMonths(*this, months);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime decreaseDateByOneYear(DateTime date)
	{
		date._year--;

		return date;
	}

	void decreaseDateByOneYear()
	{
		DateTime date = decreaseDateByOneYear(*this);

		this->_year = date._year;
	}


	static DateTime decreaseDateByYears(DateTime date, short years)
	{
		for (short i = 1; i <= years; i++)
		{
			date.decreaseDateByOneYear();
		}

		return date;
	}

	void decreaseDateByYears(short years)
	{
		DateTime date = decreaseDateByYears(*this, years);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime decreaseDateByOneDecade(DateTime date)
	{
		for (short i = 1; i <= 10; i++)
		{
			date.decreaseDateByOneYear();
		}

		return date;
	}

	void decreaseDateByOneDecade()
	{
		DateTime date = decreaseDateByOneDecade(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}

	static DateTime decreaseDateByDecades(DateTime date, short decades)
	{
		for (short i = 1; i <= decades; i++)
		{
			date.decreaseDateByOneDecade();
		}

		return date;
	}

	void decreaseDateByDecades(short decades)
	{
		DateTime date = decreaseDateByDecades(*this, decades);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime decreaseDateByOneCentury(DateTime date)
	{
		date._year -= 100;

		return date;
	}

	void decreaseDateByOneCentury()
	{
		DateTime date = decreaseDateByOneCentury(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static DateTime decreaseDateByOneMillennium(DateTime date)
	{
		date._year -= 1000;

		return date;
	}


	void decreaseDateByOneMillennium()
	{
		DateTime date = decreaseDateByOneMillennium(*this);

		this->_day = date._day;
		this->_month = date._month;
		this->_year = date._year;
	}


	static int calculateMyAgeInDays(DateTime date, bool includeEndDay = true) 
	{
		
		DateTime localTime;

		return date.getDifferenceInDays(date, localTime, includeEndDay);
	}

	int calculateMyAgeInDays(bool includeEndDay = true) 
	{
		return calculateMyAgeInDays(*this, includeEndDay);
	}

	static int getDifferenceInDays(DateTime date1, DateTime date2, bool includeEndDay = true) 
	{
		int countDays = 0;
		
		while (isDateBeforeDate2(date1, date2)) 
		{
			countDays++;

			date1 = increaseDateByOneDay(date1);
		}

		return (includeEndDay) ? ++countDays : countDays;
	}


	int getDifferenceInDays(DateTime date, bool includeEndDay = true) 
	{
		return getDifferenceInDays(*this, date, includeEndDay);
	}

	short dayOfWeekOrder() 
	{
		return dayOfWeekOrder(*this);
	}

	static void print(short day, short month, short year) 
	{
		cout << day << "/" << month << "/" << year << endl;
	}


	void print() 
	{
		cout << _day << "/" << _month << "/" << _year << endl;
	}
};

