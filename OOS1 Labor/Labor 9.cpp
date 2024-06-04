//Themen:

//Operatoren
//Ihre Aufgabe :

//Implementieren Sie den Konstruktor und die Operatoren, die für die Klasse Datum angegeben sind.Sie können zur Vereinfachung davon ausgehen, dass ein Jahr 360 Tage und jeder Monat 30 Tage hat.

//Das angegebene Hauptprogramm soll folgende Ausgabe erzeugen :

//Ausgabe:

//Die Aufgabe beginnt am 26.10.2023
//Die Aufgabe endet am 2.11.2023
//Ein Jahr und ein Monat nach Aufgabenbeginn ist der 26.11.2024
//Drei Jahre und 11 Monate nach Aufgabenbeginn ist der 26.9.2027

#include<iostream>
using namespace std;

class Date {

	int _day, _month, _year;

public:
	Date(int day = 0, int month = 0, int year = 0) : _day(day), _month(month), _year(year) {}

	Date operator+(int days) {
		int total_days = _day + days;
		int month = _month + (total_days / 30);
		int day = total_days % 30;
		int year = _year + (month / 12);
		month = month % 12;
		return Date(day, month, year);
	}

	friend ostream& operator<<(ostream& out, const Date& date) {
		out << date._day << "." << date._month << "." << date._year;
		return out;
	}
};

int main(int argc, char* argv[])
{
	Date begin_task = Date(26, 10, 2023);
	cout << "Die Aufgabe beginnt am " << begin_task << endl;
	Date end_task = begin_task + 6;
	cout << "Die Aufgabe endet am " << end_task << endl;
	Date one_year_and_one_month_later = begin_task + 390;
	cout << "Ein Jahr und ein Monat nach Aufgabenbeginn ist der " << one_year_and_one_month_later << endl;
	Date three_years_and_eleven_months_later = begin_task + 1410;
	cout << "Drei Jahre und 11 Monate nach Aufgabenbeginn ist der " << three_years_and_eleven_months_later << endl;
}