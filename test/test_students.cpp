#include <../gtest/gtest.h>
#include <Students.h>

TEST(students, create_a_student)
{
	Date D;
	D.day = 1;
	D.month = 9;
	D.year = 1999;
	ASSERT_NO_THROW(Student S("John", "Smith", D, 3));
}

TEST(Students, next_year)
{
	Date D;
	D.day = 1;
	D.month = 9;
	D.year = 1999; 
	Student S("John", "Smith", D, 3);
	S.NextCourse();
	EXPECT_EQ(4, S.GetCourse());
}

TEST(Students, change_lastname)
{
	Date D;
	D.day = 1;
	D.month = 9;
	D.year = 1999;
	Student S("John", "Smith", D, 3);
	S.ChangeLastName("Green");
	EXPECT_EQ("John Green", S.GetName());
}
