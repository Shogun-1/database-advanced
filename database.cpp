#include "database.h"

#include <iostream>
#include <algorithm>
#include <exception>
#include <sstream>
#include <iterator>


ostream& operator<<(ostream& os, const Entry& entry) {
    os << entry.date << " " << entry.event;
    return os;
}

void Database::Add(const Date& date, const string& event) {
	auto result = events[date].count(event);
	if (result == 0 && !event.empty()) {
		db[date].push_back(event);
		events[date].insert(event);
	}
}

void Database::Print(ostream& os) const {
	for (const auto& date : db) {
		for (const auto& entry : db.at(date.first)) {
			os << date.first << " " << entry << endl;
		}
	}
}

string Database::Last (const Date& date) const {
    auto iter = db.upper_bound(date);
    if (iter != begin(db)) {
        ostringstream oss;
        oss << prev(iter) -> first << " " << (prev(iter) -> second).back();
        return oss.str();
    }
	throw invalid_argument("");
}
