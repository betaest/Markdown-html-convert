#pragma once

#include <render.h>

namespace html {
std::string render(const ts::AstNode &root);
class Render : public ts::IRender {
   public:
    std::string render(const ts::AstNode &root);
};
}  // namespace html