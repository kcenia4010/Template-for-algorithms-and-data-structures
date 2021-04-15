#include <../gtest/gtest.h>
#include <Text.h>

TEST(text, create_text)
{
	ASSERT_NO_THROW(Text T);
}

TEST(text, add_head)
{
	Text T;
	T.SetCurr("hello");
	EXPECT_EQ("hello", T.GetCurr());
}

TEST(text, add_next)
{
	Text T;
	T.SetCurr("hello");
	T.addNext(" ");
	T.next();
	T.addNext("world!");
	T.GoHead();
	EXPECT_EQ("hello", T.GetCurr());
	T.next();
	EXPECT_EQ(" ", T.GetCurr());
	T.next();
	EXPECT_EQ("world!", T.GetCurr());
}

TEST(text, add_next_and_down)
{
	Text T;
	T.SetCurr("Heading 1");
	T.addNext("Heading 2");
	T.addDown("Heading 1.1");
	T.down();
	T.addNext("Heading 1.2");
	T.GoHead();
	EXPECT_EQ("Heading 1", T.GetCurr());
	T.down();
	EXPECT_EQ("Heading 1.1", T.GetCurr());
	T.next();
	EXPECT_EQ("Heading 1.2", T.GetCurr());
	T.top();
	T.top();
	T.next();
	EXPECT_EQ("Heading 2", T.GetCurr());
}

TEST(text, delete_down)
{
	Text T;
	T.SetCurr("Heading 1");
	T.addNext("Heading 2");
	T.addDown("Heading 1.1");
	T.down();
	T.addNext("Heading 1.2");
	T.addDown("Heading 1.1.1");
	T.down();
	T.addNext("Heading 1.1.2");

	T.top();
	T.deleteDown();

	T.GoHead();
	EXPECT_EQ("Heading 1", T.GetCurr());
	T.down();
	EXPECT_EQ("Heading 1.1", T.GetCurr());
	T.next();
	EXPECT_EQ("Heading 1.2", T.GetCurr());
	T.top();
	T.top();
	T.next();
	EXPECT_EQ("Heading 2", T.GetCurr());
}

TEST(text, delete_curr)
{
	Text T;
	T.SetCurr("Heading 1");
	T.addNext("Heading 2");
	T.addDown("Heading 1.1");
	T.down();
	T.addNext("Heading 1.2");
	T.addDown("Heading 1.1.1");
	T.down();
	T.addNext("Heading 1.1.2");

	T.top();
	T.deleteCurr();

	T.GoHead();
	EXPECT_EQ("Heading 1", T.GetCurr());
	T.down();
	EXPECT_EQ("Heading 1.2", T.GetCurr());
	T.top();
	T.next();
	EXPECT_EQ("Heading 2", T.GetCurr());
}

TEST(text, delete_head)
{
	Text T;
	T.SetCurr("Heading 1");
	T.deleteCurr();
	ASSERT_NO_THROW(T.SetCurr("Heading1"));
}