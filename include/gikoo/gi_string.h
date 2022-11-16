#include <cstdlib>
#include <vector>

/// String Document Referrence: 
///     1. https://docs.oracle.com/en/java/javase/19/docs/api/java.base/java/lang/String.html
///     2. https://docs.oracle.com/en/java/javase/19/docs/api/java.base/java/lang/StringBuffer.html

namespace GiKoo
{
    class GiString
    {
    public:
        GiString();

        /// @brief Constructs a new String
        /// @param str GiString
        GiString(const GiString& str);

        /// @brief Constructs a new String by decoding the specified array of characters using the platform's default charset.
        /// @param str Array of characters
        GiString(const char* str);
        
        /// @brief Constructs a new String by decoding the specified array of characters using the specified charset.
        /// @param str Array of characters
        /// @param charsetName The specified charset
        GiString(const char* str, const char* charsetName);

        /// @brief Constructs a new String by decoding the specified subarray of characters using the specified charset.
        /// @param str Array of characters
        /// @param offset Offset of subarray
        /// @param length Length of subarray
        /// @param charsetName The specified charset
        GiString(const char* str, int offset, int length, const char* charsetName);

        virtual ~GiString();

        /// @brief Returns the char value at the specified index.
        /// @param index 
        /// @return 
        char charAt(int index) const;
        
        /// @brief Compares two strings lexicographically.
        /// @param another 
        /// @return 
        int compareTo(const GiString& another) const;

        /// @brief Concatenates the specified string to the end of this string.
        /// @param str 
        /// @return 
        GiString concat(const GiString& str);

        /// @brief Returns the index within this string of the first occurrence of the specified character.
        /// @param ch The specified character
        /// @return 
        int indexOf(char ch) const;

        /// @brief Returns the index within this string of the first occurrence of the specified character, starting the search at the specified index.
        /// @param ch The specified character
        /// @param offset The specified index
        /// @return 
        int indexOf(char ch, int offset) const;

        /// @brief Returns the index within this string of the first occurrence of the specified string.
        /// @param str The specified string
        /// @return 
        int indexOf(const GiString& str) const;

        /// @brief Returns the index within this string of the first occurrence of the specified string, starting the search at the specified index.
        /// @param str The specified string
        /// @param offset The specified index
        /// @return 
        int indexOf(const GiString& str, int offset) const;

        /// @brief Returns the index within this string of the last occurrence of the specified character.
        /// @param ch The specified character
        /// @return 
        int lastIndexOf(char ch) const;

        /// @brief Returns the index within this string of the last occurrence of the specified character, searching backward starting at the specified index.
        /// @param ch The specified character
        /// @param offset The specified index
        /// @return 
        int lastIndexOf(char ch, int offset) const;

        /// @brief Returns the index within this string of the last occurrence of the specified string.
        /// @param str The specified string
        /// @return 
        int lastIndexOf(const GiString& str) const;

        /// @brief Returns the index within this string of the last occurrence of the specified string, searching backward starting at the specified index.
        /// @param str The specified string
        /// @param offset The specified index
        /// @return 
        int lastIndexOf(const GiString& str, int offset) const;

        /// @brief The length of this string.
        /// @return The length of this string.
        int length() const;

        /// @brief Splits this string around matches of the given regular expression.
        /// @param regex Regular expression.
        /// @return Vector of results.
        std::vector<GiString> split(const GiString& regex) const;

        /// @brief Returns lines extracted from this string.
        /// @return Vector of results.
        std::vector<GiString> lines() const;

        /// @brief Tells whether or not this string matches the given regular expression.
        /// @param regex 
        /// @return 
        bool matches(const GiString& regex) const;

        /// @brief Returns true if and only if this string contains the specified string.
        /// @param str 
        /// @return 
        bool contains(const GiString& str) const;

        /// @brief Returns a string resulting from replacing all occurrences of oldChar in this string with newChar.
        /// @param oldChar 
        /// @param newChar 
        /// @return 
        GiString& replace(char oldChar, char newChar);

        /// @brief Replaces each substring of this string that matches the oldStr with the specified newStr.
        /// @param oldStr 
        /// @param newStr 
        /// @return 
        GiString& replace(const GiString& oldStr, const GiString& newStr);

        /// @brief Returns a formatted string using the specified format string and arguments.
        /// @param format The specified format string.
        /// @return 
        static GiString sprintf(const GiString& format, ...);

        /// @brief Returns a hash code for this string.
        /// @return 
        size_t hashCode() const;

        /// @brief Tests if this string starts with the specified prefix.
        /// @param prefix The specified prefix.
        /// @retval true Starts with the specified prefix.
        /// @retval false Not starts with the specified prefix.
        bool startsWith(const GiString& prefix) const;

        /// @brief Tests if the substring of this string beginning at the specified index starts with the specified prefix.
        /// @param prefix The specified prefix.
        /// @param offset Substring's beginning index.
        /// @retval true Starts with the specified prefix.
        /// @retval false Not starts with the specified prefix.
        bool startsWith(const GiString& prefix, int offset) const;

        /// @brief Tests if this string ends with the specified suffix.
        /// @param suffix 
        /// @return 
        bool endsWith(const GiString& suffix) const;

        /// @brief Returns a string whose value is this string, with all leading and trailing white space removed.
        /// @details If this String object represents an empty string, or if all code points in this string are white space, then an empty string is returned.\
        ///     Otherwise, returns a substring of this string beginning with the first code point that is not a white space up to and including the last code point that is not a white space.\
        ///     This method may be used to strip white space from the beginning and end of a string.
        /// @return A string whose value is this string, with all leading and trailing white space removed.
        GiString& strip();

        /// @brief Returns a string whose value is this string, with all leading white space removed.
        /// @return 
        GiString& stripLeading();

        /// @brief Returns a string whose value is this string, with all trailing white space removed.
        /// @return 
        GiString& stripTrailing();

        /// @brief Returns true if the string is empty or contains only white space codepoints, otherwise false.
        /// @return 
        bool isBlank() const;

        /// @brief Returns true if, and only if, length() is 0.
        /// @return 
        bool isEmpty() const;

        /// @brief Returns a string whose value is this string, with all leading and trailing space removed, where space is defined as any character whose codepoint is less than or equal to 'U+0020' (the space character).
        /// @details If this String object represents an empty character sequence, or the first and last characters of character sequence represented by this String object both have codes that are not space (as defined above), then a reference to this String object is returned.\
        ///     Otherwise, if all characters in this string are space (as defined above), then a String object representing an empty string is returned.\
        ///     Otherwise, let k be the index of the first character in the string whose code is not a space (as defined above) and let m be the index of the last character in the string whose code is not a space (as defined above). A String object is returned, representing the substring of this string that begins with the character at index k and ends with the character at index m-that is, the result of this.substring(k, m + 1).\
        ///     This method may be used to trim space (as defined above) from the beginning and end of a string.
        /// @return A string whose value is this string, with all leading and trailing space removed, or this string if it has no leading or trailing space.
        GiString& trim();

        /// @brief Converts all of the characters in this String to lower case.
        /// @return 
        GiString toLowerCase() const;

        /// @brief Converts all of the characters in this String to upper case.
        /// @return 
        /// @return 
        GiString toUpperCase() const;

        /// @brief Returns a string that is a substring of this string.
        /// @param offset 
        /// @return 
        GiString subString(int offset) const;

        /// @brief Returns a string that is a substring of this string.
        /// @param offset 
        /// @param length 
        /// @return 
        GiString subString(int offset, int length) const;
    };
}