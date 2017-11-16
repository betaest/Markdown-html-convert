#pragma once

#include <rule.h>

namespace html {
namespace rule {
class Head : public ts::IRenderRule {
    std::string tag() const override { return "h"; }
    std::string render(const ts::AstNode &p) const override;
};
}  // namespace rule
}  // namespace html