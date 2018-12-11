#include <iostream>
#include "utmatrix.cpp"
#include "utvector.cpp"

int main()
{
  TMatrix<int> a(5);
  std::cout<<"Enter matrix with size = 5:"<<std::endl;
  cin>>a;
  /* Enter something like:
   * 1 2 3 4 5 press Enter
   * 4 3 2 1 press Enter
   * 1 2 3 press Enter
   * 2 1 press Enter
   * 1 press Enter
   */

  cout<<"Matrix: "<<std::endl;
  cout<<a;

  /* You will see:
   * 1 2 3 4 5
   * 0 4 3 2 1
   * 0 0 1 2 3
   * 0 0 0 2 1
   * 0 0 0 0 1
   */
  return 0;
}
