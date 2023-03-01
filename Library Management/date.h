#include<ctime>
#include<string>
#pragma once
#pragma warning(disable: 4996)


namespace TodayDate
{ 
    std::string DateGive()
    {

        time_t now = time(0);
        tm* ltm = localtime(&now);
        int Tyear, Tmonth, Tday;
        std::string Year, Month, Day, dateis;
        Tyear = 1900 + ltm->tm_year;
        Tmonth = 1 + ltm->tm_mon;
        Tday = ltm->tm_mday;
       
            

        Year = std::to_string(Tyear);
        Month = std::to_string(Tmonth);
        Day = std::to_string(Tday);
        


        if (Month == "1")
            Month = "01";
        else if (Month == "2")
            Month = "02";
        else if (Month == "3")
            Month = "03";
        else if (Month == "4")
            Month = "04";
        else if (Month == "5")
            Month = "05";
        else if (Month == "6")
            Month = "06";
        else if (Month == "7")
            Month = "07";
        else if (Month == "8")
            Month = "08";
        else if (Month == "9")
            Month = "09";

        if (Day == "1")
            Day = "01";
        else if (Day == "2")
            Day = "02";
        else if (Day == "3")
            Day = "03";
        else if (Day == "4")
            Day = "04";
        else if (Day == "5")
            Day = "05";
        else if (Day == "6")
            Day = "06";
        else if (Day == "7")
            Day = "07";
        else if (Day == "8")
            Day = "08";
        else if (Day == "9")
            Day = "09";

        dateis = Day + Month + Year;
        return dateis;
    }

    std::string InputDate()
    {
        string today_date_is = DateGive();
        char* seperate;
        string day_, month_, year_;
        string str_obj(today_date_is);
        seperate = &str_obj[0];
        day_ += seperate[0];
        day_ += seperate[1];

        month_ += seperate[2];
        month_ += seperate[3];
        year_ += seperate[4];
        year_ += seperate[5];
        year_ += seperate[6];
        year_ += seperate[7];


        int day, month, year;


        day = stoi(day_);
        month = stoi(month_);
        year = stoi(year_);






        if (month == 12) {
            month = 1;
            year++;
        }
        else
            month++;

        string Str_day, Str_mon, Str_year;
         
        Str_mon  = std::to_string(month);
        Str_day  = std::to_string(day);
        Str_year = std::to_string(year);


        if (Str_mon == "1")
            Str_mon = "01";
        else if (Str_mon == "2")
            Str_mon = "02";
        else if (Str_mon == "3")
            Str_mon = "03";
        else if (Str_mon == "4")
            Str_mon = "04";
        else if (Str_mon == "5")
            Str_mon = "05";
        else if (Str_mon == "6")
            Str_mon = "06";
        else if (Str_mon == "7")
            Str_mon = "07";
        else if (Str_mon == "8")
            Str_mon = "08";
        else if (Str_mon == "9")
            Str_mon = "09";



        if (Str_day == "1")
            Str_day = "01";
        else if (Str_day == "2")
            Str_day = "02";
        else if (Str_day == "3")
            Str_day = "03";
        else if (Str_day == "4")
            Str_day = "04";
        else if (Str_day == "5")
            Str_day = "05";
        else if (Str_day == "6")
            Str_day = "06";
        else if (Str_day == "7")
            Str_day = "07";
        else if (Str_day == "8")
            Str_day = "08";
        else if (Str_day == "9")
            Str_day = "09";

       
        string date_return;

        date_return = Str_day + Str_mon + Str_year;
        return date_return;
                     

    }



       

}
   