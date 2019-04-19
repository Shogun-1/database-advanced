#include "date.h"

#include <iomanip>
#include <exception>
#include <vector>
#include <tuple>
#include <sstream>

Date::Date(int new_year, int new_month, int new_day) {
	if (new_year < 0 || new_year >= 9999) {
		throw logic_error ("Year value is invalid: " + to_string(new_year));
	}
	year = new_year;
	if (new_month < 1 || new_month > 12) {
		throw logic_error ("Month value is invalid: " + to_string(new_month));
	}
	month = new_month;
	if (new_day < 1 || new_day > 31) {
		throw logic_error ("Day value is invalid: " + to_string(new_day));
	}
	day = new_day;
}

int Date::GetYear() const {
	return year;
}

int Date::GetMonth() const {
	return month;
}

int Date::GetDay() const {
	return day;
}

ostream& operator<<(ostream& os, const Date& d) {
	os << setfill ('0');
	os << setw (4) << d.GetYear() << "-" << setw (2) << d.GetMonth() << "-" << setw (2) << d.GetDay();
	return os;
}

bool operator<(const Date& lhs, const Date& rhs) {
	auto lhs_date = make_tuple (lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
	auto rhs_date = make_tuple (rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
	return lhs_date < rhs_date;
}

bool operator>(const Date& lhs, const Date& rhs) {
	auto lhs_date = make_tuple (lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
	auto rhs_date = make_tuple (rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
	return lhs_date > rhs_date;
}

bool operator==(const Date& lhs, const Date& rhs) {
    auto lhs_date = make_tuple (lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
    auto rhs_date = make_tuple (rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
    return lhs_date == rhs_date;
}

bool operator !=(const Date& lhs, const Date& rhs) {
    auto lhs_date = make_tuple (lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
    auto rhs_date = make_tuple (rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
    return lhs_date != rhs_date;
}

bool operator<=(const Date& lhs, const Date& rhs) {
    auto lhs_date = make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
    auto rhs_date = make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
    return lhs_date <= rhs_date;
}

bool operator>=(const Date& lhs, const Date& rhs) {
    auto lhs_date = make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
    auto rhs_date = make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
    return lhs_date >= rhs_date;
}

Date ParseDate (istream& iss) {
	while (iss.peek() == ' ') {
	    iss.ignore(1);
	}
	string date;
	getline (iss, date, ' ');
	istringstream is (date);
	bool format = true;

	int year;
	if (!isdigit(is.peek())) {
		char c;
		c = is.get();
		if (c != '-' && !isdigit(is.peek())) {
			format = false;
		}
		is.unget();
	}
	is >> year;
	if (is.peek() != '-') {
		format = false;
	}
	is.ignore(1);

	int month;
	if (!isdigit(is.peek())) {
		char c;
		c = is.get();
		if (c != '-' && !isdigit(is.peek())) {
			format = false;
		}
		is.unget();
	}
	is >> month;
	if (is.peek() != '-') {
		format = false;
	}
	is.ignore(1);

	int day;
	if (!isdigit(is.peek())) {
		char c;
		c = is.get();
		if (c != '-' && !isdigit(is.peek())) {
			format = false;
		}
		is.unget();
	}
	is >> day;

	if (!format) {
		throw logic_error ("Date format is invalid: " + date);
	}
	return {year, month, day};
}


