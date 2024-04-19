#include <iostream>
#include "DateTime.h"
#include <iomanip>
using namespace std;


int main() 
{

	DateTime date1;

	date1.print();

	cout << "Business Day : " << date1.calculateBusinessDay(DateTime(1, 5, 2024)) << endl;
	cout << "Business Day : " << date1.calculateWeekendDays(DateTime(1, 5, 2024)) << endl;
	cout << "My Age IN Days Is   : " << DateTime::calculateMyAgeInDays(DateTime(9, 11, 1999), false) << endl;

	cout << DateTime::getDifferenceInDays(date1, DateTime(9, 11, 1999)) << endl;
	cout << DateTime::getDifferenceInDays(DateTime(9, 11, 1999), date1) << endl;

	cout << date1.dayUntilTheEndOfTheYear() << " Days Until The End Of The  Year .\n";
	cout << date1.dayUntilTheEndOfTheMonth() << " Days Until The End Of The  Month .\n";
	cout << date1.dayUntilTheEndOfTheWeek() << " Days Until The End Of The  Week .\n";
	
	DateTime date(1, 1, 2025);

	cout << "Before Swap : \n";
	date1.print();
	date.print();

	DateTime::swapDates(date1, date);

	cout << "After Swap : \n";
	date1.print();
	date.print();


	cout << date1.compareDates(date, date1);

	return 0;

	//date1.print();

	cout << "Today is : " << date1.getDayShortName() << endl;

	date1.addOneDay();




	date1.print();

	date1.increaseDateByOneWeek();
	date1.print();

	date1.increaseDateByOneMonth();
	date1.print();

	date1.increaseDateByMonths(5);
	date1.print();

	date1.increaseDateByOneYear();
	date1.print();


	date1.increaseDateByWeeks(10);

	date1.print();
	cout << "Day is : " << date1.getDayShortName() << endl;

	date1.increaseDateByYears(10);

	date1.print();

	cout << "My Age IN Days Is   : " << DateTime::calculateMyAgeInDays(DateTime(9, 11, 1999), false) << endl;

	date1.addDays(1000);

	date1.print();
	cout << "Day is : " << date1.getDayShortName() << endl;

	date1.increaseDateByOneDecade();
	
	date1.print();

	date1.increaseDateByDecades(10);

	date1.print();

	date1.increaseDateByOneCentury();
	date1.print();

	date1.increaseDateByOneMillennium();
	date1.print();

	/*date1.decreaseDateByOneDay();
	date1.print();

	date1.decreaseDateByOneWeek();
	date1.print();

	date1.decreaseDateByOneMonth();
	date1.print();

	date1.decreaseDateByMonths(5);
	date1.print();

	date1.decreaseDateByOneYear();
	date1.print();

	date1.decreaseDateByWeeks(10);
	date1.print();

	date1.decreaseDateByYears(10);
	date1.print();

	cout << "____\n";
	date1.decreaseDateByDays(1000);
	date1.print();
	cout << "____\n";


	date1.decreaseDateByOneDecade();
	date1.print();

	date1.decreaseDateByDecades(10);
	date1.print();

	date1.decreaseDateByOneCentury();
	date1.print();

	date1.decreaseDateByOneMillennium();
	date1.print();*/

	date1.print();

	cout << "Today is : " << date1.getDayShortName() << endl;

	date1.decreaseDateByOneDay();

	date1.print();

	date1.decreaseDateByOneWeek();
	date1.print();

	date1.decreaseDateByOneMonth();
	date1.print();

	date1.decreaseDateByMonths(5);
	date1.print();

	date1.decreaseDateByOneYear();
	date1.print();


	date1.decreaseDateByWeeks(10);

	date1.print();
	cout << "Day is : " << date1.getDayShortName() << endl;

	date1.decreaseDateByYears(10);

	date1.print();

	cout << "My Age IN Days Is   : " << DateTime::calculateMyAgeInDays(DateTime(9, 11, 1999), false) << endl;

	date1.decreaseDateByDays(1000);

	date1.print();
	cout << "Day is : " << date1.getDayShortName() << endl;

	date1.decreaseDateByOneDecade();

	date1.print();

	date1.decreaseDateByDecades(10);

	date1.print();

	date1.decreaseDateByOneCentury();
	date1.print();

	date1.decreaseDateByOneMillennium();
	date1.print();

	cout << "\n_______________________________________\n";

	cout << "There is " << left << setw(15) << date1.numberOfDaysInYear() << " Days In Year " << date1.year << endl;
	cout << "There is " << left << setw(15) << date1.numberOfHoursInYear() << " Hours In Hours " << date1.year << endl;
	cout << "There is " << left << setw(15) << date1.numberOfMinutesInYear() << " Minutes In Minutes " << date1.year << endl;
	cout << "There is " << left << setw(15) << date1.numberOfSecondsInYear() << " Seconds In Year " << date1.year << endl;
	cout << "There is " << left << setw(15) << date1.numberOfDaysInMonth() << " Days In Month " << date1.month << endl;
	cout << "There is " << left << setw(15) << date1.numberOfHoursInMonth() << " Hours In Year " << date1.month << endl;
	cout << "There is " << left << setw(15) << date1.numberOfMinutesInMonth() << " Minutes In Year " << date1.month << endl;
	cout << "There is " << left << setw(15) << date1.numberOfSecondsInMonth() << " Seconds In Year " << date1.month << endl;

	cout << "There is " << left << setw(15) << date1.numberOfHoursInDay()   << " Hours In Day " << endl;
	cout << "There is " << left << setw(15) << date1.numberOfMinutesInDay() << " Minutes In Day "<< endl;
	cout << "There is " << left << setw(15) << date1.numberOfSecondsInDay() << " Seconds In Day "<< endl;


	cout << "\n_______________________________________\n";


	


	DateTime::increaseDateByOneMonth(DateTime(31, 1, 2023)).print();
	DateTime::decreaseDateByOneDay(DateTime(1, 1, 2024)).print();

	DateTime::increaseDateByOneMonth(DateTime(31, 12, 2023)).print();
	DateTime::decreaseDateByOneMonth(DateTime(31, 1, 2023)).print();



	return 0;
	
	cout << "\n" << date1.dayFromBeginningOfTheYear() << " Days From The Beginning of the year.\n";
	cout << "\nMonth Days : " << date1.numberOfDaysInMonth() << endl;
	date1.printMonthCalender();

	//cout << date1.isValid() << endl;


	DateTime date2("20/9/2024");

	date2.print();

	cout << "\n" << date2.dayFromBeginningOfTheYear() << " Days From The Beginning of the year.\n";
	cout << "\nMonth Days : " << date2.numberOfDaysInMonth() << endl;
	cout << "Today is : " << date2.getDayShortName() << endl;

	//cout << date2.isValid() << endl;

	DateTime date3(15, 12, 2024);
	date3.print();

	cout << "\n" << date3.dayFromBeginningOfTheYear() << " Days From The Beginning of the year.\n";

	cout << "\nMonth Days : " << date3.numberOfDaysInMonth() << endl;

	DateTime date4(250, 2022);
	date4.print();

	date4.printMonthCalender();
	date4.printYearCalender();
	//cout << date3.isValid() << endl;

	//if (date3.isDateBeforeDate2(date2))
	//	cout << "\nYes Date 1 is  before Date 2\n";
	//else 
	//	cout << "\nNo Date 1 is not before Date 2!\n";

	//if (date1.isDateBeforeDate2(date1))
	//	cout << "\nYes Date 1 is  before Date 2\n";
	//else
	//	cout << "\nNo Date 1 is not before Date 2!\n";

	//if (date3.isDateEqualToDate2(date1))
	//	cout << "\nYes Date 1 is Equal To Date 2\n";
	//else
	//	cout << "\nNo Date 1 is not  Equal To Date 2!\n";

	//if (date1.isDateEqualToDate2(date1))
	//	cout << "\nYes Date 1 is Equal To Date 2\n";
	//else
	//	cout << "\nNo Date 1 is not  Equal To Date 2!\n";

	//if (date1.isDateAfterDate2(date2))
	//	cout << "\nYes Date 1 is After Date 2\n";
	//else
	//	cout << "\nNo Date 1 is not  After Date 2!\n";

	//if (date1.isDateAfterDate2(date1))
	//	cout << "\nYes Date 1 is After Date 2\n";
	//else
	//	cout << "\nNo Date 1 is not  After Date 2!\n";


	system("pause > 0");

	return 0;
}