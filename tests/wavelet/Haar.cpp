#include "wavelet/Haar.hpp"
#include <iostream>

bool simple_test(){
  wavelet::vec signal = {1,2,3,4,4,3,2,1};
  wavelet::vec decomp = wavelet::haar_decomp(signal,4);
  wavelet::vec recomp = wavelet::haar_reconstruct(decomp,4);

  std::cout << "sig: ";
  for(auto const& num: signal) std::cout << num << " ";
  std::cout << std::endl;

  std::cout << "decomp: ";
  for(auto const& num: decomp) std::cout << num << " ";
  std::cout << std::endl;

  std::cout << "reconstruct: ";
  for(auto const& num: recomp) std::cout << num << " ";
  std::cout << std::endl;

  if(recomp==signal) return true;
  return false;
}

// int main(){
//   simple_test();
//   return 0;
// }
