#include "gtest/gtest.h"
#include "gikoo/gi_string.h"

using namespace GiKoo;

TEST(GiStringUnit, Construction) {
	GiString a;
	EXPECT_EQ(a.c_str()[0], 0);

	GiString b = "a";
	EXPECT_EQ(b.c_str()[0], 'a');
	EXPECT_EQ(b.c_str()[1], '\0');
	EXPECT_EQ(b.length(), 1);

	GiString c = "ab";
	EXPECT_EQ(c.c_str()[0], 'a');
	EXPECT_EQ(c.c_str()[1], 'b');
	EXPECT_EQ(c.c_str()[2], '\0');
	EXPECT_EQ(c.length(), 2);

	GiString d = c;
	EXPECT_EQ(d.c_str()[0], 'a');
	EXPECT_EQ(d.c_str()[1], 'b');
	EXPECT_EQ(d.c_str()[2], '\0');
	EXPECT_EQ(d.length(), 2);

	EXPECT_TRUE(true);
}

TEST(GiStringUnit, ParamConstruction) {

	GiString a = { "abcd", 1 };
	EXPECT_EQ(a.c_str()[0], 'b');
	EXPECT_EQ(a.c_str()[1], 'c');
	EXPECT_EQ(a.c_str()[2], 'd');
	EXPECT_EQ(a.c_str()[3], '\0');
	EXPECT_EQ(a.length(), 3);

	GiString b = { "abcd", 1, 2 };
	EXPECT_EQ(b.c_str()[0], 'b');
	EXPECT_EQ(b.c_str()[1], 'c');
	EXPECT_EQ(b.c_str()[2], '\0');
	EXPECT_EQ(b.length(), 2);

	EXPECT_TRUE(true);
}

TEST(GiStringUnit, Compare) {

	GiString a = { "abcd" };
	GiString b = { "abcd" };
	GiString c = { "" };
	GiString d = { "aecd" };
	GiString e;

	EXPECT_TRUE(a.equals(b));
	EXPECT_TRUE(b.equals(a));
	EXPECT_FALSE(a.equals(c));
	EXPECT_FALSE(c.equals(a));
	EXPECT_FALSE(a.equals(d));
	EXPECT_FALSE(d.equals(a));
	EXPECT_FALSE(a.equals(e));
	EXPECT_FALSE(e.equals(a));
	EXPECT_TRUE(c.equals(e));
	EXPECT_TRUE(e.equals(c));
}
TEST(GiStringUnit, strip) {
	GiString a = { " abcd" };
	EXPECT_TRUE(a.strip().equals("abcd"));

	a = "\tabcd";
	EXPECT_TRUE(a.strip().equals("abcd"));

	a = "\rabcd";
	EXPECT_TRUE(a.strip().equals("abcd"));

	a = "\nabcd";
	EXPECT_TRUE(a.strip().equals("abcd"));

	a = "abcd ";
	EXPECT_TRUE(a.strip().equals("abcd"));

	a = "   \r\nabcd ";
	EXPECT_TRUE(a.strip().equals("abcd"));

	a = "   \r\nabcd ";
	EXPECT_TRUE(a.strip(" ").equals("\r\nabcd"));

	a = "   \nabcd ";
	EXPECT_TRUE(a.strip(" \r").equals("\nabcd"));

	a = " ";
	EXPECT_TRUE(a.strip().equals(""));

	a = "";
	EXPECT_TRUE(a.strip().equals(""));

	a = "abcd \n\t edf";
	EXPECT_TRUE(a.strip().equals("abcd \n\t edf"));
}

TEST(GiStringUnit, stripLeading) {
	GiString a = { " abcd" };
	EXPECT_TRUE(a.stripLeading().equals("abcd"));

	a = "\tabcd";
	EXPECT_TRUE(a.stripLeading().equals("abcd"));

	a = "\rabcd";
	EXPECT_TRUE(a.stripLeading().equals("abcd"));

	a = "\nabcd";
	EXPECT_TRUE(a.stripLeading().equals("abcd"));

	a = "abcd ";
	EXPECT_TRUE(a.stripLeading().equals("abcd "));

	a = "   \r\nabcd ";
	EXPECT_TRUE(a.stripLeading().equals("abcd "));

	a = "   \r\nabcd ";
	EXPECT_TRUE(a.stripLeading(" ").equals("\r\nabcd "));

	a = "   \nabcd ";
	EXPECT_TRUE(a.stripLeading(" \r").equals("\nabcd "));

	a = " ";
	EXPECT_TRUE(a.stripLeading().equals(""));

	a = "";
	EXPECT_TRUE(a.stripLeading().equals(""));

	a = "abcd \n\t edf";
	EXPECT_TRUE(a.stripLeading().equals("abcd \n\t edf"));
}

TEST(GiStringUnit, stripTrailing) {
	GiString a = { "abcd " };
	EXPECT_TRUE(a.stripTrailing().equals("abcd"));

	a = "abcd\t";
	EXPECT_TRUE(a.stripTrailing().equals("abcd"));

	a = "abcd\r";
	EXPECT_TRUE(a.stripTrailing().equals("abcd"));

	a = "abcd\n";
	EXPECT_TRUE(a.stripTrailing().equals("abcd"));

	a = " abcd";
	EXPECT_TRUE(a.stripTrailing().equals(" abcd"));

	a = "abcd   \r\n";
	EXPECT_TRUE(a.stripTrailing().equals("abcd"));

	a = "abcd   \r\n";
	EXPECT_TRUE(a.stripTrailing(" ").equals("abcd   \r\n"));

	a = "abcd\r\n   ";
	EXPECT_TRUE(a.stripTrailing(" ").equals("abcd\r\n"));

	a = " abcd  \n";
	EXPECT_TRUE(a.stripTrailing(" \r").equals(" abcd  \n"));

	a = " abcd  \n";
	EXPECT_TRUE(a.stripTrailing(" \n").equals(" abcd"));

	a = " ";
	EXPECT_TRUE(a.stripTrailing().equals(""));

	a = "";
	EXPECT_TRUE(a.stripTrailing().equals(""));

	a = "abcd \n\t edf";
	EXPECT_TRUE(a.stripTrailing().equals("abcd \n\t edf"));
}

TEST(GiStringUnit, trim) {
	GiString a = { "abcd " };
	EXPECT_TRUE(a.trim().equals("abcd"));

	a = "abcd\t";
	EXPECT_TRUE(a.trim().equals("abcd"));

	a = "abcd\r";
	EXPECT_TRUE(a.trim().equals("abcd"));

	a = "abcd\n";
	EXPECT_TRUE(a.trim().equals("abcd"));

	a = " abcd";
	EXPECT_TRUE(a.trim().equals("abcd"));

	a = "abcd   \r\n";
	EXPECT_TRUE(a.trim().equals("abcd"));

	a = "abcd\r\n   ";
	EXPECT_TRUE(a.trim().equals("abcd"));

	a = " abcd  \n";
	EXPECT_TRUE(a.trim().equals("abcd"));

	a = " abcd  \n";
	EXPECT_TRUE(a.trim().equals("abcd"));

	a = " ";
	EXPECT_TRUE(a.trim().equals(""));

	a = "";
	EXPECT_TRUE(a.trim().equals(""));

	a = "abcd \n\t edf";
	EXPECT_TRUE(a.trim().equals("abcd \n\t edf"));
}

TEST(GiStringUnit, trimStart) {
	GiString a = { "abcd " };
	EXPECT_TRUE(a.trimStart().equals("abcd "));

	a = "abcd\t";
	EXPECT_TRUE(a.trimStart().equals("abcd\t"));

	a = "abcd\r";
	EXPECT_TRUE(a.trimStart().equals("abcd\r"));

	a = "abcd\n";
	EXPECT_TRUE(a.trimStart().equals("abcd\n"));

	a = " abcd";
	EXPECT_TRUE(a.trimStart().equals("abcd"));

	a = "abcd   \r\n";
	EXPECT_TRUE(a.trimStart().equals("abcd   \r\n"));

	a = "abcd\r\n   ";
	EXPECT_TRUE(a.trimStart().equals("abcd\r\n   "));

	a = " abcd  \n";
	EXPECT_TRUE(a.trimStart().equals("abcd  \n"));

	a = " abcd  \n";
	EXPECT_TRUE(a.trimStart().equals("abcd  \n"));

	a = " ";
	EXPECT_TRUE(a.trimStart().equals(""));

	a = "";
	EXPECT_TRUE(a.trimStart().equals(""));

	a = "abcd \n\t edf";
	EXPECT_TRUE(a.trimStart().equals("abcd \n\t edf"));
}

TEST(GiStringUnit, trimEnd) {
	GiString a = { "abcd " };
	EXPECT_TRUE(a.trimEnd().equals("abcd"));

	a = "abcd\t";
	EXPECT_TRUE(a.trimEnd().equals("abcd"));

	a = "abcd\r";
	EXPECT_TRUE(a.trimEnd().equals("abcd"));

	a = "abcd\n";
	EXPECT_TRUE(a.trimEnd().equals("abcd"));

	a = " abcd";
	EXPECT_TRUE(a.trimEnd().equals(" abcd"));

	a = "abcd   \r\n";
	EXPECT_TRUE(a.trimEnd().equals("abcd"));

	a = "abcd\r\n   ";
	EXPECT_TRUE(a.trimEnd().equals("abcd"));

	a = " abcd  \n";
	EXPECT_TRUE(a.trimEnd().equals(" abcd"));

	a = " abcd  \n";
	EXPECT_TRUE(a.trimEnd().equals(" abcd"));

	a = " ";
	EXPECT_TRUE(a.trimEnd().equals(""));

	a = "";
	EXPECT_TRUE(a.trimEnd().equals(""));

	a = "abcd \n\t edf";
	EXPECT_TRUE(a.trimEnd().equals("abcd \n\t edf"));
}