#include <../gtest/gtest.h>
#include <../polinom_lib/Polinom.h>

TEST(polinom, creat_polinom)
{
	ASSERT_NO_THROW(TPolinom p1);
}

TEST(polinom, can_add_monoms)
{
	TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
	TPolinom p1;
	ASSERT_NO_THROW(p1 += a);
}

TEST(polinom, can_add_monoms2)
{
	TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
	TMonom b(new double[3]{ 3, 2, 3 }, 3, 1);
	TPolinom p1;
	p1 += a;
	ASSERT_NO_THROW(p1 += b);
}

TEST(polinom, can_add_monoms3)
{
	TMonom a(new double[3]{ 1, 2, 3 }, 3, 1);
	TMonom b(new double[3]{ 3, 2, 3 }, 3, 1);
	TPolinom p1;
	p1 += b;
	ASSERT_NO_THROW(p1 += a);
}

TEST(polinom, can_mult)
{
	TMonom a(new double[2]{ 1, 0}, 2, 2);
	TMonom b(new double[2]{ 0, 1 }, 2, 1);
	TPolinom p1, p2;

	p1 += a;
	p2 += b;
	TPolinom p3;
	ASSERT_NO_THROW(p3 = p1 * p2);
}

TEST(polinom, plus)
{
	TMonom a(new double[2]{ 1, 0 }, 2, 2);
	TMonom b(new double[2]{ 0, 1 }, 2, 1);
	TPolinom p1, p2;

	p1 += a;
	p2 += b;
	TPolinom p3;
	ASSERT_NO_THROW(p3 = p1 + p2);
}

TEST(polinom, minus)
{
	TMonom a(new double[2]{ 1, 0 }, 2, 2);
	TMonom b(new double[2]{ 0, 1 }, 2, 1);
	TPolinom p1, p2;

	p1 += a;
	p2 += b;
	TPolinom p3;
	ASSERT_NO_THROW(p3 = p1 - p2);
}