#pragma once

#include <rule.h>
#include <algorithm>

namespace gfm {
namespace rule {
class linktext : public core {
   public:
    std::string tag() const { return "a"; }
    paragraph_t paragraph_type() const override { return paragraph_t::paragraph; }
    bool matched(bool beginl, const ts::Token &in) const override {
        auto str = in.str();
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);

        return str == "http" || str == "https" || str == "ftp" ||
               str == "mailto";
    }
    bool parse(ts::Token &in, const ts::AstNode &parent,
               ts::AstNode &node) const override {
        std::string text;
        do {
            text += in.str();
        } while (in.read() && !in.all_space());

        node.children()->add("text", text);
        node.extends("href", text);
        in.unread();

        return true;
    }
};
}  // namespace rule
}  // namespace gfm