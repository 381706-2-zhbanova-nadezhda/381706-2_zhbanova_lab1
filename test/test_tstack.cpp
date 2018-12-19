#include "tstack.h"

#include <gtest.h>

TEST(TStack, can_create_stack)
{
    ASSERT_NO_THROW(TStack<int> s1);
}

//TEST(TStack, can_create_stack_with_set_size)
//{
//    ASSERT_NO_THROW(TStack s1(5));
//}
//
//TEST(TStack, new_stack_is_empty)
//{
//    TStack s1;
//    EXPECT_EQ(true, s1.IsEmpty());
//}
//
//TEST(TStack, can_push_elem_in_stack)
//{
//    TStack s1;
//    int elem = 1;
//    ASSERT_NO_THROW(s1.Push(elem));
//}
//
//TEST(TStack, stack_with_elem_isnt_empty)
//{
//    TStack s1;
//    int elem = 1;
//    s1.Push(elem);
//    EXPECT_EQ(false, s1.IsEmpty());
//}
//
//TEST(TStack, cant_push_in_full_stack)
//{
//    TStack s1;
//    int i;
//    for (i = 0; i < DefMemSize; i++)
//        s1.Push(i);
//    s1.Push(i + 1);
//    EXPECT_EQ(DataFull, s1.GetRetCode());
//}
//
//
//TEST(TStack, can_pop_elem_from_stack)
//{
//    TStack s1;
//    int elem1 = 1, elem2;
//    s1.Push(elem1);
//    elem2 = s1.Get();
//    EXPECT_EQ(elem1, elem2);
//}
//
//TEST(TStack, cant_pop_from_empty_stack)
//{
//    TStack s1;
//    s1.Get();
//    EXPECT_EQ(DataEmpty, s1.GetRetCode());
//}
//
//TEST(TStack, pop_returns_last_pushed_elem)
//{
//    TStack s1;
//    int elem1 = 1, elem2 = 2, res;
//    s1.Push(elem1); s1.Push(elem2);
//    res = s1.Get();
//    EXPECT_TRUE((res = elem2) && (res != elem1));
//}
//
//TEST(TStack, full_stack_after_pop_isnt_full)
//{
//    TStack s1;
//    int i;
//    for (i = 0; i < DefMemSize; i++)
//        s1.Push(i);
//    bool isf = s1.IsFull();
//    int val = s1.Get();
//    EXPECT_TRUE(isf != s1.IsFull());
//}