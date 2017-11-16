#pragma once

#include <rule.h>

namespace html {
namespace rule {
class raw : public ts::IRenderRule {
    std::string tag() const override { return "raw"; }
    std::string render(const ts::AstNode &p) const override;
};
}  // namespace rule
}  // namespace html