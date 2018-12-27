#include "tstack.h"

#include <gtest.h>

TEST(TStack, can_create_stack)
{
  ASSERT_NO_THROW(TStack<int> s1);
}

TEST(TStack, new_stack_is_empty)
{
  TStack<int> s1(3);
  EXPECT_EQ(true, s1.IsEmpty());
}

TEST(TStack, can_create_stack_with_positive_size)
{
  ASSERT_NO_THROW(TStack<int> s1(5));
}

TEST(TStack, throw_when_create_stack_with_negative_size)
{
  ASSERT_ANY_THROW(TStack<int> s1(-5));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> s1(5);
  ASSERT_NO_THROW(TStack<int> s2(s1));
}

TEST(TStack, can_put_elem_in_stack)
{
  TStack<int> s1(3);
  ASSERT_NO_THROW(s1.Put(1));
}

TEST(TStack, stack_with_elem_isnt_empty)
{
  TStack<int> s1(3);
  s1.Put(1);
  EXPECT_FALSE(s1.IsEmpty());
}

TEST(TStack, cant_put_in_full_stack)
{
  TStack<int> s1(3);
  for ( int i = 0; i < 3; i++ )
  {
    s1.Put(i);
  }
  ASSERT_ANY_THROW(s1.Put(3));
}

TEST(TStack, can_get_elem_from_stack)
{
  TStack<int> s1(1);
  s1.Put(1);
  int res = s1.Get();
  EXPECT_EQ(1, res);
}

TEST(TStack, cant_get_from_empty_stack)
{
  TStack<int> s1(3);
  ASSERT_ANY_THROW(s1.Get());
}

TEST(TStack, get_returns_last_put_elem)
{
  TStack<int> s1(3);
  int elem1 = 1, elem2 = 2, res;
  s1.Put(elem1); s1.Put(elem2);
  res = s1.Get();
  EXPECT_TRUE((res = elem2) && (res != elem1));
}

TEST(TStack, not_empty_assignment)
{
  TStack<int> s1(10);
  TStack<int> s2(10);
  s1.Put(10);
  s1.Put(20);
  s1.Put(40);
  s2 = s1;
  EXPECT_EQ(40, s2.Get());
  EXPECT_EQ(s2.Get(), 20);
  EXPECT_EQ(s2.Get(), 10);
}

TEST(TStack, can_use_isempty_correctly)
{
  TStack<int> s1(5);
  ASSERT_TRUE(s1.IsEmpty());
}

TEST(TStack, can_use_isempty_incorrectly)
{
  TStack<int> s1(2);
  s1.Put(1);
  ASSERT_FALSE(s1.IsEmpty());
}

TEST(TStack, can_use_isfull_correctly)
{
  TStack<int> s1(1);
  s1.Put(10);
  ASSERT_TRUE(s1.IsFull());
}

TEST(TStack, can_use_isfull_incorrectly)
{
  TStack<int> s1(5);
  ASSERT_FALSE(s1.IsFull());
}

TEST(TStack, compare_equal_stacks_return_true)
{
  TStack<int> s1(2), s2(2);
  s1.Put(10);
  s1.Put(20);
  s2 = s1;
  EXPECT_TRUE(s2==s1);
}

TEST(TStack, compare_stack_with_itself_return_true)
{
  TStack<int> s1(5);
  EXPECT_TRUE(s1==s1);
}

TEST(TStack, stacks_with_different_size_are_not_equal)
{
  TStack<int> s1(5), s2(4);
  EXPECT_FALSE(s1==s2);
}

TEST(TStack, compare_non_equal_stacks_return_false)
{
  TStack<int> s1(2), s2(2);
  s1.Put(10);
  s1.Put(10);
  s2.Put(10);
  s2.Put(20);
  EXPECT_FALSE(s1==s2);
}