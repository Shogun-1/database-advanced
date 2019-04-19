#pragma once

#include "date.h"

#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <set>

using namespace std;

struct Entry {
    Date date;
    string event;
};

ostream& operator<<(ostream& os, const Entry& entry);

class Database {
public:
	void Add (const Date& date, const string& event);

	void Print (ostream& os) const;

	string Last (const Date& date) const;

	template <typename Func>
	int RemoveIf (Func function) {
	    int counter = 0;
            for (auto it = db.begin(); it != db.end(); ) {
                Date Key = it -> first;
                auto part = stable_partition (it -> second.begin(), it -> second. end(), [function, Key] (string s) {
                    return !function (Key, s);
                });
                for (auto it2 = it -> second.end(); it2 > part; ) {
                    it2--;
                    events[it -> first].erase(*it2);
                    it -> second.erase(it2);
                    counter++;
                }

                if (((it)->second).empty()) {
                    it = db.erase(it);
                } else {
                    ++it;
                }
            }
            return counter;
        }

    template <typename Func>
    vector <Entry> FindIf (Func function) const {
        vector <Entry> res;
        for (const auto& item : db) {
            for (const auto& event : item.second) {
                if (function(item.first, event)) res.push_back({item.first, event});
            }
        }
        return res;
    }

private:
	map <Date, vector<string>> db;
	map <Date, set<string>> events;
};
