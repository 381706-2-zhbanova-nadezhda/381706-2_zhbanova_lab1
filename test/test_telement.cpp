#include <gtest.h>
#include "telement.h"


TEST(TElement, can_create_element)
{
  ASSERT_NO_THROW(TElement<int> element);
}

TEST(TElement, can_copy_element)
{
  TElement<int> element(2,0);
  TElement<int> element2(element);
  ASSERT_EQ(element.GetElem(), element2.GetElem());
}

TEST(TElement, can_get_element)
{
  TElement<int> element(5, 0);
  int res = element.GetElem();
  ASSERT_EQ(5, res);
}

TEST(TElement, can_get_next)
{
    TElement<int>* elem = 0;
  TElement<int> element(5, elem);
  ASSERT_EQ(element.GetNext(), elem);
}

TEST(TElement, can_create_elem_default)
{
  TElement<int> elem;
  ASSERT_EQ(elem.GetElem(), 0);
}

TEST(TElement, can_set_next)
{
  TElement<int>* li = 0;
  TElement<int> elem;
  elem.SetNext(li);
  ASSERT_EQ(elem.GetNext(), li);
}