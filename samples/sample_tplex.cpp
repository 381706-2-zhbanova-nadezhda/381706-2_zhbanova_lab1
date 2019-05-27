#include <iostream>
#include <locale.h>
#include "tplex.h"

int main()
{
  //EXAMPLE
  std::cout << "Creation of PLEX ...";
  int x1, x2, x3, y1, y2, y3;
  std::cout << "\nInput Point1: ";
  std::cin >> x1 >> y1;
  TPoint P(x1, y1);
  std::cout << "Input Point2: ";
  std::cin >> x2 >> y2;
  TPoint P2(x2, y2);
  std::cout << "\nPLEX1 (by points):\n";
  TPlex plex(&P, &P2);
  plex.Show();
  std::cout << "\nInput Point3: ";
  std::cin >> x3 >> y3;
  TPoint P3(x3, y3);
  std::cout << "\nPLEX2 (by Plex1 and Point3):\n";
  TPlex plex2(&plex, &P3);
  plex2.Show();
  std::cout << "\nCOPY of Plex2:\n";
  TPlex plex3(plex2);
  plex3.Show();
  return 0;
}