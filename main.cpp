#include <iostream>
#include <iomanip>

using namespace std;

int getNumberOfDays(int month, int year)
{
    //calculates leap year for february
    if(month == 2)
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
         cout << "\nThis program will find days passed or date in the year"
              << "\n\t\t1) Input date (mm/dd/yyyy) to find days passed "
              << "\n\t\t2) Input passed days to find date in the year "
              << "\n\t\t\tYour choice (1/2): ";
         cin  >> choice;

         switch (choice)
         {
             case 1:
                 totalDays = 0;

                 cout << "\n\t\tPlease input date (mm/dd/yyyy): ";
                 cin  >> month >> buff >> day >> buff >> year;

                 if (month <= 12 && day <= getNumberOfDays(month, year) && (year <= 2019 || year > 0)) {
                     for (int i = 1; i < month; i++)
                         totalDays += getNumberOfDays(i, year);

                     totalDays += day;

                     cout << "\n\t\tThere are " << totalDays << " days passed in the year " << year;
                 }
                 else {
                     cout << "\n\t\tSorry, something wrong with days or year.";
                 }
                 break;
             case 2:
                 totalDays = 0;
                 amountOfMonths = 1;
                 day = 0;
                 year = 0;
                 month = 0;

                 cout << "\n\t\tInput days: ";
                 cin  >> totalDays;
                 cout << "\n\t\t" << setw(10) << "Year: ";
                 cin  >> year;

                 for (int i = 1; i <= 12; i++) {
                     if (totalDays <= getNumberOfDays(amountOfMonths, year))
                     {
                         day = totalDays;
                         break;
                     }
                     else {
                         totalDays -= getNumberOfDays(i, year);
                         amountOfMonths++;
                     }
                 }
                 if (totalDays <= getNumberOfDays(amountOfMonths, year) && amountOfMonths <= 12 && (year > 0 || year <= 2019))
                     cout << "\n\t\tThe date is: " << amountOfMonths << "/" << day << "/" << year;
                 else
                     cout << "\n\t\tSorry, something wrong with days or year.";
                 break;
             default:
                 cout << "\n\t\tPlease input (1/2)!!! : ";
                 break;
         }

         cout << "\n\n\t\tDo more (Y/N) ? ";
         cin  >> more;

     } while (more == 'y' || more == 'Y');

     return 0;
}
