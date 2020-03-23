#pragma once
struct Date
{
	unsigned char minute, hour, day, month;
	int year;
	void increase()
	{
		minute += 1;
			if (minute > 59)
			{
				minute = 0;
				hour += 1;
			}
			if (hour > 23)
			{
				hour = 0;
				day += 1;
			}
			if (day > 30)
			{
				day = 1;
				month += 1;
			}
			if (month > 12)
			{
				month = 1;
				year += 1;
			}
	}

	void get_time()
	{
		
		std::cout << std::endl << (int)hour << "." << (int)minute << "  " << (int)day << "." << (int)month << "." << year << std::endl;
	}
		 
};