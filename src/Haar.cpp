#include "wavelet/Haar.hpp"
#include <cmath>
#include <stdexcept>

namespace wavelet{

  vec haar_decomp(const vec& signal, int levels){
    vec temp, approx, detail;
    temp = signal;
    int n = temp.size();
    for(int l=0; l<levels; ++l){
      for(int i=0; i<n; i+=2){
          approx.push_back((temp[i]+temp[i+1])/2);
          detail.push_back((temp[i]-temp[i+1])/2);
      }
      for(int i=0; i<n/2; ++i){
        temp[i]=approx[i]; temp[i+n/2]=detail[i];
      }
      n=n/2;
      approx.clear();
      detail.clear();
    }
    return temp;
  }

  vec haar_reconstruct(const vec& coeffs, int levels){
    vec temp = coeffs;
    int n = temp.size() / std::pow(2,levels-1);
    for(int l=0; l<levels; ++l){
      vec prev = temp;
      for(int i=0; i<n/2; ++i){
        temp[2*i] = (prev[i] + prev[i+n/2]);
        temp[2*i+1] = (prev[i] - prev[i+n/2]);
      }
      n *= 2;
    }
    return temp;
  }

}
