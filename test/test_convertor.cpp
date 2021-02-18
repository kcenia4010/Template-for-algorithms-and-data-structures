#include <../gtest/gtest.h>
#include <Convertor.h>


TEST(convertor, _3_to_roman)
{
	Convertor C;
	arabic num;
	roman result;
	num.value = 3;
	result = C.toRoman(num);
	EXPECT_EQ(result.value, "III");
}

TEST(convertor, _6_to_roman)
{
	Convertor C;
	arabic num;
	roman result;
	num.value = 6;
	result = C.toRoman(num);
	EXPECT_EQ(result.value, "VI");
}

TEST(convertor, _9_to_roman)
{
	Convertor C;
	arabic num;
	roman result;
	num.value = 9;
	result = C.toRoman(num);
	EXPECT_EQ(result.value, "IX");
}

TEST(convertor, _23_to_roman)
{
	Convertor C;
	arabic num;
	roman result;
	num.value = 23;
	result = C.toRoman(num);
	EXPECT_EQ(result.value, "XXIII");
}

TEST(convertor, _55_to_roman)
{
	Convertor C;
	arabic num;
	roman result;
	num.value = 55;
	result = C.toRoman(num);
	EXPECT_EQ(result.value, "LV");
}

TEST(convertor, _98_to_roman)
{
	Convertor C;
	arabic num;
	roman result;
	num.value = 98;
	result = C.toRoman(num);
	EXPECT_EQ(result.value, "XCVIII");
}

TEST(convertor, _265_to_roman)
{
	Convertor C;
	arabic num;
	roman result;
	num.value = 265;
	result = C.toRoman(num);
	EXPECT_EQ(result.value, "CCLXV");
}

TEST(convertor, _999_to_roman)
{
	Convertor C;
	arabic num;
	roman result;
	num.value = 999;
	result = C.toRoman(num);
	EXPECT_EQ(result.value, "CMXCIX");
}

TEST(convertor, _1994_to_roman)
{
	Convertor C;
	arabic num;
	roman result;
	num.value = 1994;
	result = C.toRoman(num);
	EXPECT_EQ(result.value, "MCMXCIV");
}

TEST(convertor, _3000_to_roman)
{
	Convertor C;
	arabic num;
	roman result;
	num.value = 3000;
	result = C.toRoman(num);
	EXPECT_EQ(result.value, "MMM");
}

TEST(convertor, _3_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "III";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 3);
}

TEST(convertor, _4_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "IV";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 4);
}

TEST(convertor, _5_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "V";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 5);
}

TEST(convertor, _23_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "XXIII";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 23);
}

TEST(convertor, _9_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "IX";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 9);
}

TEST(convertor, _55_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "LV";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 55);
}

TEST(convertor, _98_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "XCVIII";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 98);
}

TEST(convertor, _265_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "CCLXV";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 265);
}

TEST(convertor, _999_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "CMXCIX";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 999);
}

TEST(convertor, _1994_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "MCMXCIV";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 1994);
}

TEST(convertor, _3000_to_arabic)
{
	Convertor C;
	roman num;
	arabic result;
	num.value = "MMM";
	result = C.toArabic(num);
	EXPECT_EQ(result.value, 3000);
}

TEST(convertor, check_true)
{
	Convertor C;
	roman num;
	num.value = "VIII";
	bool res = C.check(num);
	EXPECT_TRUE(res);
	EXPECT_EQ(num.value, "VIII");
}

TEST(convertor, check_IIII)
{
	Convertor C;
	roman num;
	num.value = "IIII";
	bool res = C.check(num);
	EXPECT_FALSE(res);
	EXPECT_EQ(num.value, "IV");
}

TEST(convertor, check_VVVIIII)
{
	Convertor C;
	roman num;
	num.value = "VVIIII";
	bool res = C.check(num);
	EXPECT_FALSE(res);
	EXPECT_EQ(num.value, "XIV");
}

TEST(convertor, check_CCCCXXXX)
{
	Convertor C;
	roman num;
	num.value = "CCCCXXXX";
	bool res = C.check(num);
	EXPECT_FALSE(res);
	EXPECT_EQ(num.value, "CDXL");
}
