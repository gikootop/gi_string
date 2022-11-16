/**
 * @brief GiKoo字符串类
 *
 * @file gi_string.h
 * @version 0.1.0
 *
 * @details
 *  1. PI参考的Java文档版本:
 *      a. https://docs.oracle.com/en/java/javase/19/docs/api/java.base/java/lang/String.html
 *      b. https://docs.oracle.com/en/java/javase/19/docs/api/java.base/java/lang/StringBuffer.html
 *
 *  2. 当前接口未实现实装。
 *
 */

#include <cstdlib>
#include <vector>
#include <climits>

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
         *
         * @retval true 正则表达式匹配成功
         * @retval false 正则表达式匹配失败
         */
        bool matches(const char *regex) const;

        /**
         * @brief 是否包含指定字符串
         *
         * @param str 指定字符串
         *
         * @retval true 包含指定字符串
         * @retval false 不包含指定字符串
         */
        bool contains(const GiString &str) const;

        /**
         * @brief 字符串是否为空，或者只包含空格
         *
         * @retval true 字符串为空，或者只包含空格
         * @retval false 字符串包含非空格字符
         */
        bool isBlank() const;

        /**
         * @brief 字符串是否为空，即长度为0
         *
         * @retval true 空字符串
         * @retval false 非空字符串
         */
        bool isEmpty() const;

    public: // 返回新GiString
        /**
         * @brief 移除字符串头部和尾部的空格
         *
         * @return 修改后的字符串副本
         */
        GiString strip();

        /**
         * @brief 移除字符串头部的空格
         *
         * @return 修改后的字符串副本
         */
        GiString stripLeading();

        /**
         * @brief 移除字符串尾部的空格
         *
         * @return 修改后的字符串副本
         */
        GiString stripTrailing();

        /**
         * @brief Returns a string whose value is this string, with all leading and trailing space removed, where space is defined as any character whose codeposize_t is less than or equal to 'U+0020' (the space character).
         *
         * @details If this String object represents an empty character sequence, or the first and last characters of character sequence represented by this String object both have codes that are not space (as defined above), then a reference to this String object is returned.\
         *      Otherwise, if all characters in this string are space (as defined above), then a String object representing an empty string is returned.\
         *      Otherwise, let k be the index of the first character in the string whose code is not a space (as defined above) and let m be the index of the last character in the string whose code is not a space (as defined above). A String object is returned, representing the substring of this string that begins with the character at index k and ends with the character at index m-that is, the result of this.substring(k, m + 1).\
         *      This method may be used to trim space (as defined above) from the beginning and end of a string.
         *
         * @return A string whose value is this string, with all leading and trailing space removed, or this string if it has no leading or trailing space.
         */
        GiString trim();

        /**
         * @brief 切换为全小写字符
         *
         * @return 替换后的字符串副本
         */
        GiString toLowerCase() const;

        /**
         * @brief 切换为全大写字符
         *
         * @return 替换后的字符串副本
         */
        GiString toUpperCase() const;

        /**
         * @brief 使用新字符替换旧字符
         *
         * @param oldChar 旧字符
         * @param newChar 新字符
         *
         * @return 替换后的字符串副本
         */
        GiString replace(char oldChar, char newChar) const;

        /**
         * @brief 使用新字符串替换旧字符串
         *
         * @param oldStr 旧字符串
         * @param newStr 新字符串
         *
         * @return 替换后的字符串副本
         */
        GiString replace(const GiString &oldStr, const GiString &newStr) const;

        /**
         * @brief 字符串链接，不会改变当前字符串
         *
         * @param str 待追加的字符
         *
         * @return 新的字符串副本
         */
        GiString concat(const GiString &str) const;

        /**
         * @brief 根据指定正则表达式进行拆分
         *
         * @param regex 指定正则表达式
         *
         * @return 结果集合
         */
        std::vector<GiString> split(const GiString &regex) const;

        /**
         * @brief 根据字符串中的换行符进行拆分
         *
         * @return 结果集合
         */
        std::vector<GiString> lines() const;

        /**
         * @brief 根据指定格式构建字符串
         *
         * @param fmt 指定格式
         *
         * @return 格式化后的新副本
         */
        static GiString format(const GiString &fmt, ...);

        /**
         * @brief 获取子字符串
         *
         * @param offset 起点
         *
         * @return 子字符串
         */
        GiString subString(size_t offset) const;

        /**
         * @brief 获取子字符串
         *
         * @param offset 起点
         * @param length 长度
         *
         * @return 子字符串
         */
        GiString subString(size_t offset, size_t length) const;

    public: // 查询类API
        /**
         * @brief 返回指定位置的字符
         *
         * @note 如果index是非法数值，将返回0
         *
         * @param index 指定位置
         *
         * @return 字符
         */
        char charAt(size_t index) const;

        /**
         * @brief 返回指定位置的字符
         *
         * @note 如果index是非法数值，将返回0
         *
         * @param index 指定位置
         *
         * @return 字符
         */
        char operator[](size_t index) const;

        /**
         * @brief 查询指定字符
         *
         * @param ch 指定字符
         *
         * @return 查询结果。如果未查询到，返回SIZE_MAX
         */
        size_t indexOf(char ch) const;

        /**
         * @brief 查询指定字符
         *
         * @param ch 指定字符
         * @param offset The specified index
         *
         * @return 查询结果。如果未查询到，返回SIZE_MAX
         */
        size_t indexOf(char ch, size_t offset) const;

        /**
         * @brief 查询指定字符串
         *
         * @param str 指定字符串
         *
         * @return 查询结果。如果未查询到，返回SIZE_MAX
         */
        size_t indexOf(const GiString &str) const;

        /**
         * @brief 查询指定字符串
         *
         * @param str 指定字符串
         * @param offset The specified index
         *
         * @return 查询结果。如果未查询到，返回SIZE_MAX
         */
        size_t indexOf(const GiString &str, size_t offset) const;

        /**
         * @brief 倒序查询指定字符
         *
         * @param ch 指定字符
         *
         * @return 查询结果。如果未查询到，返回SIZE_MAX
         */
        size_t lastIndexOf(char ch) const;

        /**
         * @brief 倒序查询指定字符
         *
         * @param ch 指定字符
         * @param offset 判断的起点
         *
         * @return 查询结果。如果未查询到，返回SIZE_MAX
         */
        size_t lastIndexOf(char ch, size_t offset) const;

        /**
         * @brief 倒序查询指定字符串
         *
         * @param str 指定字符串
         *
         * @return 查询结果。如果未查询到，返回SIZE_MAX
         */
        size_t lastIndexOf(const GiString &str) const;

        /**
         * @brief 倒序查询指定字符串
         *
         * @param str 指定字符串
         * @param offset 判断的起点
         *
         * @return 查询结果。如果未查询到，返回SIZE_MAX
         */
        size_t lastIndexOf(const GiString &str, size_t offset) const;

        /**
         * @brief 获得字符串长度
         *
         * @return 字符串长度
         */
        size_t length() const;

        /**
         * @brief 获得字符串的hash数值
         *
         * @return hash数值
         */
        size_t hashCode() const;

        /**
         * @brief 是否包含指定前缀
         *
         * @param prefix 前缀
         *
         * @retval true 包含
         * @retval false 不包含
         */
        bool startsWith(const GiString &prefix) const;

        /**
         * @brief 是否包含指定前缀
         *
         * @param prefix 前缀
         * @param offset 判断的起点
         *
         * @retval true 包含
         * @retval false 不包含
         */
        bool startsWith(const GiString &prefix, size_t offset) const;

        /**
         * @brief 是否包含指定后缀
         *
         * @param suffix 后缀
         *
         * @retval true 包含
         * @retval false 不包含
         */
        bool endsWith(const GiString &suffix) const;
    };
}