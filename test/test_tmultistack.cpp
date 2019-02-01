#include "tmultistack.h"

#include <gtest.h>

TEST(TMStack, cant_create_multistack_with_negative_length)
{
  ASSERT_ANY_THROW(TMStack<int> m1(3, -1));
}

TEST(TMStack, can_create_multistack_with_positive_length)
{
  ASSERT_NO_THROW(TMStack<int> m1(3, 12));
}

TEST(TMStack, new_multistack_is_empty)
{
  TMStack<int> m1(3, 12);
  EXPECT_EQ(true, m1.IsEmpty(1));
}

TEST(TMStack, multistack_with_element_is_not_empty)
{
  TMStack<int> m1(3, 12);
  m1.Set(1, 5);
  EXPECT_EQ(false, m1.IsEmpty(1));
}

TEST(TMStack, can_copy_multistack)
{
  TMStack<int> m1(3, 12);
  ASSERT_NO_THROW(TMStack<int> m2(m1));
}

TEST(TMStack, can_set_element_in_empty_stack)
{
  TMStack<int> m1(3, 12);
  ASSERT_NO_THROW(m1.Set(1, 2));
}

TEST(TMStack, can_set_element_in_not_full_stack)
{
  TMStack<int> m1(2, 4);
  m1.Set(0, 12);
  m1.Set(0, 12);
  m1.Set(0, 12);
  EXPECT_NO_THROW(m1.Set(0, 12));
}

TEST(TMStack, cant_set_element_in_full_multistack)
{
  TMStack<int> m1(2, 5);
  m1.Set(1, 12);
  m1.Set(1, 12);
  m1.Set(1, 12);
  m1.Set(1, 12);
  m1.Set(1, 12);
  EXPECT_ANY_THROW(m1.Set(1, 12));
}

TEST(TMStack, can_get_element)
{
  TMStack<int> m1(5, 15);
  m1.Set(2, 12);
  EXPECT_EQ(12, m1.Get(2));
}

TEST(TMStack, cant_get_element_from_empty_multistack)
{
  TMStack<int> m1(2, 5);
  EXPECT_ANY_THROW(m1.Get(1));
}

TEST(TMStack, correct_order_return_value)
{
  TMStack <int> m1(2, 5);
  m1.Set(1, 1);
  m1.Set(1, 2);
  m1.Set(1, 3);
  ASSERT_EQ(3, m1.Get(1));
  ASSERT_EQ(2, m1.Get(1));
  ASSERT_EQ(1, m1.Get(1));
}

TEST(TMStack, can_use_isfull_correctly)
{
  TMStack<int> m1(5, 25);
  m1.Set(1, 12);
  m1.Set(1, 12);
  m1.Set(1, 12);
  m1.Set(1, 12);
  m1.Set(1, 12);
  EXPECT_EQ(true, m1.IsFull(1));
}