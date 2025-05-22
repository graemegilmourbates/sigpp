#include <vector>
// Simple Haar Wavelet

namespace wavelet{
  using vec = std::vector<double>;
  vec haar_decomp(const vec& signal, int levels);
  vec haar_reconstruct(const vec& coeffs, int levels);

  using Matrix = std::vector<std::vector<double>>;
  Matrix haar_2d_decomp(const Matrix& img, int levels);
  Matrix haar_2d_reconstruct(const Matrix& img, int levels);
}
