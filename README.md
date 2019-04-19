# Project-4
The most complex project by now  

***Date format: YYYY-MM-DD***

Project of a database that supports the following types of operations:
1) ***Add*** *date event* - adding new *event* with specified *date*
2) ***Print*** - printing ALL the data from the database (like *date event* and so on)
3) ***Find*** *condition* - printing the entries that satisfy given *condition*
4) ***Del*** *condition* - deleting the entries that satisfy given *condition*
5) ***Last*** *date* - printing the last entry prior to the specified *date*

***Exmaples***
1) ***Find date > 2019-01-01*** - printing all events, that happened after 1st of January 2019
2) ***Del date <= 2018-12-31 AND (event == "fishing" OR event = "swimming")*** - deleting the entries named *fishing* or *swimming*, that happened before 31st of December 2018 (including that date) 

***Notes***
1) Unlimited amount of events can be stored in one day
2) If the condition is empty in *Find* and *Del* commands, all events will be printed/deleted
