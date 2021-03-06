#pragma once

#include <rule.h>

namespace html {
namespace rule {
class text : public ts::IRenderRule {
    std::string tag() const override { return "text"; }
    std::string render(const ts::AstNode &p) const override;
};
}  // namespace rule
}  // namespace html