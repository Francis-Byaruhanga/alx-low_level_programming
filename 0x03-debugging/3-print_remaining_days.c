#include <stdio.h>
#include "main.h"

/**
 * print_remaining_days - takes a date and prints how main days are
 * left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of month
 * @year: year
 * Return: void
 */

void print_remaining_days(int month, int day, int year)
{
	int days_in_months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day_of_year = day;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
		return;
	}

	for (int i = 1; i < month; i++)
	{
		day_of_year += days_in_months[i];
	}

	if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day_of_year++;
	}

	printf("Day of the year: %d\n", day_of_year);
	printf("Remaining days: %d\n", 365 + (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) - day_of_year));
}

