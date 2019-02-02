#include <gtest.h>
#include "tlist.h"

TEST(TList, can_create_list)
{
  ASSERT_NO_THROW(TList<int> list);
}

TEST(TList, can_create_right_copy_of_list)
{
  TList <int> list;
  list.PutStart(1);
  TList<int> list2(list);
  ASSERT_EQ(list.GetStart(), list2.GetStart());
}

TEST(TList, can_put_elem_into_list)
{
  TList <int> list;
  list.PutStart(4);
  list.PutStart(3);
  list.PutStart(2);
  list.Put(2, 1);

  ASSERT_EQ(list.Get(2), 1);
}

TEST(TList, can_put_elem_to_the_start_of_list)
{
  TList <int> list;
  ASSERT_NO_THROW(list.PutStart(1));
}

TEST(TList, can_put_elem_to_the_end_of_list)
{
  TList <int> list;
  ASSERT_NO_THROW(list.PutEnd(1));
}

TEST(TList, throw_when_put_elem_to_incorrent_index)
{
  TList<int> list;
  list.PutStart(1);
  list.PutStart(1);
  list.PutStart(1);
  ASSERT_ANY_THROW(list.Put(0, 1));
}

TEST(TList, throw_when_get_elem_when_list_is_empty)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.Get(1));
}

TEST(TList, can_get_elem_to_index)
{
  TList<int> list;
  list.PutStart(3);
  list.PutStart(2);
  list.PutStart(1);
  int res = list.Get(1);
  ASSERT_EQ(2, res);
}

TEST(TList, throw_when_get_elem_with_incorrent_index)
{
  TList<int> list;
  list.PutStart(1);
  list.PutStart(1);
  list.PutStart(1);
  ASSERT_ANY_THROW(list.Get(0));
}

TEST(TList, can_get_elem_from_the_start_of_list)
{
  TList<int> list;
  list.PutStart(2);
  list.PutStart(1);
  int res = list.GetStart();
  ASSERT_EQ(1, res);
}

TEST(TList, can_get_elem_from_the_end_of_list)
{
  TList<int> list;
  list.PutStart(2);
  list.PutStart(1);
  int res = list.GetEnd();
  ASSERT_EQ(2, res);
}

TEST(TList, throw_when_get_from_start_when_list_is_empty)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.GetStart());
}

TEST(TList, throw_when_get_from_end_when_list_is_empty)
{
  TList<int> list;
  ASSERT_ANY_THROW(list.GetEnd());
}

TEST(TList, can_use_isempty_correctly)
{
  TList<int> list;
  ASSERT_TRUE(list.IsEmpty());
}

TEST(TList, can_use_isempty_incorrectly)
{
  TList<int> list;
  list.PutStart(1);
  ASSERT_FALSE(list.IsEmpty());
}

TEST(TList, can_use_isfull_correctly)
{
  TList<int> list;
  list.PutStart(1);
  ASSERT_TRUE(list.IsFull());
}