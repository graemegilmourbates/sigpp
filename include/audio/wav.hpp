#include <iostream>
#include <vector>
#include <fstream>

namespace wav{
  // WAV header structure
  struct WavHeader {
      char riff_header[4];
      uint32_t file_size;
      char wave_header[4];
      char fmt_header[4];
      uint32_t fmt_chunk_size;
      uint16_t audio_format;
      uint16_t num_channels;
      uint32_t sample_rate;
      uint32_t byte_rate;
      uint16_t block_align;
      uint16_t bits_per_sample;
      char data_header[4];
      uint32_t data_size;
  };

  std::tuple<WavHeader, std::vector<int16_t>> read_wav(std::string file_path);
  bool write_wav(std::string f_path, const WavHeader& header, std::vector<char> data);
}
