#include "ttabletree.h"

#include <gtest.h>

//TESTS FOR CLASS TString

TEST(TString, can_create_string_without_symbols)
{
  ASSERT_NO_THROW(TString string);
}

TEST(TString, can_create_string_with_symbols)
{
  ASSERT_NO_THROW(TString string("Program"));
}

TEST(TString, can_create_copy_of_string)
{
  TString string("Program");
  TString string2(string);
  EXPECT_EQ(string.GetMemory()[0], 'P');
  EXPECT_EQ(string.GetMemory()[6], 'm');
}

TEST(TString, can_get_count)
{
  TString string("Program");
  EXPECT_EQ(string.GetCount(), 7);
}

TEST(TString, can_get_memory)
{
  TString string("Program");
  ASSERT_NO_THROW(string.GetMemory());
  EXPECT_EQ(string.GetMemory()[0], 'P');
  EXPECT_EQ(string.GetMemory()[6], 'm');
}

TEST(TString, can_use_assign_operator)
{
  TString string("Program");
  TString string2;
  string2 = string;
  EXPECT_EQ(string.GetMemory()[0], 'P');
  EXPECT_EQ(string.GetMemory()[6], 'm');
}

TEST(TString, can_compare_strings_part1)
{
  TString string("One");
  TString string2("Two");
  TString string3("One");
  EXPECT_TRUE(string == string3);
  EXPECT_TRUE(string2 != string3);
  EXPECT_FALSE(string == string2);
  EXPECT_FALSE(string != string3);
}

TEST(TString, can_compare_strings_part2)
{
  TString string("AAA");
  TString string2("AAAAAAA");
  EXPECT_TRUE(string < string2);
  EXPECT_FALSE(string > string2);
  EXPECT_TRUE(string2 > string);
  EXPECT_FALSE(string2 < string);
}

TEST(TString, throw_when_use_wrong_index_of_element)
{
  TString string("Program");
  ASSERT_ANY_THROW(string[-1]);
  ASSERT_ANY_THROW(string[10]);
}

TEST(TString, can_return_element)
{
  TString string("Program");
  EXPECT_EQ(string[0], 'P');
  EXPECT_EQ(string[6], 'm');
}

//TESTS FOR CLASS TElemTree

TEST(TElemTree, can_create_element_of_tabletree_without_parametres)
{
  ASSERT_NO_THROW(TElemTree<int> elem);
}

TEST(TElemTree, can_create_element_of_tabletree_with_parametres)
{
  TString string("old");
  TString string2("new");
  ASSERT_NO_THROW(TElemTree<int> element(1, string));
  TElemTree<int> element(1, string);
  ASSERT_NO_THROW(TElemTree<int> element1(2, string2, &element, &element, &element));
}

TEST(TElemTree, can_create_copy_of_element_of_tabletree)
{
  TString string("new");
  TElemTree<int> element(1, string);
  TElemTree<int> element2(element);
  EXPECT_EQ(element.GetData(), 1);
  EXPECT_EQ(element.GetKey(), "new");
}

TEST(TElemTree, can_use_assign_operator)
{
  TString string("new");
  TElemTree<int> element(1, string);
  TElemTree<int> element2;
  element2 = element;
  EXPECT_EQ(element.GetData(), 1);
  EXPECT_EQ(element.GetKey(), "new");
}

TEST(TElemTree, can_get_data)
{
  TString string("new");
  TElemTree<int> element(1, string);
  EXPECT_EQ(element.GetData(), 1);
}

TEST(TElemTree, can_get_key)
{
  TString string("new");
  TElemTree<int> element(1, string);
  EXPECT_EQ(element.GetKey(), "new");
}

TEST(TElemTree, can_get_right)
{
  TString string("old");
  TString string2("new");
  TElemTree<int> element(1, string);
  TElemTree<int> element2(2, string2, NULL, &element);
  EXPECT_EQ(element2.GetRight(), &element);
}

TEST(TElemTree, can_get_left)
{
  TString string("old");
  TString string2("new");
  TElemTree<int> element(1, string);
  TElemTree<int> element2(2, string2, &element);
  EXPECT_EQ(element2.GetLeft(), &element);
}

TEST(TElemTree, can_get_parent)
{
  TString string("old");
  TString string2("new");
  TElemTree<int> element(1, string);
  TElemTree<int> element2(2, string2, NULL, NULL, &element);
  EXPECT_EQ(element2.GetParent(), &element);
}

TEST(TElemTree, can_set_data)
{
  TString string("new");
  TElemTree<int> element(1, string);
  element.SetData(2);
  EXPECT_EQ(element.GetData(), 2);
}

TEST(TElemTree, can_set_key)
{
  TString string("old");
  TString string1("new");
  TElemTree<int> element(1, string);
  element.SetKey(string1);
  EXPECT_EQ(element.GetKey(), string1);
}

TEST(TElemTree, can_set_right)
{
  TString string("old");
  TString string2("new");
  TElemTree<int> element(1, string);
  TElemTree<int> element2(2, string2);
  element2.SetRight(&element);
  EXPECT_EQ(element2.GetRight(), &element);
}

TEST(TElemTree, can_set_left)
{
  TString string("old");
  TString string2("new");
  TElemTree<int> element(1, string);
  TElemTree<int> element2(2, string2);
  element2.SetLeft(&element);
  EXPECT_EQ(element2.GetLeft(), &element);
}

TEST(TElemTree, can_set_parent)
{
  TString string("old");
  TString string2("new");
  TElemTree<int> element(1, string);
  TElemTree<int> element2(2, string2);
  element2.SetParent(&element);
  EXPECT_EQ(element2.GetParent(), &element);
}

TEST(TElemTree, can_compare_elements)
{
  TString string("old");
  TString string1("old");
  TString string2("new");
  TElemTree<int> element(1, string);
  TElemTree<int> element1(1, string1);
  TElemTree<int> element2(2, string2);
  EXPECT_TRUE(element == element1);
  EXPECT_FALSE(element == element2);
  EXPECT_TRUE(element != element2);
  EXPECT_FALSE(element != element1);
}

//TESTS FOR CLASS TTableTree
