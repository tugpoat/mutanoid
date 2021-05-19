#include "CLogger.h"

// Simple logger class.
// I should write something more fancy as I start doing more C++ projects again.

//TODO: use va_args for function prototypes and implementations

CLogger::CLogger() {
	loghandle.open("mutanoid.log");
}

CLogger::~CLogger() {
	loghandle.flush();
	loghandle.close();
}

void CLogger::log(std::string buf)
{
	this->logToConsole(buf);
	this->logToFile(buf);
}

void CLogger::fatal(std::string buf)
{
	std::cout << buf << std::endl;
}

void CLogger::err(std::string buf)
{
	buf = "ERR: " + buf;
	this->logToConsole(buf);
	this->logToFile(buf);
}

void CLogger::warn(std::string buf)
{
	buf = "WARN: " + buf;
	this->logToConsole(buf);
	this->logToFile(buf);
}

void CLogger::debug(std::string buf)
{
	buf = "DEBUG: " + buf;
	this->logToConsole(buf);
	this->logToFile(buf);
}

bool CLogger::logToConsole(std::string buf, int level)
{
	std::cout << buf << std::endl;
	return true;
}

bool CLogger::logToFile(std::string buf, int level)
{
	switch (level){
		case -1:
			break;
		case LOG_LEVEL_FATAL:
			buf = "FATAL: " + buf;
			break;
		case LOG_LEVEL_ERR:
			buf = "ERR: " + buf;
			break;
		case LOG_LEVEL_WARN:
			buf = "WARN: " + buf;
			break;
		case LOG_LEVEL_DEBUG:
			buf = "DEBUG: " + buf;
			break;
	}

	// TODO: handle io exceptions
	loghandle << buf << std::endl;

	return true;
}