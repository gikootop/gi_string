﻿#include "gtest/gtest.h"
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