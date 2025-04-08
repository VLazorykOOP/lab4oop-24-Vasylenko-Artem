#include <iostream>

#include "console.h"
#include "taskManager.h"
#include "date.h"

// Створити клас типу - дата з полями : день(1 - 31), місяць(1 - 12), рік(ціле число).У класі визначити
// - конструктори(не менше двох);
// - функції - члени встановлення дня, місяця та року, функції встановлення полів класу повинні перевіряти коректність параметрів, що задаються;
// - функції - члени одержання дня, місяця та року;
// - дві функції - члени друку за шаблоном : “5 січня 2019 року” і “05.01.2019”. Написати програму тестування всіх можливостей цього класу.

void task_01()
{
	Date date1;
	date1.printFullDate();
	date1.printShortDate();
	newLine();

	Date date2(5, 1, 2019);
	date2.printFullDate();
	date2.printShortDate();
	newLine();

	date2.setDay(15);
	date2.setMonth(8);
	date2.setYear(2025);
	date2.printFullDate();
	date2.printShortDate();
	newLine();

	// Test
	date2.setDay(32);
	date2.setMonth(13);
	date2.setYear(-2023);
}
