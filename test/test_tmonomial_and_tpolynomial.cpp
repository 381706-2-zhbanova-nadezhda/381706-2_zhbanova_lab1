#include "tpolynomial.h"

#include <gtest.h>

TEST(TMonomial, can_create_default_monomial)
{
  ASSERT_NO_THROW(TMonomial A);
}

TEST(TMonomial, can_create_monomial_wiht_custom_size)
{
  ASSERT_NO_THROW(TMonomial A(3));
}

TEST(TMonomial, throws_when_create_monomial_with_negative_size)
{
  ASSERT_ANY_THROW(TMonomial A(-3));
}

TEST(TMonomial, throws_when_create_monom_with_negative_power)
{
  int a[3] = { 1,-2,3 };
  ASSERT_ANY_THROW(TMonomial A(3, a, 1));
}

TEST(TMonomial, can_create_monomial_with_parameters)
{
	int a[3] = { 1,2,3 };
	ASSERT_NO_THROW(TMonomial A(3, a, 3.34));
}

TEST(TMonomial, can_create_copy_of_the_monomial)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3, a, 3.34);
	TMonomial B(A);
	ASSERT_EQ(B.GetCoeff(), A.GetCoeff());
	ASSERT_EQ(B.GetN(), A.GetN());
	ASSERT_EQ(B.GetNext(), A.GetNext());
	int * power = B.GetPower();
	for (int i = 0; i < 3; i++){
		ASSERT_EQ(power[i], a[i]);
	}
}

TEST(TMonomial, can_set_next)
{
  TMonomial A(2);
  TMonomial B(3);
  ASSERT_NO_THROW(A.SetNext(&B));
  ASSERT_EQ(A.GetNext(), &B);
}

TEST(TMonomial, can_set_and_get_coeff)
{
  TMonomial A;
  ASSERT_NO_THROW(A.SetCoeff(3.14));
  ASSERT_EQ(3.14, A.GetCoeff());
}

TEST(TMonomial, can_set_and_get_power)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3);
	ASSERT_NO_THROW(A.SetPower(a));
	ASSERT_EQ(1, A.GetPower()[0]);
	ASSERT_EQ(2, A.GetPower()[1]);
	ASSERT_EQ(3, A.GetPower()[2]);
}

TEST(TMonomial, can_set_and_get_size)
{
	TMonomial A(3);
	ASSERT_NO_THROW(A.SetN(5));
	printf("%d\n", A.GetN());
	ASSERT_EQ(5, A.GetN());
}

TEST(TMonomial, can_assign_monomials)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3, a, 3.12);
	TMonomial B(6);
	B = A;
	ASSERT_EQ(B.GetCoeff(), A.GetCoeff());
	ASSERT_EQ(B.GetN(), A.GetN());
	ASSERT_EQ(B.GetNext(), A.GetNext());
	int * power = B.GetPower();
	for (int i = 0; i < 3; i++){
		ASSERT_EQ(power[i], a[i]);
	}
}

TEST(TMonomial, can_add_monomials_with_equal_size)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3, a, 3.1);
	TMonomial B(3, a, 0.5);
	ASSERT_NO_THROW(A + B);
	TMonomial C(3);
	C = A + B;
	ASSERT_EQ(3.6, C.GetCoeff());
}

TEST(TMonomial, trows_when_add_monomials_with_different_size_and_powers)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3);
	TMonomial B(3);
	TMonomial C(4);
	A.SetPower(a);
	ASSERT_ANY_THROW(A + B);
	ASSERT_ANY_THROW(A + C);
}

TEST(TMonomial, can_subtract_monomials_with_equal_size)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3, a, 3.1);
	TMonomial B(3, a, 0.5);
	ASSERT_NO_THROW(A - B);
	TMonomial C(3);
	C = A - B;
	ASSERT_EQ(2.6, C.GetCoeff());
}

TEST(TMonomial, trows_when_subtract_monomials_with_different_size_and_power)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3);
	TMonomial B(3);
	TMonomial C(4);
	A.SetPower(a);
	ASSERT_ANY_THROW(A - B);
	ASSERT_ANY_THROW(A - C);
}

TEST(TMonomial, can_multiply_monomials_with_equal_size)
{
	int a[3] = { 1,2,3 };
	int a2[3] = { 3,2,1 };
	TMonomial A(3, a, 3.1);
	TMonomial B(3, a2, 0.5);
	ASSERT_NO_THROW(A * B);
	TMonomial C(3);
	C = A * B;
	ASSERT_EQ(3.1*0.5, C.GetCoeff());
	for (int i =0; i < 3; i++)
		ASSERT_EQ(C.GetPower()[i], 4);
}

TEST(TMonomial, trows_when_multiply_monomials_with_different_size)
{
	int a[3];
	for (int i = 0; i < 3; i++)
		a[i] = i + 1;
	TMonomial A(3);
	TMonomial C(4);
	A.SetPower(a);
	ASSERT_ANY_THROW(A * C);
}

TEST(TMonomial, can_equivalence_equal_monomials)
{
	int a[3] = { 1,2,3 };
	TMonomial A(3, a, 3.1); 
	TMonomial B(3, a, 3.1);

	ASSERT_TRUE(A == B);
}

TEST(TMonomial, trows_when_equivalence_monomials_with_different_size)
{
	TMonomial A(3);
	TMonomial B(4);
	ASSERT_ANY_THROW(A == B);
}

TEST(TMonomial, equivalence_different_monomials_with_equal_size)
{
	int a[3] = { 1,2,3 };
	int b[3] = { 1,3,2 };
	TMonomial A(3);
	TMonomial B(3);
	A.SetPower(a);
	B.SetPower(b);
	ASSERT_EQ(false, A == B);
	B.SetPower(a);
	A.SetCoeff(3.1);
	B.SetCoeff(3.4);
	ASSERT_EQ(false, A == B);
}

TEST(TMonomial, can_compare_monomials_with_equal_size)
{
	int a[3] = { 1,2,3 };
	int b[3] = { 1,3,2 };
	TMonomial A(3,a,1);
	TMonomial B(3,b,1);
	ASSERT_EQ(false, A > B);
	ASSERT_EQ(true, A < B);
}

TEST(TMonomial, trows_when_compare_monomials_with_different_size)
{
	TMonomial A(3);
	TMonomial B(4);
	ASSERT_ANY_THROW(A > B);
	ASSERT_ANY_THROW(A < B);
}

TEST(TPolynomial, can_create_polynomial)
{
  ASSERT_NO_THROW(TPolynomial A);
}

TEST(TPolynomial, can_create_polynomial_with_positive_n)
{
  ASSERT_NO_THROW(TPolynomial A(3));
}

TEST(TPolynomial, throws_when_create_polynomial_with_negative_n)
{
  ASSERT_ANY_THROW(TPolynomial A(-3));
}