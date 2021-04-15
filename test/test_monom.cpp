#include <../gtest/gtest.h>
#include <../polinom_lib/Monom.h>

TEST(monom, can_creat_monom)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;

	ASSERT_NO_THROW(TMonom a(data, 3, 1));
}

TEST(monom, can_get_K)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);
	EXPECT_EQ(a.GetK(), 1);
}

TEST(monom, can_get_dim)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);
	EXPECT_EQ(a.GetDim(), 3);
}

TEST(monom, can_set_K)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);
	a.SetK(-3.2);
	EXPECT_EQ(a.GetK(), -3.2);
}

TEST(monom, can_set_dim)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);
	a.SetDim(4);
	EXPECT_EQ(a.GetDim(), 4);
}

TEST(monom, can_use_operator_index)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);
	
	EXPECT_EQ(a[0], 2);
	EXPECT_EQ(a[1], 7);
	EXPECT_EQ(a[2], 1);
}

TEST(monom, can_use_operator_equal)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);
	double* data1 = new double[4];
	data1[0] = 4;
	data1[1] = 1;
	data1[2] = 1;
	data1[3] = 0;
	TMonom b(data1, 4, -4.5);
	b = a;
	EXPECT_EQ(a[0], b[0]);
	EXPECT_EQ(a[1], b[1]);
	EXPECT_EQ(a[2], b[2]);
}

TEST(monom, can_copy_monom)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);
	TMonom b(a);
	EXPECT_EQ(a[0], b[0]);
	EXPECT_EQ(a[1], b[1]);
	EXPECT_EQ(a[2], b[2]);
}

TEST(monom, can_compare)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);

	double* data1 = new double[3];
	data1[0] = 4;
	data1[1] = 1;
	data1[2] = 1;
	TMonom b(data1, 3, -4.5);

	EXPECT_TRUE(b > a);
	EXPECT_FALSE(a > b);
}

TEST(monom, can_compare_2)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);

	double* data1 = new double[3];
	data1[0] = 4;
	data1[1] = 1;
	data1[2] = 1;
	TMonom b(data1, 3, -4.5);

	EXPECT_FALSE(b < a);
	EXPECT_TRUE(a < b);
}

TEST(monom, can_compare_3)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);

	double* data1 = new double[3];
	data1[0] = 4;
	data1[1] = 1;
	data1[2] = 1;
	TMonom b(data1, 3, -4.5);

	EXPECT_FALSE(b == a);
	b = a;
	EXPECT_TRUE(a == b);
}

TEST(monom, can_use_multiplication)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);

	double* data1 = new double[3];
	data1[0] = 1;
	data1[1] = 0;
	data1[2] = 4;
	TMonom b(data1, 3,  2);

	TMonom c = a* b;;

	EXPECT_EQ(c[0], 3);
	EXPECT_EQ(c[1], 7);
	EXPECT_EQ(c[2], 5);
	EXPECT_EQ(c.GetK(), 2);
}


TEST(monom, can_use_division)
{
	double* data = new double[3];
	data[0] = 2;
	data[1] = 7;
	data[2] = 1;
	TMonom a(data, 3, 1);

	double* data1 = new double[3];
	data1[0] = 1;
	data1[1] = 0;
	data1[2] = 4;
	TMonom b(data1, 3, 2);

	TMonom c(data1, 3, 2);
	c = a / b;
	EXPECT_EQ(c[0], 1);
	EXPECT_EQ(c[1], 7);
	EXPECT_EQ(c[2], -3);
	EXPECT_EQ(c.GetK(), 0.5);
}

TEST(monom, can_use_sum)
{
	double* data = new double[3];
	data[0] = 1;
	data[1] = 0;
	data[2] = 4;
	TMonom a(data, 3, -3);

	double* data1 = new double[3];
	data1[0] = 1;
	data1[1] = 0;
	data1[2] = 4;
	TMonom b(data1, 3, 2);

	TMonom* c;
	c = a + b;
	EXPECT_EQ(c[0][0], 1);
	EXPECT_EQ(c[0][1], 0);
	EXPECT_EQ(c[0][2], 4);
	EXPECT_EQ(c[0].GetK(), -1);
}

TEST(monom, can_use_sum_with_different_data)
{
	double* data = new double[3];
	data[0] = 1;
	data[1] = 8;
	data[2] = 4;
	TMonom a(data, 3, -3);

	double* data1 = new double[3];
	data1[0] = 1;
	data1[1] = 0;
	data1[2] = 4;
	TMonom b(data1, 3, 2);

	TMonom* c;
	c = a + b;
	EXPECT_EQ(c[0][0], 1);
	EXPECT_EQ(c[0][1], 8);
	EXPECT_EQ(c[0][2], 4);
	EXPECT_EQ(c[0].GetK(), -3);
	EXPECT_EQ(c[1][0], 1);
	EXPECT_EQ(c[1][1], 0);
	EXPECT_EQ(c[1][2], 4);
	EXPECT_EQ(c[1].GetK(), 2);
}

TEST(monom, can_use_difference)
{
	double* data = new double[3];
	data[0] = 1;
	data[1] = 0;
	data[2] = 4;
	TMonom a(data, 3, -3);

	double* data1 = new double[3];
	data1[0] = 1;
	data1[1] = 0;
	data1[2] = 4;
	TMonom b(data1, 3, 2);

	TMonom* c;
	c = a - b;
	EXPECT_EQ(c[0][0], 1);
	EXPECT_EQ(c[0][1], 0);
	EXPECT_EQ(c[0][2], 4);
	EXPECT_EQ(c[0].GetK(), -5);
}

TEST(monom, can_use_difference_with_different_data)
{
	double* data = new double[3];
	data[0] = 1;
	data[1] = 0;
	data[2] = 4;
	TMonom a(data, 3, -3);

	double* data1 = new double[3];
	data1[0] = 1;
	data1[1] = 8;
	data1[2] = 4;
	TMonom b(data1, 3, 2);

	TMonom* c;
	c = a - b;
	EXPECT_EQ(c[0][0], 1);
	EXPECT_EQ(c[0][1], 8);
	EXPECT_EQ(c[0][2], 4);
	EXPECT_EQ(c[0].GetK(), -2);
	EXPECT_EQ(c[1][0], 1);
	EXPECT_EQ(c[1][1], 0);
	EXPECT_EQ(c[1][2], 4);
	EXPECT_EQ(c[1].GetK(), -3);
}