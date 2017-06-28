
#include "base.h"

std::ofstream logFile;
void log(const std::string& txt){

	time_t current_time;
	struct tm * time_info;
	char timeString[9];  // espacio para "HH:MM:SS\0"

	time(&current_time);
	time_info = localtime(&current_time);
	strftime(timeString, sizeof(timeString), "%H:%M:%S", time_info);

	logFile << timeString << " : " << txt << std::endl;
}
