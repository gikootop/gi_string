#include "gikoo/gi_string.h"
#include <cstring>
#include <cmath>

#define MIN(x,y) (x > y ? y : x)
#define MAX(x,y) (x > y ? x : y)

#define UNUSED_VAR(x) ((void)x)

using namespace GiKoo;

GiString::GiString()
{
	empty();
}

GiString::GiString(const GiString& str)
{
	copy(str);
}

GiString::GiString(const char* str, size_t offset, size_t length, const char* charsetName)
{
	// TODO: 未使用的变量
	UNUSED_VAR(charsetName);

	// 空指针防御
	if (!str)
	{
		empty();
		return;
	}

	// offset非法防御
	size_t strLen = strlen(str);
	if (offset >= strLen)
	{
		empty();
		return;
	}

	// 字符串拷贝处理
	copy(str + offset, length);
}

GiString::~GiString()
{
}

const char* GiString::compareTo(const GiString& another) const
{
	if (!isEmpty() && !another.isEmpty()) return nullptr;
	if (!isEmpty() || !another.isEmpty()) return m_data.get();

	// TODO: 未实现
	return nullptr;
}

bool GiString::equals(const GiString& another) const
{
	return compareTo(another) == nullptr;
}

bool GiString::operator==(const GiString& another) const
{
	return compareTo(another) == nullptr;
}

bool GiString::matches(const char* regex) const
{
	// TODO: Not Implements
	return false;
}

bool GiString::contains(const GiString& str) const
{
	// TODO: Not Implements
	return false;
}

bool GiString::isBlank() const
{
	auto cur = m_data.get();
	while (*cur != '\0')
	{
		if (*cur != ' ') return false;
		++cur;
	}
	return true;
}

bool GiString::isEmpty() const
{
	return length() == 0;
}

GiString GiString::strip()
{
	// TODO: Not Implements
	return "";
}

GiString GiString::stripLeading()
{
	// TODO: Not Implements
	return "";
}

GiString GiString::stripTrailing()
{
	// TODO: Not Implements
	return "";
}

GiString GiString::trim()
{
	// TODO: Not Implements
	return "";
}

GiString GiString::toLowerCase() const
{
	// TODO: Not Implements
	return "";
}

GiString GiString::toUpperCase() const
{
	// TODO: Not Implements
	return "";
}

GiString GiString::replace(char oldChar, char newChar) const
{
	// TODO: Not Implements
	return "";
}

GiString GiString::replace(const GiString& oldStr, const GiString& newStr) const
{
	// TODO: Not Implements
	return "";
}

GiString GiString::concat(const GiString& str) const
{
	// TODO: Not Implements
	return "";
}

std::vector<GiString> GiString::split(const GiString& regex) const
{
	// TODO: Not Implements
	std::vector<GiString> ret;
	return ret;
}

std::vector<GiString> GiString::lines() const
{
	// TODO: Not Implements
	std::vector<GiString> ret;
	return ret;
}

GiString GiString::subString(size_t offset, size_t length) const
{
	// TODO: Not Implements
	return "";
}

char& GiString::operator[](size_t index)
{
	if (index >= length())
	{
		index = 0;
	}
	return m_data.get()[index];
}

GiString& GiString::copy(const GiString& str)
{
	m_data = str.m_data;
	return *this;
}

GiString& GiString::copy(const char* str, size_t length)
{
	if (!str)
	{
		empty();
		return *this;
	}

	size_t realLen = MIN(strlen(str) + 1, length);
	m_data = std::shared_ptr<char>(new char[realLen](), std::default_delete<char[]>());

	// 内存拷贝
	auto c_str = m_data.get();
	memcpy(c_str, str, sizeof(char) * realLen);

	// 字符串结束符补位
	c_str[realLen] = 0;

	return *this;
}

GiString& GiString::operator=(const GiString& str)
{
	copy(str);
	return *this;
}

void GiString::empty()
{
	m_data = std::shared_ptr<char>(new char[1](), std::default_delete<char[]>());
	m_data.get()[0] = 0;
}

const char* GiString::c_str() const
{
	return m_data.get();
}

char GiString::charAt(size_t index) const
{
	if (index >= length()) return 0;
	return m_data.get()[index];
}

size_t GiString::indexOf(char ch, size_t offset) const
{
	// TODO: Not Implements
	return 0;
}

size_t GiString::indexOf(const GiString& str, size_t offset) const
{
	// TODO: Not Implements
	return 0;
}

size_t GiString::lastIndexOf(char ch, size_t offset) const
{
	// TODO: Not Implements
	return 0;
}

size_t GiString::lastIndexOf(const GiString& str, size_t offset) const
{
	// TODO: Not Implements
	return 0;
}

size_t GiString::length() const
{
	auto c_str = m_data.get();
	if (!c_str) return 0;
	return strlen(c_str);
}

size_t GiString::hashCode() const
{
	// TODO: Not Implements
	return 0;
}

bool GiString::startsWith(const GiString& prefix, size_t offset) const
{
	// TODO: Not Implements
	return false;
}

bool GiString::endsWith(const GiString& suffix) const
{
	// TODO: Not Implements
	return false;
}

GiString GiString::format(const GiString& fmt, ...)
{
	return "";
}