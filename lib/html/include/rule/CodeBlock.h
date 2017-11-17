#pragma once

#include <rule.h>

namespace html {
namespace rule {
class CodeBlock : public ts::IRenderRule {
    std::string tag() const override { return "code"; }
    std::string render(const ts::AstNode &p) const override;
};
}  // namespace rule
}  // namespace html