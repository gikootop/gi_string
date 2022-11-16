#include "gi_string.h"

using namespace GiKoo;

GiString::GiString(const char *str, size_t offset, size_t length, const char *charsetName)
{
}

GiString::~GiString()
{
}

size_t GiString::compareTo(const GiString &another) const
{
}

bool GiString::matches(const char *regex) const
{
}

bool GiString::contains(const GiString &str) const
{
}

bool GiString::isBlank() const
{
}

bool GiString::isEmpty() const
{
}

GiString GiString::strip()
{
}

GiString GiString::stripLeading()
{
}

GiString GiString::stripTrailing()
{
}

GiString GiString::trim()
{
}

GiString GiString::toLowerCase() const
{
}

GiString GiString::toUpperCase() const
{
}

GiString GiString::replace(const GiString &oldStr, const GiString &newStr) const
{
}

GiString GiString::concat(const GiString &str) const
{
}

std::vector<GiString> GiString::split(const GiString &regex) const
{
}

std::vector<GiString> GiString::lines() const
{
}

GiString GiString::subString(size_t offset, size_t length) const
{
}

char GiString::charAt(size_t index) const
{
}

char &GiString::operator[](size_t index)
{
}

size_t GiString::indexOf(const GiString &str, size_t offset) const
{
}

size_t GiString::lastIndexOf(const GiString &str, size_t offset) const
{
}

size_t GiString::length() const
{
}

size_t GiString::hashCode() const
{
}

bool GiString::startsWith(const GiString &prefix, size_t offset) const
{
}

bool GiString::endsWith(const GiString &suffix) const
{
}
