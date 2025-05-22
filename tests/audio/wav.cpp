#include "audio/wav.hpp"

bool test_read(){
  try{
    auto data = wav::read_wav("data/c_minor_scale.wav");
  } catch(const std::runtime_error& error) {
        std::cerr << "Error: " << error.what() << std::endl;
        return false;
  }
  std::cout << "Data Read Success..." << std::endl;
  return true;
}

// int main(){
//   return 0;
// }
