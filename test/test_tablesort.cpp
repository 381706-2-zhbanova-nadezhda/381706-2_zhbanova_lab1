#include "ttablesort.h"

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

//TESTS FOR CLASS TTableSee

TEST(TTableSee, can_create_table_without_parametres)
{
  TTableSee<int> table;
  EXPECT_EQ(table.GetSize(), 1);
}

TEST(TTableSee, can_create_table_with_parametres)
{
  TTableSee<int> table(10);
  EXPECT_EQ(table.GetSize(), 10);
}

TEST(TTableSee, can_create_copy_of_table)
{
  TTableSee<int> table(10);
  TTableSee<int> table2(table);
  EXPECT_EQ(table2.GetSize(), 10);
}

TEST(TTableSee, can_get_size)
{
  TTableSee<int> table(10);
  EXPECT_EQ(table.GetSize(), 10);
}

TEST(TTableSee, can_get_count)
{
  TTableSee<int> table(10);
  EXPECT_EQ(table.GetCount(), 0);
  TString string("new");
  TElement<int> element(1, string);
  table.Add(element);
  EXPECT_EQ(table.GetCount(), 1);
}

TEST(TTableSee, can_add_element)
{
  TString string("new");
  TElement<int> element(1, string);
  TTableSee<int> table(10);
  table.Add(element);
  EXPECT_EQ(table[string], 1);
}

TEST(TTableSee, can_use_resize)
{
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(1, string2);
  TTableSee<int> table(1);
  table.Add(element);
  ASSERT_NO_THROW(table.Add(element2));
}

TEST(TTableSee, can_use_operator_for_index)
{
  TString string("new");
  TElement<int> element(1, string);
  TTableSee<int> table(10);
  table.Add(element);
  EXPECT_EQ(table[string], 1);
}

TEST(TTableSee, can_search_element)
{
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(1, string2);
  TTableSee<int> table(1);
  table.Add(element);
  table.Add(element2);
  EXPECT_TRUE(table.Search(string) == element);
}

TEST(TTableSee, can_add_element_without_key)
{
  TTableSee<int> table(5);
  TString string = table.Add(15);
  EXPECT_EQ(string.GetMemory()[0], 'K');
  EXPECT_EQ(string.GetMemory()[1], 'e');
  EXPECT_EQ(string.GetMemory()[2], 'y');
  TString string2 = "Key";
  TElement<int> element2(15, string2);
  EXPECT_TRUE(table.Search(string) == element2);
}

TEST(TTableSee, cad_delete_element_by_two_ways)
{
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(2, string2);
  TString string3("three");
  TElement<int> element3(3, string3);
  TTableSee<int> table(3);
  table.Add(element);
  table.Add(element2);
  table.Add(element3);
  table.Delete(element3);
  table.Delete(string2);
  EXPECT_EQ(table.GetCount(), 1);
}

TEST(TTableSee, can_not_delete_element_from_empty_table)
{
  TTableSee<int> table(3);
  TString string("one");
  TElement<int> element(1, string);
  EXPECT_FALSE(table.Delete(element));
  EXPECT_FALSE(table.Delete(string));
}

TEST(TTableSee, can_delete_element_from_not_empty_table)
{
  TTableSee<int> table(3);
  TString string("one");
  TElement<int> element(1, string);
  table.Add(element);
  TString string2("two");
  TElement<int> element2(2, string2);
  table.Add(element2);
  EXPECT_TRUE(table.Delete(element));
  EXPECT_TRUE(table.Delete(string2));
}

//TESTS FOR CLASS TTableSort

TEST(TSortTable, can_create_table_without_parametres)
{
  TSortTable<int> table;
  EXPECT_EQ(table.GetSize(), 1);
}

TEST(TSortTable, can_create_table_with_parametres)
{
  TSortTable<int> table(10);
  EXPECT_EQ(table.GetSize(), 10);
}

TEST(TSortTable, can_use_resize)
{
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(1, string2);
  TSortTable<int> table(1);
  table.Add(element);
  ASSERT_NO_THROW(table.Add(element2));
}

TEST(TSortTable, can_create_sort_table_using_different_sortings)
{
  TTableSee<int> table(3);
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(2, string2);
  TString string3("three");
  TElement<int> element3(3, string3);
  table.Add(element3);
  table.Add(element);
  table.Add(element2);
  ASSERT_NO_THROW(TSortTable<int> temp(table, 1));
  ASSERT_NO_THROW(TSortTable<int> temp1(table, 2));
  ASSERT_NO_THROW(TSortTable<int> temp2(table, 3));
}

TEST(TSortTable, can_create_copy_of_table)
{
  TSortTable<int> table(10);
  TSortTable<int> table2(table);
  EXPECT_EQ(table2.GetSize(), 10);
}

TEST(TSortTable, can_get_size)
{
  TSortTable<int> table(10);
  EXPECT_EQ(table.GetSize(), 10);
}

TEST(TSortTable, can_get_count)
{
  TSortTable<int> table(10);
  EXPECT_EQ(table.GetCount(), 0);
  TString string("new");
  TElement<int> element(1, string);
  table.Add(element);
  EXPECT_EQ(table.GetCount(), 1);
}

TEST(TSortTable, can_add_element)
{
  TSortTable<int> table(10);
  TString string("One");
  TElement<int> element(1, string);
  table.Add(element);
  EXPECT_EQ(table[string], 1);
}

TEST(TSortTable, can_add_element_without_key)
{
  TSortTable<int> table(5);
  TString string = table.Add(15);
  EXPECT_EQ(string.GetMemory()[0], 'K');
  EXPECT_EQ(string.GetMemory()[1], 'e');
  EXPECT_EQ(string.GetMemory()[2], 'y');
  TString string2 = "Key";
  TElement<int> element2(15, string2);
  EXPECT_TRUE(table.LineSearch(string) == element2);
}

TEST(TSortTable, cad_delete_element_by_two_ways)
{
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(2, string2);
  TString string3("three");
  TElement<int> element3(3, string3);
  TSortTable<int> table(3);
  table.Add(element);
  table.Add(element2);
  table.Add(element3);
  table.Delete(element3);
  table.Delete(string2);
  EXPECT_EQ(table.GetCount(), 1);
}

TEST(TSortTable, can_not_delete_element_from_empty_table)
{
  TSortTable<int> table(3);
  TString string("one");
  TElement<int> element(1, string);
  EXPECT_FALSE(table.Delete(element));
  EXPECT_FALSE(table.Delete(string));
}

TEST(TSortTable, can_delete_element_from_not_empty_table)
{
  TSortTable<int> table(3);
  TString string("one");
  TElement<int> element(1, string);
  table.Add(element);
  TString string2("two");
  TElement<int> element2(2, string2);
  table.Add(element2);
  EXPECT_TRUE(table.Delete(element));
  EXPECT_TRUE(table.Delete(string2));
}

TEST(TSortTable, can_use_operator_for_index)
{
  TString string("new");
  TElement<int> element(1, string);
  TSortTable<int> table(10);
  table.Add(element);
  EXPECT_EQ(table[string], 1);
}

TEST(TSortTable, can_search_element)
{
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(2, string2);
  TString string3("three");
  TElement<int> element3(3, string3);
  TSortTable<int> table(1);
  table.Add(element);
  table.Add(element2);
  table.Add(element3);
  EXPECT_TRUE(table.LineSearch(string2) == element2);
  EXPECT_TRUE(table.BinarySearch(string2) == element2);
}

TEST(TSortTable, can_sort_table_by_insert_sort)
{
  TTableSee<int> table(3);
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(2, string2);
  TString string3("three");
  TElement<int> element3(3, string3);
  table.Add(element3);
  table.Add(element);
  table.Add(element2);
  TSortTable<int>::InsertSort(table);
  EXPECT_TRUE(table.GetNode()[0].GetKey() == "one");
}

TEST(TSortTable, can_sort_seetable_by_selection_sort)
{
  TTableSee<int> table(3);
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(2, string2);
  TString string3("three");
  TElement<int> element3(3, string3);
  table.Add(element3);
  table.Add(element);
  table.Add(element2);
  TSortTable<int>::SelectionSort(table);
  EXPECT_TRUE(table.GetNode()[0].GetKey() == "one");
}

TEST(TSortTable, can_sort_seetable_by_quick_sort)
{
  TTableSee<int> table(3);
  TString string("one");
  TElement<int> element(1, string);
  TString string2("two");
  TElement<int> element2(2, string2);
  TString string3("three");
  TElement<int> element3(3, string3);
  table.Add(element3);
  table.Add(element);
  table.Add(element2);
  TSortTable<int>::QuickSort(table, 0, table.GetCount() - 1);
  EXPECT_TRUE(table.GetNode()[0].GetKey() == "one");
}