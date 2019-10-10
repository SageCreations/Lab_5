#include <iostream>

using namespace std;

int getNumberOfDays(int month, int year)
{
    //calculates leap year for february
    if( month == 2)
    {
        if((year%400==0) || (year%4==0 && year%100!=0))
            return 29;
        else
            return 28;
    }
    //months that have 31 days
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
            ||month == 10 || month==12)
        return 31;
    else
        return 30;
}

int main() {
     char more, buff;
     int month, day, year, totalDays, choice, amountOfMonths;

     do {
         cout << "\n\t\t1.) How many days have passed in the year? "
              << "\n\t\t2.) What is the date from how many days have passed? "
              << "\n\n\t\tPlease input (1 or 2):";
         cin  >> choice;

         switch (choice)
         {
             case 1:
                 totalDays = 0;

                 cout << "\n\tPlease input month, date and year in this format (M/D/YYYY) : ";
                 cin  >> month >> buff >> day >> buff >> year;

                 for (int i = 1; i < month; i++)
                     totalDays += getNumberOfDays(i, year);

                 totalDays += day;

                 cout << "\n\t\tNumber of days passed :  " << totalDays;
                 break;
             case 2:
                 totalDays = 0;
                 amountOfMonths = 1;

                 cout << "\n\tPlease give the year for context: ";
                 cin  >> year;
                 cout << "\n\tPlease input amount of days passed to output the date: ";
                 cin  >> totalDays;

                 for (int i = 1; i < 12; i++) {
                     totalDays -= getNumberOfDays(i, year);
                     amountOfMonths++;
                     if (totalDays <= getNumberOfDays(amountOfMonths, year))
                     {
                         day = totalDays;
                         month = amountOfMonths;
                         break;
                     }
                 }
                 cout << "\n\t\tThe date is: " << month << "/" << day << "/" << year;
                 break;
             default:
                 cout << "\n\t\tPlease input (1/2)!!! : ";
                 break;
         }

         cout << "\n\n\tDo more (Y/N) ? ";
         cin  >> more;

     } while (more == 'y' || more == 'Y');

     return 0;
}
