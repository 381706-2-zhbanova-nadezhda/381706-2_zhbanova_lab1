#include <gtest.h>
#include "tarrlist.h"


TEST(TArrList, can_create_arrlist)
{
  ASSERT_NO_THROW(TArrList <int> list);
}

TEST(TArrList, can_create_list_with_positive_size)
{
  ASSERT_NO_THROW(TArrList <int> list(5));
}

TEST(TArrList, throw_when_create_arrlist_with_negative_size)
{
  ASSERT_ANY_THROW(TArrList <int> list(-5));
}

TEST(TArrList, throw_when_create_arrlist_with_size_eq_zero)
{
  ASSERT_ANY_THROW(TArrList <int> list(0));
}

TEST(TArrList, can_put_elem_to_the_start_of_arrlist)
{
  TArrList <int> list(5);
  ASSERT_NO_THROW(list.PutStart(1));
}

TEST(TArrList, can_put_elem_to_the_end_of_arrlist)
{
  TArrList <int> list(5);
  ASSERT_NO_THROW(list.PutEnd(1));
}

TEST(TArrList, can_put_elem_into_arrlist)
{
  TArrList <int> list(5);
  list.PutStart(4);
  list.PutStart(3);
  list.PutStart(2);
  list.Put(2, 1);

  ASSERT_EQ(list.Get(2), 1);
}

TEST(TArrList, arrlist_with_elem_isnt_empty)
{
  TArrList <int> list(5);
  list.PutStart(1);
  ASSERT_FALSE(list.IsEmpty());
}

TEST(TArrList, cant_put_to_the_start_into_full_arrlist)
{
  TArrList <int> list(5);
  for ( int i = 0; i < 5; i++ )
  {
    list.PutStart(1);
  }
  ASSERT_ANY_THROW(list.PutStart(1));
}

TEST(TArrList, cant_put_to_the_end_into_full_arrlist)
{
  TArrList <int> list(5);
  for ( int i = 0; i < 5; i++ )
  {
    list.PutStart(1);
  }
  ASSERT_ANY_THROW(list.PutEnd(1));
}

TEST(TArrList, cant_put_into_full_list)
{
  TArrList <int> list(5);
  for ( int i = 0; i < 5; i++ )
  {
    list.PutStart(1);
  }
  ASSERT_ANY_THROW(list.Put(1, 6));
}

TEST(TArrList, can_get_elem_from_the_start_of_arrlist)
{
  TArrList <int> list(5);
  list.PutStart(2);
  list.PutStart(1);
  int res = list.GetStart();
  EXPECT_EQ(1, res);
}

TEST(TArrList, can_get_elem_from_the_end_of_arrlist)
{
  TArrList <int> list(5);
  list.PutStart(2);
  list.PutStart(1);
  int res = list.GetEnd();
  EXPECT_EQ(2, res);
}

TEST(TArrList, can_get_elem_from_arrlist)
{
  TArrList <int> list(5);
  for ( int i = 1; i < 5; i++ )
  {
    list.PutEnd(i);
  }
  ASSERT_EQ(list.Get(1), 2);
}

TEST(TArrList, throw_when_get_last_element_from_empty_arrlist)
{
  TArrList <int> list(5);
  ASSERT_ANY_THROW(list.GetEnd());
}

TEST(TArrList, throw_when_get_start_element_from_empty_arrlist)
{
  TArrList <int> list(5);
  ASSERT_ANY_THROW(list.GetStart());
}

TEST(TArrList, throws_when_get_elem_from_empty_arrlist)
{
  TArrList <int> list(5);
  ASSERT_ANY_THROW(list.Get(1));
}

TEST(TArrList, can_create_right_copy_arrlist)
{
  TArrList <int> list1(5);
  list1.PutStart(1);
  TArrList <int> list2(list1);
  ASSERT_EQ(list1.GetStart(), list2.GetStart());
}

TEST(TArrList, can_use_isempty_correctly)
{
  TArrList <int> list(5);
  ASSERT_TRUE(list.IsEmpty());
}

TEST(TArrList, can_use_isempty_incorrectly)
{
  TArrList <int> list(5);
  list.PutStart(1);
  ASSERT_FALSE(list.IsEmpty());
}

TEST(TArrList, can_use_isfull_correctly)
{
  TArrList <int> list(1);
  list.PutStart(1);
  ASSERT_TRUE(list.IsFull());
}

TEST(TArrList, can_use_isfull_incorrectly)
{
  TArrList <int> list(5);
  ASSERT_FALSE(list.IsFull());
}

TEST(TArrList, throw_when_put_with_incurrent_index)
{
  TArrList <int> list(5);
  ASSERT_ANY_THROW(list.Put(10, 6));
}

TEST(TArrList, throw_when_get_with_incurrent_index)
{
  TArrList <int> list(5);
  list.PutStart(1);
  list.PutStart(1);
  ASSERT_ANY_THROW(list.Get(10));
}