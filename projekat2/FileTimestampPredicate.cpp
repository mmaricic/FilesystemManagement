#include "FileSelectionDerived.h"
#include <iomanip>
#include "user.h"

FileTimestampPredicate::FileTimestampPredicate(string startt, string stopt){
	struct tm structtime;
	startt = startt + "00:00:00";
	std::istringstream ss1(startt);
	ss1 >> get_time(&structtime, "%d.%m.%Y.%H:%M:%S");
	startTime = mktime(&structtime);
	stopt = stopt + "23:59:59";
	std::istringstream ss2(stopt);
	ss2 >> get_time(&structtime, "%d.%m.%Y.%H:%M:%S");
	stopTime = mktime(&structtime);
	range = 1;
}
FileTimestampPredicate::FileTimestampPredicate(string time){
	struct tm structtime;
	std::istringstream ss(time);
	ss >> get_time(&structtime, "%d.%m.%Y.%H:%M:%S");
	startTime = mktime(&structtime);
	stopTime = 0;
	range = 0;
}

bool FileTimestampPredicate::operator()(File &file){
	if (range) 
		return ((file.getTime() >= startTime) && (file.getTime() <= stopTime));
	return file.getTime() == startTime;
}