#include "bitfield\polinom.h"
#include <gtest.h>
#include <locale>
#include <stdio.h>
TEST(Polinom, can_create_polinom_from_string_size_like_one_Monom_AND_makeit_back_to_string_and_they_the_same)
{

	string a = "+26.100000x^5y^4z^16";

	ASSERT_NO_FATAL_FAILURE(Polinom A(a));
	Polinom A(a);
	EXPECT_EQ(a, A.createstringfrompol());
}

TEST(Polinom, can_create_polinom_from_ANY_string_size_like_many_DIFFMonoms_AND_makeit_back_to_string_and_they_the_same)
{
	string a = "+26.1x^5y^4z^6-6.1x^5y^3z^6-226.1x^5y^5z^17";

	string b = "-226.100000x^5y^5z^17+26.100000x^5y^4z^6-6.100000x^5y^3z^6";
	
	
	Polinom A(a);
	EXPECT_EQ(b, A.createstringfrompol());
}

TEST(Polinom, polinom_can_push_Monom_by_string_according_hide_to_each_time)
{
	string a = "+26.1x^5y^4z^6-6.1x^5y^3z^6-226.13x^15y^14z^16";

	string b = "-226.130000x^15y^14z^16+26.100000x^5y^4z^6-6.100000x^5y^3z^6";


	Polinom A(a);
	EXPECT_EQ(b, A.createstringfrompol()); //=<>
	Polinom B(b);
	EXPECT_EQ(b, B.createstringfrompol());

	
}

TEST(Polinom, polinom_can_be_made_unique_when2todelete_also_as_deleting_last_two_monoms)
{
	string a = "+1x^5y^6z^7-4x^2y^2z^2+4x^2y^2z^2";

	string b = "+1.000000x^5y^6z^7";


	Polinom A(a);
	A.makeunique();
	EXPECT_EQ(b, A.createstringfrompol()); 
	
}

TEST(Polinom, polinom_can_be_made_unique_when2todelete_also_as_deleting_first_two_monoms)
{
	string a = "+1x^5y^6z^7-1x^5y^6z^7-4.7x^2y^2z^2";

	string b = "-4.700000x^2y^2z^2";


	Polinom A(a);
	A.makeunique();
	EXPECT_EQ(b, A.createstringfrompol());

}

TEST(Polinom, polinom_can_be_made_unique_when2todelete_also_as_deleting_two_monoms_indep_from_place)
{
	string a = "+1x^5y^6z^7+8x^5y^6z^9-1x^5y^6z^7-4x^2y^2z^2";

	string b = "+8.000000x^5y^6z^9-4.000000x^2y^2z^2";


	Polinom A(a);
	A.makeunique();
	EXPECT_EQ(b, A.createstringfrompol());

}
TEST(Polinom, polinom_can_be_made_unique_when2todelete_also_as_deleting__two_monoms_in_middle)
{
	string a = "+8x^5y^6z^9-1x^5y^6z^7+1x^5y^6z^7-1x^5y^6z^7-4x^2y^2z^2";

	string b = "+8.000000x^5y^6z^9-1.000000x^5y^6z^7-4.000000x^2y^2z^2";


	Polinom A(a);
	A.makeunique();
	EXPECT_EQ(b, A.createstringfrompol());

}

TEST(Polinom, polinom_can_be_made_unique_del_one_monom)
{
	string a = "+1x^5y^6z^7-4x^2y^2z^2+5x^2y^2z^2";

	string b = "+1.000000x^5y^6z^7+1.000000x^2y^2z^2";


	Polinom A(a);
	A.makeunique();
	EXPECT_EQ(b, A.createstringfrompol());

}

TEST(Polinom, polinoms_with_different_monoms_can_be_added)
{
	string a = "+1x^5y^6z^7+5x^2y^2z^2";

	string b = "-3x^14y^4z^5+54x^0y^7z^3";
	string c = "+1.000000x^5y^6z^7-3.000000x^14y^4z^5+54.000000x^0y^7z^3+5.000000x^2y^2z^2";

	Polinom A(a);
	Polinom B(b);
	Polinom C = A + B;
	EXPECT_EQ(c, C.createstringfrompol());

}

TEST(Polinom, polinoms_madeof_monoms_can_be_added)
{
	string a = "+5x^2y^2z^2";

	string b = "-3.123x^5y^4z^5";
	string c = "-3.123000x^5y^4z^5+5.000000x^2y^2z^2";

	Polinom A(a);
	Polinom B(b);
	Polinom C = A + B;
	EXPECT_EQ(c, C.createstringfrompol());

}

TEST(Polinom, polinoms_with_different_monoms_can_be_added_and_operation_add_overloaded)
{
	string a = "+1x^5y^6z^7+5x^2y^2z^2";
	string e = "+1x^6y^6z^7+5x^2y^2z^1";
	string b = "-3x^5y^4z^5+54x^0y^7z^3";
	string c = "+1.000000x^6y^6z^7+1.000000x^5y^6z^7-3.000000x^5y^4z^5+54.000000x^0y^7z^3+5.000000x^2y^2z^2+5.000000x^2y^2z^1";

	Polinom A(a);
	Polinom B(b);
	Polinom E(e);
	Polinom C = A + B+E;
	

	EXPECT_EQ(c, C.createstringfrompol());

}

TEST(Polinom, polinoms_with_equal_monoms_can_be_added_and_looks_like_pretty)
{
	string a = "+1x^5y^6z^7+5x^2y^2z^2";

	string b = "-3x^4y^4z^5+5x^2y^2z^2";
	string c = "+1.000000x^5y^6z^7-3.000000x^4y^4z^5+10.000000x^2y^2z^2";

	Polinom A(a);
	Polinom B(b);
	Polinom C = A + B;
	EXPECT_EQ(c, C.createstringfrompol());

}

TEST(Polinom, polinoms_with_opposite_monoms_can_be_added_and_looks_like_pretty)
{
	string a = "+1x^5y^6z^7+5x^2y^2z^2";

	string b = "-3x^5y^4z^5-5x^2y^2z^2";
	string c = "+1.000000x^5y^6z^7-3.000000x^5y^4z^5";

	Polinom A(a);
	Polinom B(b);
	Polinom C = A + B;
	EXPECT_EQ(c, C.createstringfrompol());

}

TEST(Polinom, polinoms_with_different_monoms_can_be_sub)
{
	string a = "+1x^5y^6z^7+5x^2y^2z^2";

	string b = "-3x^4y^4z^5+54x^0y^7z^3";
	string c = "+1.000000x^5y^6z^7+3.000000x^4y^4z^5-54.000000x^0y^7z^3+5.000000x^2y^2z^2";

	Polinom A(a);
	Polinom B(b);
	Polinom C = A - B;
	EXPECT_EQ(c, C.createstringfrompol());

}

TEST(Polinom, polinoms_madeof_monoms_can_be_sub)
{
	string a = "+5x^2y^2z^2";

	string b = "-3x^4y^4z^5";
	string c = "+3.000000x^4y^4z^5+5.000000x^2y^2z^2";

	Polinom A(a);
	Polinom B(b);
	Polinom C = A - B;
	EXPECT_EQ(c, C.createstringfrompol());

}

TEST(Polinom, polinoms_with_different_monoms_can_be_subbed_and_operation_sub_overloaded)
{
	string a = "+1x^5y^6z^7+5x^2y^2z^2";
	string e = "+1x^6y^6z^7+5x^2y^2z^1";
	string b = "-3x^15y^4z^5+54x^0y^7z^3";
	string c = "-1.000000x^6y^6z^7+1.000000x^5y^6z^7+3.000000x^15y^4z^5-54.000000x^0y^7z^3+5.000000x^2y^2z^2-5.000000x^2y^2z^1";

	Polinom A(a);
	Polinom B(b);
	Polinom E(e);
	Polinom C = A - B - E;


	EXPECT_EQ(c, C.createstringfrompol());

}

TEST(Polinom, polinoms_with_equal_monoms_can_be_subbed_and_looks_like_pretty)
{
	string a = "+1x^5y^6z^7-5x^2y^2z^2";

	string b = "-3x^4y^4z^5+5x^2y^2z^2";
	string c = "+1.000000x^5y^6z^7+3.000000x^4y^4z^5-10.000000x^2y^2z^2";

	Polinom A(a);
	Polinom B(b);
	Polinom C = A - B;
	EXPECT_EQ(c, C.createstringfrompol());

}

TEST(Polinom, polinoms_with_opposite_monoms_can_be_subbed_and_looks_like_pretty)
{
	string a = "+1x^5y^6z^7-5x^2y^2z^2";

	string b = "-3x^5y^4z^5-5x^2y^2z^2";
	string c = "+1.000000x^5y^6z^7+3.000000x^5y^4z^5";

	Polinom A(a);
	Polinom B(b);
	Polinom C = A - B;
	EXPECT_EQ(c, C.createstringfrompol());

}

TEST(Polinom, polinoms_with_deff_size_can_be_multiplied_with_repeats)
{
	string a = "+1x^5y^4z^5-5x^2y^2z^2+1x^3y^2z^1";
	string b = "-3x^4y^4z^5-5x^2y^2z^2";

	string c = "1";

	Polinom A(a);
	Polinom B(b);
	Polinom C = A * B;
	EXPECT_EQ("1", "1");

}

TEST(Polinom,polinoms_with_deff_size_can_be_multiplied_no_repeats)
{
	string a = "+1.1x^5y^6z^7-5x^2y^2z^2+1x^3y^2z^1";
	string b = "-3.12x^4y^4z^5-5x^2y^2z^2";

	string c = "-3.432000x^9y^10z^12-5.500000x^7y^8z^9+15.600000x^6y^6z^7-3.120000x^7y^6z^6+25.000000x^4y^4z^4-5.000000x^5y^4z^3";

	Polinom A(a);
	Polinom B(b);
	Polinom C = A * B;
	EXPECT_EQ(c, C.createstringfrompol());

}




