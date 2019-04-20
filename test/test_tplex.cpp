#include "tplex.h"
#include <gtest.h>

//TESTS FOR CLASS TPoint

TEST(TPoint, can_create_point_without_parametrs)
{
  ASSERT_NO_THROW(TPoint point);
}

TEST(TPoint, point_was_created_without_parametrs_has_nulls)
{
  TPoint point;
  EXPECT_EQ(point.GetX(), 0);
  EXPECT_EQ(point.GetY(), 0);
}

TEST(TPoint, can_create_point_with_parametrs)
{
  ASSERT_NO_THROW(TPoint point(3,5));
}

TEST(TPoint, can_get_x_and_y)
{
  TPoint point(3,5);
  EXPECT_EQ(point.GetX(), 3);
  EXPECT_EQ(point.GetY(), 5);
}

TEST(TPoint, can_set_x_and_y)
{
  TPoint point(3,5);
  point.SetX(7);
  point.SetY(8);
  EXPECT_EQ(point.GetX(), 7);
  EXPECT_EQ(point.GetY(), 8);
}

TEST(TPoint, can_create_copy_of_point)
{
  TPoint point(3,5);
  ASSERT_NO_THROW(TPoint point2(point));
  TPoint point2(point);
  EXPECT_EQ(point2.GetX(), 3);
  EXPECT_EQ(point2.GetY(), 5);
}

TEST(TPoint, compare_equal_points_return_true)
{
  TPoint point(3,5);
  TPoint point2(3,5);
  EXPECT_TRUE(point == point2);
}

TEST(TPoint, compare_non_equal_points_return_false)
{
  TPoint point(3,5);
  TPoint point2(9,1);
  EXPECT_FALSE(point == point2);
}

TEST(TPoint, can_return_true_if_points_are_not_equil)
{
  TPoint point(3,5);
  TPoint point2(9,1);
  EXPECT_TRUE(point != point2);
}

TEST(TPoint, can_return_false_if_points_are_equil)
{
  TPoint point(3,5);
  TPoint point2(3,5);
  EXPECT_FALSE(point != point2);
}

//TESTS FOR CLASS TLine

TEST(TLine, can_create_line)
{
  ASSERT_NO_THROW(TLine line);
}

TEST(TLine, can_create_line_by_points)
{
  TPoint point(3,5);
  TPoint point2(9,1);
  ASSERT_NO_THROW(TLine line(&point, &point2));
}

TEST(TLine, can_create_copy_of_line)
{
  TPoint point(3,5);
  TPoint point2(9,1);
  TLine line(&point, &point2);
  ASSERT_NO_THROW(TLine line2(line));
  TLine line2(line);
  EXPECT_EQ(line2.GetX1(), 3);
  EXPECT_EQ(line2.GetY1(), 5);
  EXPECT_EQ(line2.GetX2(), 9);
  EXPECT_EQ(line2.GetY2(), 1);
}

TEST(TLine, can_get_point_A_and_point_B)
{
  TPoint point(3,5);
  TPoint point2(9,1);
  TLine line(&point, &point2);
  EXPECT_TRUE(*line.GetPointA() == point);
  EXPECT_TRUE(*line.GetPointB() == point2);
}

TEST(TLine, can_set_point_A_and_point_B)
{
  TLine line;
  TPoint point(3,5);
  TPoint point2(9,1);
  ASSERT_NO_THROW(line.SetPointA(&point));
  ASSERT_NO_THROW(line.SetPointB(&point2));
  line.SetPointA(&point);
  line.SetPointB(&point2);
  EXPECT_EQ(line.GetX1(), 3);
  EXPECT_EQ(line.GetY1(), 5);
  EXPECT_EQ(line.GetX2(), 9);
  EXPECT_EQ(line.GetY2(), 1);
}

TEST(TLine, can_get_x_and_y_of_point_A_and_point_B)
{
  TPoint point(3,5);
  TPoint point2(9,1);
  TLine line(&point, &point2);
  EXPECT_EQ(line.GetX1(), 3);
  EXPECT_EQ(line.GetY1(), 5);
  EXPECT_EQ(line.GetX2(), 9);
  EXPECT_EQ(line.GetY2(), 1);
}

TEST(TLine, can_set_x_and_y_of_point_A_and_point_B)
{
  TLine line;
  line.SetX1(3);
  line.SetY1(5);
  line.SetX2(9);
  line.SetY2(1);
  EXPECT_EQ(line.GetX1(), 3);
  EXPECT_EQ(line.GetY1(), 5);
  EXPECT_EQ(line.GetX2(), 9);
  EXPECT_EQ(line.GetY2(), 1);
}

TEST(TLine, can_get_length_of_line)
{
  TPoint point(1,1);
  TPoint point2(4,5);
  TLine line(&point, &point2);
  EXPECT_EQ(line.GetLength(), 5);
}

TEST(TLine, compare_equal_lines)
{
  TPoint point(3,5);
  TPoint point2(1,5);
  TLine line(&point, &point2);
  TLine line2(line);
  EXPECT_TRUE(line == line2);
  EXPECT_FALSE(line != line2);
}

TEST(TLine, compare_non_equal_lines)
{
  TPoint point(3,5);
  TPoint point2(3,6);
  TPoint point3(7,1);
  TLine line(&point, &point2);
  TLine line2(&point2, &point3);
  EXPECT_TRUE(line != line2);
  EXPECT_FALSE(line == line2);
}

//TESTS FOR CLASS TPlex

TEST(TPlex, can_create_plex)
{
  ASSERT_NO_THROW(TPlex plex);
}

TEST(TPlex, can_create_plex_by_points)
{
  TPoint point(3,5);
  TPoint point2(7,4);
  ASSERT_NO_THROW(TPlex plex(&point, &point2));
}

TEST(TPlex, can_create_plex_by_plexes)
{
  TPoint point(3,5);
  TPoint point2(7,4);
  TPoint point3(8,3);
  TPlex plex(&point, &point2);
  TPlex plex2(&plex, &point3);
  ASSERT_NO_THROW(TPlex res(&plex, &plex2));
}

TEST(TPlex, can_create_copy_of_plex)
{
  TPoint point(3,5);
  TPoint point2(7,4);
  TPoint point3(8,3);
  TPlex plex(&point, &point2);
  TPlex plex2(&plex, &point3);
  TPlex win(&plex, &plex2);
  ASSERT_NO_THROW(TPlex plex2(plex));
  ASSERT_NO_THROW(TPlex plex3(plex2));
  ASSERT_NO_THROW(TPlex win2(win));
}

TEST(TPlex, can_add_line_to_plex)
{
  TPoint point(3,5);
  TPoint point2(7,4);
  TPoint point3(8,3);
  TPoint point4(3,3);
  TPlex plex(&point, &point2);
  TPlex plex1(&plex, &point3);
  TLine line;
  line.SetPointA(&point4);
  line.SetPointB(&point3);
  ASSERT_NO_THROW(plex1 += line);
}