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
 *  2. 接口内部使用char*进行实现。
 *
 */

#include <cstdlib>
#include <vector>
#include <climits>
#include <memory>

namespace GiKoo
{
	typedef char GI_STRING_DATA_TYPE;

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
		GiString(const GiString& str);

		/**
		 * @brief 创建GiString对象，指定子串，指定字符集
		 *
		 * @param str 拷贝元
		 * @param offset 子串起点
		 * @param length 子串长度
		 * @param charsetName 字符集名
		 */
		GiString(const GI_STRING_DATA_TYPE* str,
			size_t offset = 0,
			size_t length = SIZE_MAX,
			const GI_STRING_DATA_TYPE* charsetName = nullptr);

		virtual ~GiString();

	public: // 判断类API
		/**
		 * @brief 比较两个字符串
		 *
		 * @param another 待比较的字符串
		 *
		 * @retval null 字符串相同相同
		 * @retval ptr 第一个不相同的字符所在位置
		 */
		virtual const GI_STRING_DATA_TYPE* compareTo(const GiString& another) const;

		/**
		 * @brief 比较两个字符串
		 *
		 * @param another 待比较的字符串
		 *
		 * @retval true 两个字符串相等
		 * @retval false 两个字符串不等
		 */
		virtual bool equals(const GiString& another) const;

		/**
		 * @brief 比较两个字符串
		 *
		 * @param another 待比较的字符串
		 *
		 * @retval true 两个字符串相等
		 * @retval false 两个字符串不等
		 */
		virtual bool operator==(const GiString& another) const;

		/**
		 * @brief 是否符合指定正则表达式
		 *
		 * @param regex 正则表达式
		 *
		 * @retval true 正则表达式匹配成功
		 * @retval false 正则表达式匹配失败
		 */
		virtual bool matches(const GI_STRING_DATA_TYPE* regex) const;

		/**
		 * @brief 是否包含指定字符串
		 *
		 * @param str 指定字符串
		 *
		 * @retval true 包含指定字符串
		 * @retval false 不包含指定字符串
		 */
		virtual bool contains(const GiString& str) const;

		/**
		 * @brief 字符串是否为空，或者只包含空格
		 *
		 * @retval true 字符串为空，或者只包含空格
		 * @retval false 字符串包含非空格字符
		 */
		virtual bool isBlank() const;

		/**
		 * @brief 字符串是否为空，即长度为0
		 *
		 * @retval true 空字符串
		 * @retval false 非空字符串
		 */
		virtual bool isEmpty() const;

	public: // 返回新GiString
		/**
		 * @brief 移除字符串头部和尾部的空格
		 *
		 * @return 修改后的字符串副本
		 */
		virtual GiString strip();

		/**
		 * @brief 移除字符串头部的空格
		 *
		 * @return 修改后的字符串副本
		 */
		virtual GiString stripLeading();

		/**
		 * @brief 移除字符串尾部的空格
		 *
		 * @return 修改后的字符串副本
		 */
		virtual GiString stripTrailing();

		/**
		 * @brief 移除字符串头部和尾部的空格，以及小于0x20的字符
		 *
		 * @return 修改后的字符串副本
		 */
		virtual GiString trim();

		/**
		 * @brief 切换为全小写字符
		 *
		 * @return 替换后的字符串副本
		 */
		virtual GiString toLowerCase() const;

		/**
		 * @brief 切换为全大写字符
		 *
		 * @return 替换后的字符串副本
		 */
		virtual GiString toUpperCase() const;

		/**
		 * @brief 使用新字符替换旧字符
		 *
		 * @param oldChar 旧字符
		 * @param newChar 新字符
		 *
		 * @return 替换后的字符串副本
		 */
		virtual GiString replace(GI_STRING_DATA_TYPE oldChar, GI_STRING_DATA_TYPE newChar) const;

		/**
		 * @brief 使用新字符串替换旧字符串
		 *
		 * @param oldStr 旧字符串
		 * @param newStr 新字符串
		 *
		 * @return 替换后的字符串副本
		 */
		virtual GiString replace(const GiString& oldStr, const GiString& newStr) const;

		/**
		 * @brief 字符串链接，不会改变当前字符串
		 *
		 * @param str 待追加的字符
		 *
		 * @return 新的字符串副本
		 */
		virtual GiString concat(const GiString& str) const;

		/**
		 * @brief 根据指定正则表达式进行拆分
		 *
		 * @param regex 指定正则表达式
		 *
		 * @return 结果集合
		 */
		virtual std::vector<GiString> split(const GiString& regex) const;

		/**
		 * @brief 根据字符串中的换行符进行拆分
		 *
		 * @return 结果集合
		 */
		virtual std::vector<GiString> lines() const;

		/**
		 * @brief 根据指定格式构建字符串
		 *
		 * @param fmt 指定格式
		 *
		 * @return 格式化后的新副本
		 */
		static GiString format(const GiString& fmt, ...);

		/**
		 * @brief 获取子字符串
		 *
		 * @param offset 起点
		 * @param length 长度
		 *
		 * @return 子字符串
		 */
		virtual GiString subString(size_t offset, size_t length = SIZE_MAX) const;

	public: // 修改类API

		/**
		 * @brief 返回指定位置的字符
		 *
		 * @note 如果index是非法数值，将返回0
		 *
		 * @param index 指定位置
		 *
		 * @return 字符
		 */
		virtual GI_STRING_DATA_TYPE& operator[](size_t index);

		/**
		 * @brief 拷贝字符串
		 *
		 * @param str 被拷贝字符串
		*/
		virtual GiString& copy(const GiString& str);

		/**
		 * @brief 拷贝字符串
		 *
		 * @param str 被拷贝字符串
		 * @param length 最大拷贝字符数
		 *
		*/
		virtual GiString& copy(const GI_STRING_DATA_TYPE* str, size_t length = SIZE_MAX);

		/**
		 * @brief 重载等号操作符
		 *
		 * @param str 被拷贝字符串
		 *
		 * @return 自身引用
		*/
		virtual GiString& operator=(const GiString& str);

		/**
		 * @brief 清空字符串
		*/
		virtual void empty();

	public: // 查询类API

		/**
		 * @brief 字符串指针
		 *
		 * @return 返回内部数据变量
		*/
		virtual const GI_STRING_DATA_TYPE* c_str() const;

		/**
		 * @brief 返回指定位置的字符
		 *
		 * @note 如果index是非法数值，将返回0
		 *
		 * @param index 指定位置
		 *
		 * @return 字符
		 */
		virtual GI_STRING_DATA_TYPE charAt(size_t index) const;

		/**
		 * @brief 查询指定字符
		 *
		 * @param ch 指定字符
		 * @param offset 起点
		 *
		 * @return 查询结果。如果未查询到，返回SIZE_MAX
		 */
		virtual size_t indexOf(GI_STRING_DATA_TYPE ch, size_t offset = 0) const;

		/**
		 * @brief 查询指定字符串
		 *
		 * @param str 指定字符串
		 * @param offset The specified index
		 *
		 * @return 查询结果。如果未查询到，返回SIZE_MAX
		 */
		virtual size_t indexOf(const GiString& str, size_t offset = 0) const;

		/**
		 * @brief 倒序查询指定字符
		 *
		 * @param ch 指定字符
		 * @param offset 判断的起点
		 *
		 * @return 查询结果。如果未查询到，返回SIZE_MAX
		 */
		virtual size_t lastIndexOf(GI_STRING_DATA_TYPE ch, size_t offset = 0) const;

		/**
		 * @brief 倒序查询指定字符串
		 *
		 * @param str 指定字符串
		 * @param offset 判断的起点
		 *
		 * @return 查询结果。如果未查询到，返回SIZE_MAX
		 */
		virtual size_t lastIndexOf(const GiString& str, size_t offset = 0) const;

		/**
		 * @brief 获得字符串长度
		 *
		 * @return 字符串长度
		 */
		virtual size_t length() const;

		/**
		 * @brief 获得字符串的hash数值
		 *
		 * @return hash数值
		 */
		virtual size_t hashCode() const;

		/**
		 * @brief 是否包含指定前缀
		 *
		 * @param prefix 前缀
		 * @param offset 判断的起点
		 *
		 * @retval true 包含
		 * @retval false 不包含
		 */
		virtual bool startsWith(const GiString& prefix, size_t offset = SIZE_MAX) const;

		/**
		 * @brief 是否包含指定后缀
		 *
		 * @param suffix 后缀
		 *
		 * @retval true 包含
		 * @retval false 不包含
		 */
		virtual bool endsWith(const GiString& suffix) const;

	private:
		GI_STRING_DATA_TYPE* m_data;
	};
}