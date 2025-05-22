#include "audio/wav.hpp"

namespace wav{
  std::tuple<WavHeader, std::vector<int16_t>> read_wav(std::string file_path){
    WavHeader header;
    std::ifstream in(file_path, std::ios::binary);

    if (!in.is_open()) {
      throw std::runtime_error("Failed to open file: " + file_path);
    }

    in.read(reinterpret_cast<char*>(&header), sizeof(WavHeader));

    if (!in) {
      throw std::runtime_error("Failed to read WAV header: file too short or corrupt");
    }

    if (std::strncmp(header.riff_header, "RIFF", 4) ||
    std::strncmp(header.wave_header, "WAVE", 4) ||
    std::strncmp(header.fmt_header , "fmt ", 4) ||
    std::strncmp(header.data_header, "data", 4)) {
      throw std::runtime_error("Invalid WAV file");
    }

    std::vector<int16_t> pcm_data(header.data_size/sizeof(int16_t));
    in.read(reinterpret_cast<char*>(pcm_data.data()), header.data_size);
    return std::make_tuple(header, pcm_data);
  }

  bool write_wav(std::string f_path, const WavHeader& header, std::vector<char> data){
    std::ofstream out(f_path, std::ios::binary);
    if(!out) return false;

    out.write(reinterpret_cast<const char*>(&header), sizeof(WavHeader));
    out.write(data.data(), data.size());
    out.close();
    return true;
  }
}
