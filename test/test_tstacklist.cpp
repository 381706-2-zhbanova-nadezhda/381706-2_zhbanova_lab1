#include "tstacklist.h"

#include <gtest.h>

TEST(TStackList, can_create_stacklist)
{
  ASSERT_NO_THROW(TStackList<int> s1);
}

TEST(TStackList, new_stacklist_is_empty)
{
  TStackList<int> s1(3);
  EXPECT_EQ(true, s1.IsEmpty());
}

TEST(TStackList, can_create_stacklist_with_positive_size)
{
  ASSERT_NO_THROW(TStackList<int> s1(5));
}

TEST(TStackList, throw_when_create_stacklist_with_negative_size)
{
  ASSERT_ANY_THROW(TStackList<int> s1(-5));
}

TEST(TStackList, can_create_copied_stacklist)
{
  TStackList<int> s1(5);
  ASSERT_NO_THROW(TStackList<int> s2(s1));
}

TEST(TStackList, can_get_max_size)
{
  TStackList<int> s1(10);
  ASSERT_EQ(s1.GetMaxSize(), 10);
}

TEST(TStackList, can_put_elem_in_stacklist)
{
  TStackList<int> s1(3);
  ASSERT_NO_THROW(s1.Put(1));
}

TEST(TStackList, stacklist_with_elem_isnt_empty)
{
  TStackList<int> s1(3);
  s1.Put(1);
  ASSERT_FALSE(s1.IsEmpty());
}

TEST(TStackList, cant_put_in_full_stacklist)
{
  TStackList<int> s1(1);
  s1.Put(1);
  ASSERT_ANY_THROW(s1.Put(3));
}

TEST(TStackList, can_get_elem_from_stacklist)
{
  TStackList<int> s1;
  s1.Put(1);
  int res = s1.Get();
  EXPECT_EQ(1, res);
}

TEST(TStackList, cant_get_from_empty_stacklist)
{
  TStackList<int> s1(3);
  ASSERT_ANY_THROW(s1.Get());
}

TEST(TStackList, get_returns_last_put_elem)
{
  TStackList<int> s1(3);
  int elem1 = 1, elem2 = 2, res;
  s1.Put(elem1); s1.Put(elem2);
  res = s1.Get();
  EXPECT_TRUE((res = elem2) && (res != elem1));
}

TEST(TStackList, not_empty_assignment)
{
  TStackList<int> s1(10);
  TStackList<int> s2(10);
  s1.Put(10);
  s1.Put(20);
  s1.Put(40);
  s2 = s1;
  EXPECT_EQ(40, s2.Get());
  EXPECT_EQ(s2.Get(), 20);
  EXPECT_EQ(s2.Get(), 10);
}

TEST(TStackList, can_use_isempty_correctly)
{
  TStackList<int> s1(3);
  ASSERT_TRUE(s1.IsEmpty());
}

TEST(TStackList, can_use_isempty_incorrectly)
{
  TStackList<int> s1(2);
  s1.Put(1);
  ASSERT_FALSE(s1.IsEmpty());
}

TEST(TStackList, can_use_isfull_correctly)
{
  TStackList<int> s1(1);
  s1.Put(10);
  ASSERT_TRUE(s1.IsFull());
}

TEST(TStackList, can_use_isfull_incorrectly)
{
  TStackList<int> s1(5);
  ASSERT_FALSE(s1.IsFull());
}

TEST(TStackList, can_get_size)
{
  TStackList<int> S(5);
  S.Put(1);
  S.Put(2);
  ASSERT_EQ(S.GetSize(), 2);
}