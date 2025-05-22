#include <iostream>

bool test_read();
bool simple_test();

int main(){
  int fails=0;
  if(!test_read()) ++fails;
  if(!simple_test()) ++fails;
  std::cout << "Failed: " << fails << " tests." << std::endl;
  return 0;
}
