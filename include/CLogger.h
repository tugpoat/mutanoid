//==============================================================================
#ifndef _CLOGGER_H_
	#define _CLOGGER_H_

#include <string>
#include <iostream>
#include <fstream>

class CLogger {
public:
	enum LOG_LEVEL {
		LOG_LEVEL_NONE = 0,
		LOG_LEVEL_FATAL = 1,
		LOG_LEVEL_ERR = 2,
		LOG_LEVEL_WARN = 3,
		LOG_LEVEL_DEBUG = 4,
		LOG_LEVEL_VDEBUG = 5, // Verbose debug
		LOG_LEVEL_GFXDEBUG = 6 // Graphics debug
	} LOG_LEVEL;


	CLogger();
	~CLogger();

	void setLevel(int newlevel);

	void log(std::string buf);
	void fatal(std::string buf);
	void err(std::string buf);
	void warn(std::string buf);
	void debug(std::string buf);
	void vdebug(std::string buf);
	void gfxdebug(std::string buf);
protected:
	bool logToConsole(std::string buf, int level = -1);
	bool logToFile(std::string buf, int level = -1);
private:
	int 			log_level;
	std::string		logfile;
	std::ofstream	loghandle;

};
#endif