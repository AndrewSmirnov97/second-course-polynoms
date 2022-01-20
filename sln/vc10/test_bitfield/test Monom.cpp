#include "bitfield\Monom.h"
#include <gtest.h>
#include <locale>
#include <stdio.h>
TEST(Monom, Monom_can_be_created_from_string_w_no_throw)
{

	string a = "+26x^4y^5z^7";
	ASSERT_NO_THROW(Monom A(a));
}
TEST(Monom, positive_sign_monom_created)
{
	string a = "+26x^4y^5z^6";
	Monom A(a);
	EXPECT_EQ(1, A.getsign());
}
TEST(Monom, neg_sign_monom_created)
{
	string a = "-26x^5y^5z^6";
	Monom A(a);
	EXPECT_EQ(-1, A.getsign());
}
//TEST(Momom, can_create_any_monom_from_string){
//	string sub;
//	sub = to_string(rand() % 1000);
//	string a;
//	sub = to_string(rand() % 1000);
//	if (rand() % 1000 < 500){
//		a = a + "+" + sub;
//	}
//	else
//		a = a + "-" + sub;
//	sub = to_string(rand() % 1000);
//	a = a + "x^" + sub;
//	sub = to_string(rand() % 1000);
//	a = a + "y^" + sub;
//	sub = to_string(rand() % 1000);
//	a = a + "z^" + sub;
//	EXPECT_NO_FATAL_FAILURE(Monom(a));
//	
//}

TEST(Monom, creates_needed_coefs_from_string)
{
	string a = "-26x^5y^4z^16";
	Monom A(a);
	EXPECT_EQ(-1, A.getsign());
	EXPECT_EQ(26, A.getcoef());
	EXPECT_EQ(5, A.getx());
	EXPECT_EQ(4, A.gety());
	EXPECT_EQ(16, A.getz());

}
TEST(Momom, can_correctly_create_hide_with_any_monom_from_string){
	string sub;
	sub = to_string(rand() % 19);
	string a;
	sub = to_string(rand() % 19);
	if (rand() % 19 < 10){
		a = a + "+" + sub;
	}
	else
		a = a + "-" + sub;
	int x = rand() % 19;
	sub = to_string(x);
	
	a = a + "x^" + sub;
	int y = rand() % 19;
	sub = to_string(y);
	a = a + "y^" + sub;
	int z = rand() % 19;
	sub = to_string(z);
	a = a + "z^" + sub;
	Monom A(a);
	EXPECT_EQ(x + y * 20 + z * 400, A.gethide());
	 a = "-1x^5y^14z^6";
	Monom B(a);
	EXPECT_EQ(5 + 14 * 20 + 6 * 400, B.gethide());
}

TEST(Momom, no_failure_when_copy_monoms){
	string sub;
	sub = to_string(rand() % 19);
	string a;
	sub = to_string(rand() % 19);
	if (rand() % 19 < 10){
		a = a + "+" + sub;
	}
	else
		a = a + "-" + sub;
	int x = rand() % 19;
	sub = to_string(x);

	a = a + "x^" + sub;
	int y = rand() % 19;
	sub = to_string(y);
	a = a + "y^" + sub;
	int z = rand() % 19;
	sub = to_string(z);
	a = a + "z^" + sub;
	Monom A(a);
	

	ASSERT_NO_FATAL_FAILURE(Monom B(A));

}
TEST(Momom, can_copy_Monoms_with_correct_coefs){
	string sub;
	sub = to_string(rand() % 19);
	string a;
	sub = to_string(rand() % 19);
	if (rand() % 19 < 10){
		a = a + "+" + sub;
	}
	else
		a = a + "-" + sub;
	int x = rand() % 19;
	sub = to_string(x);

	a = a + "x^" + sub;
	int y = rand() % 19;
	sub = to_string(y);
	a = a + "y^" + sub;
	int z = rand() % 19;
	sub = to_string(z);
	a = a + "z^" + sub;
	Monom A(a);
	Monom B(A);
	EXPECT_EQ(B.getsign(), A.getsign() );
	EXPECT_EQ(B.getcoef(), A.getcoef());
	EXPECT_EQ(B.getx(), A.getx());
	EXPECT_EQ(B.gety(), A.gety());
	EXPECT_EQ(B.getz(), A.getz());
	
}



TEST(Momom, operator_multiply_dont_change_its_operands){
	string sub;
	sub = to_string(rand() % 9);
	string a;
	sub = to_string(rand() % 9);
	if (rand() % 9 < 5){
		a = a + "+" + sub;
	}
	else
		a = a + "-" + sub;
	sub = to_string(rand() % 9);
	a = a + "x^" + sub;
	sub = to_string(rand() % 9);
	a = a + "y^" + sub;
	sub = to_string(rand() % 9);
	a = a + "z^" + sub;
	Monom A(a);
	Monom B(a);
	Monom copyA(A);
	Monom copyB(B);
	Monom C=A*B;
	EXPECT_EQ(copyA, A);
	EXPECT_EQ(copyB, B);

}

TEST(Momom, operator_multiply_multiplies_correctly){
	string a = "-26x^5y^4z^6";
	string b = "-6x^6y^12z^0";
	Monom A(a);
	Monom B(b);
	
	Monom C = A*B;
	
	EXPECT_EQ(1, C.getsign());
	EXPECT_EQ(156, C.getcoef());
	EXPECT_EQ(11, C.getx());
	EXPECT_EQ(16, C.gety());
	EXPECT_EQ(6, C.getz());
}
TEST(Momom, operator_multiply_refreshes_hide){
	string a = "-26x^4y^4z^6";
	string b = "-6x^5y^4z^0";
	Monom A(a);
	Monom B(b);

	Monom C = A*B;

	EXPECT_EQ(4+4*20+6*400+5+4*20+0*400, C.gethide());
	
}
