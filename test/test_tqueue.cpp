#include "tqueue.h"

#include <gtest.h>

TEST(TQueue, can_create_queue)
{
  ASSERT_NO_THROW(TQueue<int> s1);
}

TEST(TQueue, new_queue_is_empty)
{
  TQueue<int> s1(3);
  EXPECT_EQ(true, s1.IsEmpty());
}

TEST(TQueue, can_create_queue_with_positive_size)
{
  ASSERT_NO_THROW(TQueue<int> s1(5));
}

TEST(TQueue, throw_when_create_queue_with_negative_size)
{
  ASSERT_ANY_THROW(TQueue<int> s1(-5));
}

TEST(TQueue, can_create_copied_queue)
{
  TQueue<int> s1(5);
  ASSERT_NO_THROW(TQueue<int> s2(s1));
}

TEST(TQueue, can_put_elem_in_queue)
{
  TQueue<int> s1(3);
  ASSERT_NO_THROW(s1.Put(1));
}

TEST(TQueue, queue_with_elem_isnt_empty)
{
  TQueue<int> s1(3);
  s1.Put(1);
  EXPECT_EQ(false, s1.IsEmpty());
}

TEST(TQueue, cant_put_in_full_queue)
{
  TQueue<int> s1(3);
  for ( int i = 0; i < 3; i++ )
  {
    s1.Put(i);
  }
  ASSERT_ANY_THROW(s1.Put(3));
}

TEST(TQueue, can_get_elem_from_queue)
{
  TQueue<int> s1(1);
  s1.Put(1);
  int res = s1.Get();
  EXPECT_EQ(1, res);
}

TEST(TQueue, cant_get_from_empty_queue)
{
  TQueue<int> s1(3);
  ASSERT_ANY_THROW(s1.Get());
}

TEST(TQueue, get_returns_first_put_elem)
{
  TQueue<int> s1(3);
  int elem1 = 1, elem2 = 2, res;
  s1.Put(elem1); s1.Put(elem2);
  res = s1.Get();
  EXPECT_TRUE((res = elem1) && (res != elem2));
}

TEST(TQueue, not_empty_assignment)
{
  TQueue<int> s1(10);
  TQueue<int> s2(10);
  s1.Put(10);
  s1.Put(20);
  s1.Put(40);
  s2 = s1;
  EXPECT_EQ(s2.Get(), 10);
  EXPECT_EQ(s2.Get(), 20);
  EXPECT_EQ(s2.Get(), 40);
}

TEST(TQueue, can_use_isempty_correctly)
{
  TQueue<int> s1(5);
  ASSERT_TRUE(s1.IsEmpty());
}

TEST(TQueue, can_use_isempty_incorrectly)
{
  TQueue<int> s1(2);
  s1.Put(1);
  ASSERT_FALSE(s1.IsEmpty());
}

TEST(TQueue, can_use_isfull_correctly)
{
  TQueue<int> s1(1);
  s1.Put(10);
  ASSERT_TRUE(s1.IsFull());
}

TEST(TQueue, can_use_isfull_incorrectly)
{
  TQueue<int> s1(5);
  ASSERT_FALSE(s1.IsFull());
}

TEST(TQueue, compare_equal_queues_return_true)
{
  TQueue<int> s1(2), s2(2);
  s1.Put(10);
  s1.Put(20);
  s2 = s1;
  EXPECT_TRUE(s2==s1);
}

TEST(TQueue, compare_queue_with_itself_return_true)
{
  TQueue<int> s1(5);
  EXPECT_TRUE(s1==s1);
}

TEST(TQueue, queues_with_different_size_are_not_equal)
{
  TQueue<int> s1(5), s2(4);
  EXPECT_FALSE(s1==s2);
}

TEST(TQueue, compare_non_equal_queues_return_false)
{
  TQueue<int> s1(2), s2(2);
  s1.Put(10);
  s1.Put(10);
  s2.Put(10);
  s2.Put(20);
  EXPECT_FALSE(s1==s2);
}