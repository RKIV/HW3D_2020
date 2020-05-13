#include "IvyException.h"
# include <sstream>

IvyException::IvyException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* IvyException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* IvyException::GetType() const noexcept
{
	return "Ivy Exception";
}

int IvyException::GetLine() const noexcept
{
	return line;
}

const std::string& IvyException::GetFile() const noexcept
{
	return file;
}

std::string IvyException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}