#ifndef _Engine_H_
#define _Engine_H_

#include "common.h"
#include <string.h>
#include <string>

namespace Engine
{
	// 获取当前系统时间-毫秒表示
	uint64_t getTimeNow();

	// 获取当前系统时间-秒表示
	int32_t getCurrentTime();

	// 拆分字符串
	void splitString(const std::string& str, const std::string& delimiters, std::vector<std::string>& tokens);

	class TabFile
	{
	public:
		TabFile();
		~TabFile();

		bool load(const char* filename);
		bool loadFromData(const char* data);

		const char* getString(int32_t row, int32_t col, const char* defaultValue);
		int32_t getInteger(int32_t row, int32_t col, const int32_t defaultValue);
		float getFloat(int32_t row, int32_t col, const float defaultValue);

		int32_t RowNum();
		int32_t ColNum();

	private:
		typedef std::vector<std::string> ValueCol;
		typedef std::vector<ValueCol> ValueRow;

		ValueRow mValues;
		int32_t mRowNum;
		int32_t mColNum;
	};

	class LogFile
	{
	public:
		static LogFile* getInstance();

	public:
		LogFile();
		~LogFile();

		void setLogMessageProvider(PLogMessage log);
		void LogMessage(const char* fmt, ...);

	private:
		PLogMessage m_LogDelegate;
	};
};

#endif // _Engine_H_
