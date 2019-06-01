#include "thashtable.h"

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

//TESTS FOR CLASS TElement

TEST(TElement, can_create_element_without_parametres)
{
  ASSERT_NO_THROW(TElement<int> elem);
  TElement<int> element;
  EXPECT_EQ(element.GetData(), 0);
  EXPECT_EQ(element.GetKey(), " ");
}

TEST(TElement, can_create_element_with_parametres)
{
  TString string("new");
  ASSERT_NO_THROW(TElement<int> element(1, string));
}

TEST(TElement, can_create_copy_of_element)
{
  TString string("new");
  TElement<int> element(1, string);
  TElement<int> element2(element);
  EXPECT_EQ(element.GetData(), 1);
  EXPECT_EQ(element.GetKey(), "new");
}

TEST(TElement, can_use_assign_operator)
{
  TString string("new");
  TElement<int> element(1, string);
  TElement<int> element2;
  element2 = element;
  EXPECT_EQ(element.GetData(), 1);
  EXPECT_EQ(element.GetKey(), "new");
}

TEST(TElement, can_get_data)
{
  TString string("new");
  TElement<int> element(1, string);
  EXPECT_EQ(element.GetData(), 1);
}

TEST(TElement, can_set_data)
{
  TString string("new");
  TElement<int> element(1, string);
  element.SetData(2);
  EXPECT_EQ(element.GetData(), 2);
}

TEST(TElement, can_get_key)
{
  TString string("new");
  TElement<int> element(1, string);
  EXPECT_EQ(element.GetKey(), "new");
}

TEST(TElement, can_set_key)
{
  TString string("old");
  TString string1("new");
  TElement<int> element(1, string);
  element.SetKey(string1);
  EXPECT_EQ(element.GetKey(), string1);
}

TEST(TElement, can_compare_elements)
{
  TString string("old");
  TString string1("old");
  TString string2("new");
  TElement<int> element(1, string);
  TElement<int> element1(1, string1);
  TElement<int> element2(2, string2);
  EXPECT_TRUE(element == element1);
  EXPECT_FALSE(element == element2);
  EXPECT_TRUE(element != element2);
  EXPECT_FALSE(element != element1);
}

//TESTS FOR CLASS THashTable

TEST(THashTable, can_create_hashtable_without_parametres)
{
  THashTable<int> table;
  EXPECT_EQ(table.GetSize(), 1);
}

TEST(THashTable, can_create_hashtable_with_parametres)
{
  THashTable<int> table(10);
  EXPECT_EQ(table.GetSize(), 10);
}

TEST(THashTable, can_create_copy_of_table)
{
  THashTable<int> table(10);
  THashTable<int> table2(table);
  EXPECT_EQ(table2.GetSize(), 10);
}

TEST(THashTable, can_get_size)
{
  THashTable<int> table(10);
  EXPECT_EQ(table.GetSize(), 10);
}

TEST(THashTable, can_get_count)
{
  THashTable<int> table(10);
  EXPECT_EQ(table.GetCount(), 0);
  TString string("new");
  TElement<int> element(1, string);
  table.Add(element);
  EXPECT_EQ(table.GetCount(), 1);
}

TEST(THashTable, can_get_node)
{
  THashTable<int> table(10);
  EXPECT_NO_THROW(table.GetNode());
}

TEST(THashTable, can_add_element_1)
{
  TString string("new");
  TElement<int> element(1, string);
  THashTable<int> table(10);
  EXPECT_NO_THROW(table.Add(element));
}

TEST(THashTable, can_add_element_2)
{
  TString string("new");
  THashTable<int> table(10);
  EXPECT_NO_THROW(table.Add(string, 5));
}

TEST(THashTable, can_use_resize)
{
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(1, string2);
  THashTable<int> table(1);
  table.Add(element);
  ASSERT_NO_THROW(table.Add(element2));
}

TEST(THashTable, can_search_element)
{
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(2, string2);
  THashTable<int> table(1);
  table.Add(element);
  table.Add(element2);
  EXPECT_EQ(table.Search(string), 1);
}

TEST(THashTable, can_delete_element_from_not_empty_table)
{
  THashTable<int> table(3);
  TString string("one");
  TElement<int> element(1, string);
  table.Add(element);
  TString string2("two");
  TElement<int> element2(2, string2);
  table.Add(element2);
  EXPECT_TRUE(table.Delete(string2));
}