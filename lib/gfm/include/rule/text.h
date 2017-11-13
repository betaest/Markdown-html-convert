#include <rule.h>
#include <utils.h>

namespace gfm {
namespace rule {
class text : public core {
   public:
    std::string tag() const override { return "text"; }
    paragraph_t paragraph_type() const override { return paragraph_t::paragraph; }
    bool matched(bool beginl, const ts::Token &in) const override {
        return true;
    }
    bool parse(ts::Token &in, const ts::AstNode &parent,
               ts::AstNode &node) const override {
        node.extends("text", in.str());

        return true;
    }
};
}  // namespace rule
}  // namespace gfm