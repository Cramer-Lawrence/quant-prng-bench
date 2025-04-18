#include "BenchReport.h"

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

std::string BenchReport::fileName = "BenchmarkReport";
std::ofstream BenchReport::reportFile;

std::string BenchReport::getCurrentTimeForLog()
{
	auto now = std::chrono::system_clock::now();
	auto time_c = std::chrono::system_clock::to_time_t(now);
	std::tm now_tm = *std::localtime(&time_c);
	std::stringstream ss;
	ss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " - ";
	return ss.str();
}

void BenchReport::log(const std::string& logLine)
{
	if (!reportFile.is_open())
	{
		reportFile.open(fileName);
	}	

	reportFile << getCurrentTimeForLog() << logLine << std::endl;
}

void BenchReport::endLog()
{
	if (reportFile.is_open())
		reportFile.close();
}
