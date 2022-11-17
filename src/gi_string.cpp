#include "gikoo/gi_string.h"

using namespace GiKoo;

GiString::GiString(const char *str, size_t offset, size_t length, const char *charsetName)
{
}

GiString::~GiString()
{
}

size_t GiString::compareTo(const GiString &another) const
{
    return 0;
}

bool GiString::matches(const char *regex) const
{
    return false;
}

bool GiString::contains(const GiString &str) const
{
    return false;
}

bool GiString::isBlank() const
{
    return false;
}

bool GiString::isEmpty() const
{
    return false;
}

GiString GiString::strip()
{
    return "";
}

GiString GiString::stripLeading()
{
    return "";
}

GiString GiString::stripTrailing()
{
    return "";
}

GiString GiString::trim()
{
    return "";
}

GiString GiString::toLowerCase() const
{
    return "";
}

GiString GiString::toUpperCase() const
{
    return "";
}

GiString GiString::replace(const GiString &oldStr, const GiString &newStr) const
{
    return "";
}

GiString GiString::concat(const GiString &str) const
{
    return "";
}

std::vector<GiString> GiString::split(const GiString &regex) const
{
    std::vector<GiString> ret;
    return ret;
}

std::vector<GiString> GiString::lines() const
{
    std::vector<GiString> ret;
    return ret;
}

GiString GiString::subString(size_t offset, size_t length) const
{
    return "";
}

char GiString::charAt(size_t index) const
{
    return '\0';
}

char &GiString::operator[](size_t index)
{
    static char ret;
    return ret;
}

size_t GiString::indexOf(const GiString &str, size_t offset) const
{
    return 0;
}

size_t GiString::lastIndexOf(const GiString &str, size_t offset) const
{
    return 0;
}

size_t GiString::length() const
{
    return 0;
}

size_t GiString::hashCode() const
{
    return 0;
}

bool GiString::startsWith(const GiString &prefix, size_t offset) const
{
    return false;
}

bool GiString::endsWith(const GiString &suffix) const
{
    return false;
}
