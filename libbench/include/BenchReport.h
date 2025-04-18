#ifndef BENCHREPORT_H
#define BENCHREPORT_H

#include <string>
#include <fstream>

class BenchReport
{
private:
	static std::string fileName;
	static std::ofstream reportFile;

public:
	BenchReport() = delete;

	static void log(const std::string& logLine);
	static void endLog();
private:
	static std::string getCurrentTimeForLog();
};

#endif
