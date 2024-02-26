#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <cstdarg>
#include "head.h"

TEST(Sum, SumOfMultiplePositiveNumbers) {
	string arr1[] = {"123", "345"};
	const string* txt1 = &arr1[0];
	EXPECT_EQ(Sum(2, txt1), "468");
	EXPECT_EQ(Sum(2, "123", "345"), "468");
	string output;
	Sum(&output, 2, txt1);
	EXPECT_EQ(output, "468");

	string arr2[] = {"123", "345", "999"};
	const string* txt2 = &arr2[0];
	EXPECT_EQ(Sum(3, txt2), "1467");
	EXPECT_EQ(Sum(3, "123", "345", "999"), "1467");

	string arr3[] = {"123", "345", "999", "0", "0"};
	const string* txt3 = &arr3[0];
	EXPECT_EQ(Sum(5, txt3), "1467");

	string arr4[] = {"123", "345", "999", "1000000", "1"};
	const string* txt4 = &arr4[0];
	EXPECT_EQ(Sum(5, txt4), "1001468");

	string arr5[] = {"9999", "9999"};
	const string* txt5 = &arr5[0];
	EXPECT_EQ(Sum(2, txt5), "19998");
}

 TEST(Sum, SumWithLeadingZeros) {
	string arr5[] = {"00000000000", "0"};
	const string* txt5 = &arr5[0];
	EXPECT_EQ(Sum(2, txt5), "0");

	string arr6[] = {"00000000000", "1"};
	const string* txt6 = &arr6[0];
	EXPECT_EQ(Sum(2, txt6), "1");

	string arr7[] = {"00000000001", "0"};
	const string* txt7 = &arr7[0];
	EXPECT_EQ(Sum(2, txt7), "1");

	string arr8[] = {"00000000001", "1"};
	const string* txt8 = &arr8[0];
	EXPECT_EQ(Sum(2, txt8), "2");
 }

TEST(Sum, SumOfNegativeNumbers) {
	string arr00[] {"-1", "-1", "-1", "-1"};
	const string* txt00 = &arr00[0];
	EXPECT_EQ(Sum(4, txt00), "-4");

	string arr01[] {"-9999", "-9999"};
	const string* txt01 = &arr01[0];
	EXPECT_EQ(Sum(2, txt01), "-19998");

	string arr02[] {"-00000000", "-0"};
	const string* txt02 = &arr02[0];
	EXPECT_EQ(Sum(2, txt02), "0");

	string arr03[] {"-0", "-0"};
	const string* txt03 = &arr03[0];
	EXPECT_EQ(Sum(2, txt03), "0");

	string arr04[] {"-0", "-0", "-15"};
	const string* txt04 = &arr04[0];
	EXPECT_EQ(Sum(3, txt04), "-15");

	EXPECT_EQ(Sum(2, "-999", "-0"), "-999");
	EXPECT_EQ(Sum(2, "-0", "-0"), "0");
}

TEST(Sum, SumOfPositiveAndNegativeNumbers) {
	EXPECT_EQ(Sum(2, "000", "-000123"), "-123");
	EXPECT_EQ(Sum(2, "-15", "10"), "-5");
	EXPECT_EQ(Sum(2, "-999", "0"), "-999");
	EXPECT_EQ(Sum(2, "-0", "+0"), "0");
	EXPECT_EQ(Sum(2, "-0", "0"), "0");
	EXPECT_EQ(Sum(2, "+0", "-0"), "0");
	EXPECT_EQ(Sum(2, "-0", "-0"), "0");
	EXPECT_EQ(Sum(2, "10", "-1"), "9");
	EXPECT_EQ(Sum(2, "-999", "1"), "-998");
	EXPECT_EQ(Sum(4, "-1", "1", "-1", "1"), "0");
	EXPECT_EQ(Sum(3, "-1", "1", "-1"), "-1");
	EXPECT_EQ(Sum(2, "-1234", "+1234"), "0");
	EXPECT_EQ(Sum(2, "-1234", "1234"), "0");
	EXPECT_EQ(Sum(2, "+001", "-0001112"), "-1111");
	EXPECT_EQ(Sum(2, "68", "-94"), "-26");
	EXPECT_EQ(Sum(2, "-68", "94"), "26");
	EXPECT_EQ(Sum(2, "94", "-68"), "26");
	EXPECT_EQ(Sum(2, "-94", "68"), "-26");
	EXPECT_EQ(Sum(2, "-94", "94"), "0");
	EXPECT_EQ(Sum(2, "94", "-94"), "0");
	EXPECT_EQ(Sum(3, "-68", "94", "-123"), "-97");
	string arr01[] = { "+0000000000000000", "-00000000000000000", "+3333333333333333", "-234121212123", "-5298592312354352", "+99657452352300005403405349", "-1423900000000000000000000000000000000000000000000000000000000000000000"};
    string arr00[] = { "321312222", "-4234320000000", "+0000000000000"};
    const string* txt00 = &arr00[0];
	EXPECT_EQ(Sum(3, txt00), "-4233998687778");
    const string* txt01 = &arr01[0];
	EXPECT_EQ(Sum(7, txt01), "-1423899999999999999999999999999999999999999900342547649665487696827793");

	EXPECT_EQ(Sum(2, "-7847168", "7204296"), "-642872");
	EXPECT_EQ(Sum(2, "-7847168", "7204296"), "-642872");
	EXPECT_EQ(Sum(2, "-07847168", "000000000000000007204296"), "-642872");
}

TEST(Sum, OverloadingFunction) {
	string arr4[] = {"123", "345", "999", "1000000", "1"};
	const string* txt4 = &arr4[0];
	EXPECT_EQ(Sum(5, txt4), "1001468");
	EXPECT_EQ(Sum(5, "123", "345", "999", "1000000", "1"), "1001468");
	string output1;
	Sum(&output1, 5, txt4);
	EXPECT_EQ(output1, "1001468");
	string output2;
	Sum(&output2, 5, "123", "345", "999", "1000000", "1");
	EXPECT_EQ(output2, "1001468");
	string output3;
	Sum(output3, 5, txt4);
	EXPECT_EQ(output3, "1001468");
	string output4;
	Sum(output4, 5, "123", "345", "999", "1000000", "1");
	EXPECT_EQ(output4, "1001468");
}

TEST(Mult, MultiplyingPositiveNumbers) {
	string arr0[] = {"123", "345", "1"};
	const string* txt0 = &arr0[0];
	EXPECT_EQ(Mult(3, txt0), "42435");

	EXPECT_EQ(Mult(2, "2137", "54"), "115398");
	EXPECT_EQ(Mult(2, "100", "1"), "100");
	EXPECT_EQ(Mult(2, "1", "100"), "100");
	EXPECT_EQ(Mult(2, "1", "1"), "1");
	EXPECT_EQ(Mult(2, "5", "5"), "25");
	EXPECT_EQ(Mult(2, "9", "9"), "81");
	EXPECT_EQ(Mult(2, "99", "99"), "9801");
	EXPECT_EQ(Mult(2, "9999", "9999"), "99980001");
	EXPECT_EQ(Mult(2, "9999", "999"), "9989001");
	EXPECT_EQ(Mult(2, "9999", "99"), "989901");
	EXPECT_EQ(Mult(2, "48", "62"), "2976");
	EXPECT_EQ(Mult(2, "-7847168", "7204296"), "-56533321033728");
	EXPECT_EQ(Mult(2, "-07847168", "7204296"), "-56533321033728");
	EXPECT_EQ(Mult(2, "-07847168", "000000000007204296"), "-56533321033728");
}

TEST(Mult, MultOfNegativeNumbers) {
	EXPECT_EQ(Mult(2, "000", "-000123"), "0");
	EXPECT_EQ(Mult(2, "-15", "10"), "-150");
	EXPECT_EQ(Mult(2, "-999", "0"), "0");
	EXPECT_EQ(Mult(2, "-0", "+0"), "0");
	EXPECT_EQ(Mult(2, "-0", "0"), "0");
	EXPECT_EQ(Mult(2, "-0", "-0"), "0");
	EXPECT_EQ(Mult(2, "+0", "-0"), "0");
	EXPECT_EQ(Mult(2, "-999", "1"), "-999");
	EXPECT_EQ(Mult(4, "-1", "1", "-1", "1"), "1");
	EXPECT_EQ(Mult(3, "-1", "1", "-1"), "1");
	EXPECT_EQ(Mult(3, "-1", "-1", "-1"), "-1");
	EXPECT_EQ(Mult(2, "-1234", "+1234"), "-1522756");
	EXPECT_EQ(Mult(2, "-1234", "1234"), "-1522756");
	EXPECT_EQ(Mult(2, "+001", "-0001112"), "-1112");
	EXPECT_EQ(Mult(2, "68", "-94"), "-6392");
	EXPECT_EQ(Mult(2, "-68", "94"), "-6392");
	EXPECT_EQ(Mult(2, "94", "-68"), "-6392");
	EXPECT_EQ(Mult(2, "-94", "68"), "-6392");
	EXPECT_EQ(Mult(2, "-94", "94"), "-8836");
	EXPECT_EQ(Mult(2, "94", "-94"), "-8836");
	EXPECT_EQ(Mult(3, "-68", "94", "-123"), "786216");
	EXPECT_EQ(Mult(2, "0", "-3333333"), "0");
	EXPECT_EQ(Mult(2, "0", "3333333"), "0");
}

TEST(Mult, OverloadingFunction) {
	string arr4[] = {"123", "345", "1"};
	const string* txt4 = &arr4[0];
	EXPECT_EQ(Mult(3, txt4), "42435");
	EXPECT_EQ(Mult(3, "123", "345", "1"), "42435");
	string output1;
	Mult(&output1, 3, txt4);
	EXPECT_EQ(output1, "42435");
	string output2;
	Mult(&output2, 3, "123", "345", "1");
	EXPECT_EQ(output2, "42435");
	string output3;
	Mult(output3, 3, txt4);
	EXPECT_EQ(output3, "42435");
	string output4;
	Mult(output4, 3, "123", "345", "1");
	EXPECT_EQ(output4, "42435");
}

TEST(Operations, Random) {
	string arr01[] = {"123", "345", "1"};
	const string* txt01 = &arr01[0];
	EXPECT_EQ(Operation(Sum, 3, txt01), "469");
}

TEST(Everything, LosoweTestyDajcieMiZieloneProsze) {

	string arr01[] = {"-1234", "+1234"};
	const string* txt01 = &arr01[0];
	EXPECT_EQ(Sum(2, arr01), "0");

	string arr02[] = {"-123", "+123"};
	const string* txt02 = &arr02[0];
	EXPECT_EQ(Sum(2, arr02), "0");

	string arr03[] = {"+123", "-123"};
	const string* txt03 = &arr03[0];
	EXPECT_EQ(Sum(2, arr03), "0");

	string arr04[] = {"1234", "-1233"};
	const string* txt04 = &arr04[0];
	EXPECT_EQ(Sum(2, arr04), "1");

	string arr05[] = {"0", "-1233"};
	const string* txt05 = &arr05[0];
	EXPECT_EQ(Sum(2, arr05), "-1233");

	string arr06[] = {"0", "0"};
	const string* txt06 = &arr06[0];
	EXPECT_EQ(Sum(2, arr06), "0");
	
	string arr07[] = {"00000", "00000"};
	const string* txt07 = &arr07[0];
	EXPECT_EQ(Sum(2, arr07), "0");
	
	EXPECT_EQ(Sum(2, "-1234", "+1234"), "0");
	EXPECT_EQ(Sum(2, "-123", "+123"), "0");
	EXPECT_EQ(Sum(2, "+123", "-123"), "0");
	EXPECT_EQ(Sum(2, "1234", "-1233"), "1");
	EXPECT_EQ(Sum(2, "-0002", "00000"), "-2");
	EXPECT_EQ(Sum(2, "00000", "-0002"), "-2");
	EXPECT_EQ(Mult(2, "-0002", "00000"), "0");
	EXPECT_EQ(Mult(2, "00000", "-0002"), "0");
	EXPECT_EQ(Mult(2, "00000", "0000"), "0");
	EXPECT_EQ(Mult(2, "00000", "00000"), "0");
	EXPECT_EQ(Sum(2, "00000", "00000"), "0");

	EXPECT_EQ(Sum(2, "0000000000000000000000001763153", "-00000000000005104102"), "-3340949");
	EXPECT_EQ(Mult(2, "0000000000000000000000001763153", "-00000000000005104102"), "-8999312753606");

	string arr08[] = {"-0", "1234"};
	const string* txt08 = &arr08[0];
	EXPECT_EQ(Sum(2, arr08), "1234");
	
	EXPECT_EQ(Sum(2, "100000000", "-1"), "99999999");
	EXPECT_EQ(Sum(2, "-0", "1234"), "1234");
	EXPECT_EQ(Sum(2, "0", "1234"), "1234");
	EXPECT_EQ(Sum(3, "-0", "1234", "-1233"), "1");
	EXPECT_EQ(Sum(3, "0", "1234", "-1233"), "1");
	EXPECT_EQ(Sum(3, "0000000", "1234", "-1233"), "1");
	EXPECT_EQ(Sum(3, "0000000", "1234", "-0001233"), "1");
	EXPECT_EQ(Sum(3, "0000000", "00001234", "-0001233"), "1");
	EXPECT_EQ(Sum(3, "-0000000", "00001234", "-0001233"), "1");
	EXPECT_EQ(Sum(3, "1234", "0", "-1233"), "1");
	EXPECT_EQ(Sum(3, "1234", "0", "-1233"), "1");
	EXPECT_EQ(Sum(3, "001234", "000", "-1233"), "1");
	EXPECT_EQ(Sum(3, "1234", "0", "-001233"), "1");
	EXPECT_EQ(Sum(3, "-1233", "1234", "0"), "1");
	EXPECT_EQ(Sum(3, "0", "0", "0"), "0");
	EXPECT_EQ(Sum(3, "00", "0", "000"), "0");
	EXPECT_EQ(Sum(3, "-0", "-0", "-0"), "0");
	EXPECT_EQ(Sum(3, "0", "-0", "0"), "0");
	EXPECT_EQ(Sum(3, "1", "1", "1"), "3");
	EXPECT_EQ(Sum(3, "1", "1", "-2"), "0");
	EXPECT_EQ(Sum(3, "0", "0", "1"), "1");
	EXPECT_EQ(Sum(3, "600017000939", "0", "60003400046005"), "60603417046944");
	EXPECT_EQ(Sum(3, "+600017000939", "+0", "60003400046005"), "60603417046944");
	EXPECT_EQ(Mult(3, "+600017000939", "+1", "60003400046005"), "36003060141746974728198695");
	EXPECT_EQ(Mult(3, "+00600017000939", "+01", "060003400046005"), "36003060141746974728198695");
	EXPECT_EQ(Mult(3, "+00600017000939", "+00", "060003400046005"), "0");
	EXPECT_EQ(Sum(3, "-0", "1", "0"), "1");
	EXPECT_EQ(Sum(3, "-0", "1", "-2"), "-1");
	EXPECT_EQ(Sum(3, "-0", "-1", "2"), "1");
	EXPECT_EQ(Sum(3, "-0", "-0", "02"), "2");
	EXPECT_EQ(Sum(3, "-0", "0", "02"), "2");
	EXPECT_EQ(Sum(3, "-0", "-0", "-0"), "0");
	EXPECT_EQ(Mult(3, "-0", "-0", "-0"), "0");
	EXPECT_EQ(Mult(4, "-0", "-0", "-0", "-0"), "0");
}

/*
int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
*/