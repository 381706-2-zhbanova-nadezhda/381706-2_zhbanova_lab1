#pragma once

#include <iostream>
#include <string>

class TException
{
private:
  std::string str;
public:
  TException(std::string _str): str(_str) {}
  void Show()
  {
  std::cout << "\nWarning! \nMessage: " << str << std::endl;
  }
};
