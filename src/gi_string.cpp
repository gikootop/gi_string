#include "gikoo/gi_string.h"
#include <cstring>
#include <cmath>
#include <cassert>
#include <unordered_set>

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

GiString::GiString(const GI_STRING_DATA_TYPE* str, size_t offset, size_t length, const GI_STRING_DATA_TYPE* charsetName)
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
	if (m_data)
	{
		delete[] m_data;
	}
}

const GI_STRING_DATA_TYPE* GiString::compareTo(const GiString& another) const
{
	if (isEmpty() && another.isEmpty()) return nullptr;
	if (isEmpty() || another.isEmpty()) return m_data;

	const GI_STRING_DATA_TYPE* cur = m_data;
	const GI_STRING_DATA_TYPE* anotherCur = another.m_data;
	while (*cur != '\0' && *anotherCur != '\0')
	{
		if (*cur != *anotherCur) break;

		++cur;
		++anotherCur;
	}
	
	if (*cur == '\0' && *anotherCur == '\0') return nullptr;

	return cur;
}

bool GiString::equals(const GiString& another) const
{
	return compareTo(another) == nullptr;
}

bool GiString::operator==(const GiString& another) const
{
	return compareTo(another) == nullptr;
}

bool GiString::matches(const GI_STRING_DATA_TYPE* regex) const
{
	// TODO: Not Implements
	return false;
}

bool GiString::contains(const GiString& str) const
{
	return strstr(m_data, str.m_data) != nullptr;
}

bool GiString::isBlank() const
{
	auto cur = m_data;
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

GiString GiString::strip(const GI_STRING_DATA_TYPE* coll)
{
	return stripLeading(coll).stripTrailing(coll);
}

GiString GiString::stripLeading(const GI_STRING_DATA_TYPE* coll)
{
	if (coll == nullptr) coll = " \r\n\t";

	std::unordered_set<GI_STRING_DATA_TYPE> set;
	while (*coll != '\0')
	{
		set.emplace(*coll++);
	}

	char* cur = m_data;
	while (*cur != '\0')
	{
		if (set.find(*cur) != set.end())
			++cur;
		else
			break;
	}
	
	return cur;
}

GiString GiString::stripTrailing(const GI_STRING_DATA_TYPE* coll)
{
	if (coll == nullptr) coll = " \r\n\t";
	std::unordered_set<GI_STRING_DATA_TYPE> set;
	while (*coll != '\0')
	{
		set.emplace(*coll++);
	}
	set.emplace('\0');

	char* cur = m_data + length();
	while (cur >= m_data)
	{
		if (set.find(*cur) != set.end())
			--cur;
		else
			break;
	}

	return subString(0, cur - m_data + 1);
}

GiString GiString::trim()
{
	return trimStart().trimEnd();
}

GiString GiString::trimStart()
{
	char* cur = m_data;
	while (*cur != '\0')
	{
		if (*cur <= 0x20)
			++cur;
		else
			break;
	}
	return cur;
}

GiString GiString::trimEnd()
{
	char* cur = m_data + length();
	while (cur >= m_data)
	{
		if (*cur <= 0x20)
			--cur;
		else
			break;
	}
	return subString(0, cur - m_data + 1);
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

GiString GiString::replace(GI_STRING_DATA_TYPE oldChar, GI_STRING_DATA_TYPE newChar) const
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
	return { m_data, 0, length };
}

GI_STRING_DATA_TYPE& GiString::operator[](size_t index)
{
	if (index >= length())
	{
		index = 0;
	}
	return m_data[index];
}

GiString& GiString::copy(const GiString& str)
{
	size_t realLen = str.length() + 1;
	m_data = new GI_STRING_DATA_TYPE[realLen];
	assert(m_data != nullptr);

	// 内存拷贝
	memcpy(m_data, str.m_data, sizeof(GI_STRING_DATA_TYPE) * realLen);

	// 字符串结束符补位
	m_data[realLen - 1] = 0;

	return *this;
}

GiString& GiString::copy(const GI_STRING_DATA_TYPE* str, size_t length)
{
	if (!str)
	{
		empty();
		return *this;
	}

	size_t realLen = MIN(strlen(str), length) + 1;
	m_data = new GI_STRING_DATA_TYPE[realLen];
	assert(m_data != nullptr);

	// 内存拷贝
	memcpy(m_data, str, sizeof(GI_STRING_DATA_TYPE) * (realLen));

	// 字符串结束符补位
	m_data[realLen - 1] = 0;

	return *this;
}

GiString& GiString::operator=(const GiString& str)
{
	copy(str);
	return *this;
}

void GiString::empty()
{
	m_data = new GI_STRING_DATA_TYPE[1];
	assert(m_data != nullptr);

	m_data[0] = 0;
}

const GI_STRING_DATA_TYPE* GiString::c_str() const
{
	return m_data;
}

GI_STRING_DATA_TYPE GiString::charAt(size_t index) const
{
	assert(m_data != nullptr);
	if (index >= length()) return 0;
	return m_data[index];
}

size_t GiString::indexOf(GI_STRING_DATA_TYPE ch, size_t offset) const
{
	// TODO: Not Implements
	return 0;
}

size_t GiString::indexOf(const GiString& str, size_t offset) const
{
	// TODO: Not Implements
	return 0;
}

size_t GiString::lastIndexOf(GI_STRING_DATA_TYPE ch, size_t offset) const
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
	if (!m_data) return 0;
	return strlen(m_data);
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