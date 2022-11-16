/**
 * @brief GiKoo字符串类
 *
 * @file gi_string.h
 *
 * @details
 *  PI参考的Java文档版本:
 *  1. https://docs.oracle.com/en/java/javase/19/docs/api/java.base/java/lang/String.html
 *  2. https://docs.oracle.com/en/java/javase/19/docs/api/java.base/java/lang/StringBuffer.html
 */

#include <cstdlib>
#include <vector>

namespace GiKoo
{
    /**
     * @brief GiString类
     *
     * @details 一个开箱即用的字符串类。API模仿Java的String，StringBuffer，StringBuilder等类。
     */
    class GiString
    {
    public:
        /**
         * @brief 创建GiString对象
         */
        GiString();

        /**
         * @brief 创建GiString对象
         *
         * @param str 拷贝元
         */
        GiString(const GiString &str);

        /**
         * @brief 创建GiString对象，默认字符集
         *
         * @param str 拷贝元
         */
        GiString(const char *str);

        /**
         * @brief 创建GiString对象，指定字符集
         *
         * @param str 拷贝元
         * @param charsetName 字符集名
         */
        GiString(const char *str, const char *charsetName);

        /**
         * @brief 创建GiString对象，指定子串，指定字符集
         *
         * @param str 拷贝元
         * @param offset 子串起点
         * @param length 子串长度
         * @param charsetName 字符集名
         */
        GiString(const char *str, size_t offset, size_t length, const char *charsetName);

        virtual ~GiString();

    public: // 判断类API
        /**
         * @brief 比较两个字符串
         *
         * @param another 待比较的字符串
         * @retval true 两个字符串相同
         * @retval false 两个字符串不相同
         */
        size_t compareTo(const GiString &another) const;

        /**
         * @brief 是否符合指定正则表达式
         *
         * @param regex 正则表达式
         * @return
         */
        bool matches(const char *regex) const;

        /**
         * @brief 是否包含指定字符串
         *
         * @param str 指定字符串
         * @return
         */
        bool contains(const GiString &str) const;

        /**
         * @brief Returns true if the string is empty or contains only white space codeposize_ts, otherwise false.
         *
         * @return
         */
        bool isBlank() const;

        /**
         * @brief Returns true if, and only if, length() is 0.
         *
         * @return
         */
        bool isEmpty() const;

    public: // 修改类API
        /**
         * @brief Returns a string whose value is this string, with all leading and trailing white space removed.
         *
         * @details If this String object represents an empty string, or if all code posize_ts in this string are white space, then an empty string is returned.\
         *      Otherwise, returns a substring of this string beginning with the first code posize_t that is not a white space up to and including the last code posize_t that is not a white space.\
         *      This method may be used to strip white space from the beginning and end of a string.
         * @return A string whose value is this string, with all leading and trailing white space removed.
         */
        GiString &strip();

        /**
         * @brief Returns a string whose value is this string, with all leading white space removed.
         *
         * @return
         */
        GiString &stripLeading();

        /**
         * @brief Returns a string whose value is this string, with all trailing white space removed.
         *
         * @return
         */
        GiString &stripTrailing();

        /**
         * @brief Returns a string whose value is this string, with all leading and trailing space removed, where space is defined as any character whose codeposize_t is less than or equal to 'U+0020' (the space character).
         *
         * @details If this String object represents an empty character sequence, or the first and last characters of character sequence represented by this String object both have codes that are not space (as defined above), then a reference to this String object is returned.\
         *      Otherwise, if all characters in this string are space (as defined above), then a String object representing an empty string is returned.\
         *      Otherwise, let k be the index of the first character in the string whose code is not a space (as defined above) and let m be the index of the last character in the string whose code is not a space (as defined above). A String object is returned, representing the substring of this string that begins with the character at index k and ends with the character at index m-that is, the result of this.substring(k, m + 1).\
         *      This method may be used to trim space (as defined above) from the beginning and end of a string.
         * @return A string whose value is this string, with all leading and trailing space removed, or this string if it has no leading or trailing space.
         */
        GiString &trim();

        /**
         * @brief Converts all of the characters in this String to lower case.
         *
         * @return
         */
        GiString toLowerCase() const;

        /**
         * @brief Converts all of the characters in this String to upper case.
         *
         * @return
         * @return
         */
        GiString toUpperCase() const;

        /**
         * @brief Returns a string resulting from replacing all occurrences of oldChar in this string with newChar.
         *
         * @param oldChar
         * @param newChar
         * @return
         */
        GiString &replace(char oldChar, char newChar);

        /**
         * @brief Replaces each substring of this string that matches the oldStr with the specified newStr.
         *
         * @param oldStr
         * @param newStr
         * @return
         */
        GiString &replace(const GiString &oldStr, const GiString &newStr);

    public: // 返回新GiString
        /**
         * @brief 字符串链接，不会改变当前字符串
         *
         * @param str 待追加的字符
         * @return 新的字符串副本
         */
        GiString concat(const GiString &str) const;

        /**
         * @brief Splits this string around matches of the given regular expression.
         *
         * @param regex Regular expression.
         * @return Vector of results.
         */
        std::vector<GiString> split(const GiString &regex) const;

        /**
         * @brief Returns lines extracted from this string.
         *
         * @return Vector of results.
         */
        std::vector<GiString> lines() const;

        /**
         * @brief Returns a formatted string using the specified format string and arguments.
         *
         * @param fmt The specified format string.
         * @return
         */
        static GiString format(const GiString &fmt, ...);

        /**
         * @brief Returns a string that is a substring of this string.
         *
         * @param offset
         * @return
         */
        GiString subString(size_t offset) const;

        /**
         * @brief Returns a string that is a substring of this string.
         *
         * @param offset
         * @param length
         * @return
         */
        GiString subString(size_t offset, size_t length) const;

    public: // 查询类API
        /**
         * @brief 返回指定位置的字符
         *
         * @note 如果index是非法数值，将返回0
         *
         * @param index 指定位置
         * @return 字符
         */
        char charAt(size_t index) const;

        /**
         * @brief 返回指定位置的字符
         *
         * @note 如果index是非法数值，将返回0
         *
         * @param index 指定位置
         * @return 字符
         */
        char operator[](size_t index) const;

        /**
         * @brief Returns the index within this string of the first occurrence of the specified character.
         *
         * @param ch The specified character
         * @return
         */
        size_t indexOf(char ch) const;

        /**
         * @brief Returns the index within this string of the first occurrence of the specified character, starting the search at the specified index.
         *
         * @param ch The specified character
         * @param offset The specified index
         * @return
         */
        size_t indexOf(char ch, size_t offset) const;

        /**
         * @brief Returns the index within this string of the first occurrence of the specified string.
         *
         * @param str The specified string
         * @return
         */
        size_t indexOf(const GiString &str) const;

        /**
         * @brief Returns the index within this string of the first occurrence of the specified string, starting the search at the specified index.
         *
         * @param str The specified string
         * @param offset The specified index
         * @return
         */
        size_t indexOf(const GiString &str, size_t offset) const;

        /**
         * @brief Returns the index within this string of the last occurrence of the specified character.
         *
         * @param ch The specified character
         * @return
         */
        size_t lastIndexOf(char ch) const;

        /**
         * @brief Returns the index within this string of the last occurrence of the specified character, searching backward starting at the specified index.
         *
         * @param ch The specified character
         * @param offset The specified index
         * @return
         */
        size_t lastIndexOf(char ch, size_t offset) const;

        /**
         * @brief Returns the index within this string of the last occurrence of the specified string.
         *
         * @param str The specified string
         * @return
         */
        size_t lastIndexOf(const GiString &str) const;

        /**
         * @brief Returns the index within this string of the last occurrence of the specified string, searching backward starting at the specified index.
         *
         * @param str The specified string
         * @param offset The specified index
         * @return
         */
        size_t lastIndexOf(const GiString &str, size_t offset) const;

        /**
         * @brief The length of this string.
         *
         * @return The length of this string.
         */
        size_t length() const;

        /**
         * @brief Returns a hash code for this string.
         *
         * @return
         */
        size_t hashCode() const;

        /**
         * @brief Tests if this string starts with the specified prefix.

         * @param prefix The specified prefix.
         * @retval true Starts with the specified prefix.
         * @retval false Not starts with the specified prefix.
         */
        bool startsWith(const GiString &prefix) const;

        /**
         * @brief Tests if the substring of this string beginning at the specified index starts with the specified prefix.
         *
         * @param prefix The specified prefix.
         * @param offset Substring's beginning index.
         * @retval true Starts with the specified prefix.
         * @retval false Not starts with the specified prefix.
         */
        bool startsWith(const GiString &prefix, size_t offset) const;

        /**
         * @brief Tests if this string ends with the specified suffix.
         *
         * @param suffix
         * @return
         */
        bool endsWith(const GiString &suffix) const;
    };
}