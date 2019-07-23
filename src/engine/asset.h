#pragma once
#include <map>
#include <sstream>
#include <vector>

namespace Engine {
namespace Assets {

enum AssetType {
  SHADER_PROGRAM_VERT_FRAG,
  MESH,
};

class Asset {
 protected:
  bool loaded;

 public:
  Asset(std::string name, std::vector<std::string> flags, std::string path,
        AssetType type)
      : name{name}, flags{flags}, path{path}, type{type}, loaded{false} {};

  const std::string name;
  const std::vector<std::string> flags;
  const std::string path;
  const AssetType type;

  virtual void load() = 0;
  virtual void release() = 0;

  bool isLoaded() { return loaded; };
};
} // namespace Assets
} // namespace Engine
