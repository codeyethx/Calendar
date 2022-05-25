/**
 * Creates a calendar based on user input of month and year.
 * @file calendar.cpp
 * @author Gift Chidera Uwakwe
 * @date February 7, 2022
 */

 #include <iostream>

 int month, day, year, start = 0;

 #define MONTHS_PER_YEAR 12

 const unsigned short DAYS_PER_MONTH[MONTHS_PER_YEAR] =
 {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

 const char MONTH_NAMES[MONTHS_PER_YEAR][10] =
 {"January",   "February", "March",    "April",
 "May",       "June",     "July",     "August",
 "September", "October",  "November", "December"};

 /**
  * Returns true if indicated year is a leap year.
  * @param year: the year that user inputs.
  * @return true if year is a leap year, and false otherwise.
  */
 bool leapYear(int year)
 {
    return (((year % 400) == 0) || ((year % 4 == 0) && !(year % 100 == 0)));
 }

 /**
  * Checks through months January and February to find the starting day of
  * the month following the Gregorian calendar.
  * @returns extra day, and extra day if leap year or not.
  * CITE: https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
  * DESC: Used this page to learn how to determine a day of the week, while accounting for leap years.
  */
 int day_of()
 {
    int subset_days[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3)
    {
       year--;
    }
    return ((year + year / 4 - year / 100 + year / 400 + subset_days[month - 1] + day) % 7);
 }

 /**
  * Prints the calender and calculates how many days are in month and which months
  * day starts on.
  */
 void printMonth()
{
   start = day_of();
   int count = 0;
   int days_per = DAYS_PER_MONTH[month - 1];
   if (leapYear(year + 1) && month == 2)
   {
      days_per = DAYS_PER_MONTH[month - 1] + 1;
   }
   if (start == 6)
   {
      start = -1;
      std::cout << " ";
   }
   for (count = 0; count <= start; count++)
   {
      if (count > 0)
      {
         std::cout << "   ";
      }
      else
      {
         std::cout << "    ";
      }
   }
   for (day = 1; day <= days_per; day++)
   {
      if (++count > 6)
      {
        count = 0;
        std::cout << day;
        if (day != days_per)
        {
           std::cout << '\n';
           if (day < 9)
           {
              std::cout << " ";
            }
         }
       }
       else
       {
         if (day >= 9)
         {
           std::cout << day;
         }
         else
         {
           std::cout << day << " ";
         }
         if (day != days_per)
         {
           std::cout << " ";
         }
       }
   }
}

 // Controls operation of the program.
 int main()
 {
   std::cout << "Enter the month: ";
   std::cin >> month;
   std::cout << "Enter the year: ";
   std::cin >> year;
   std::cout << MONTH_NAMES[month - 1] << " " << year << std::endl;
   std::cout << "Su" << "  "<< "M" << "  "<< "T"<< "  " << "W" << " " << "Th" << "  " << "F" << " " << "Sa\n";
   printMonth();
   std::cout << std::endl;
   return 0;
 }
