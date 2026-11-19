// Introductory Programming Lab 12 -- Emerson Beesley -- November 12, 2026

#include <iostream>
using namespace std;

bool isLeapYear(int year);
/**
isLeapYear – determines whether a given year is a leap year
under the Gregorian calendar.
@param year the year; expected to be >= 1582
@return true if year is a leap year; false otherwise
*/

int daysInMonth(int month, int year);
/**
daysInMonth – determines the number of days in a specified month
@param month the month; expected to be in the range [1..12]
@param year the year; expected to be >= 1582
@return either 28, 29, 30, or 31, based on month and (leap) year
*/

int dayOfWeek(int month, int day, int year);
/**
dayOfWeek - Computes the weekday of a given date.
@param year the year
@param month the month (1 = January ... 12 = December)
@param day the day of the month
@return the weekday (0 = Saturday ... 6 = Friday)
*/


int main(void) {
	int inputYear;
	int inputMonth;
	int inputDay;
	int outputWeekday;
	string printedMonth;
	string printedWeekday;

	while (true) {
		cout << "Enter date or Q to quit: ";

		if (!(cin >> inputMonth >> inputDay >> inputYear)) { break; }

		switch (inputMonth) {
			case 1: printedMonth = "January"; break;
			case 2: printedMonth = "February"; break;
			case 3: printedMonth = "March"; break;
			case 4: printedMonth = "April"; break;
			case 5: printedMonth = "May"; break;
			case 6: printedMonth = "June"; break;
			case 7: printedMonth = "July"; break;
			case 8: printedMonth = "August"; break;
			case 9: printedMonth = "September"; break;
			case 10: printedMonth = "October"; break;
			case 11: printedMonth = "November"; break;
			case 12: printedMonth = "December"; break;
		}
		
		outputWeekday = dayOfWeek(inputMonth, inputDay, inputYear);
		switch (outputWeekday) {
			case 0: printedWeekday = "Saturday"; break;
			case 1: printedWeekday = "Sunday"; break;
			case 2: printedWeekday = "Monday"; break;
			case 3: printedWeekday = "Tuesday"; break;
			case 4: printedWeekday = "Wednesday"; break;
			case 5: printedWeekday = "Thursday"; break;
			case 6: printedWeekday = "Friday"; break;
		}

		cout << printedWeekday << ", " << printedMonth << " " << inputDay << ", " << inputYear << endl << endl;

		
	}

}


bool isLeapYear(int year) {
	if ((year % 4) == 0) {
		//continue
		if ((year % 100) == 0) {
			//continue
			if ((year % 400) == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}


int daysInMonth(int month, int year) {
	switch (month) {
		case 1: return 31; break;
		case 2: if (isLeapYear(year)) { return 29; } else { return 28; } break;
		case 3: return 31; break;
		case 4: return 30; break;
		case 5: return 31; break;
		case 6: return 30; break;
		case 7: return 31; break;
		case 8: return 31; break;
		case 9: return 30; break;
		case 10: return 31; break;
		case 11: return 30; break;
		case 12: return 31; break;
	}
}


int dayOfWeek(int month, int day, int year) {
	int usableMonth;
	int usableYear;
	int weekDay;

	if ((month == 1) || (month == 2)) {
		usableMonth = month + 12;
		usableYear = year - 1;
	}
	else {
		usableMonth = month;
		usableYear = year;
	}

	return weekDay = (day + (((usableMonth + 1) * 26) / 10) + usableYear + (usableYear / 4) + (6 * (usableYear / 100)) + (usableYear / 400)) % 7;
} 