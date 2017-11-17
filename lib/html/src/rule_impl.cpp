#include <html_render.h>
#include <rule/CodeBlock.h>
#include <rule/Head.h>
#include <rule/raw.h>
#include <rule/text.h>
#include <sstream>

using namespace ts;
namespace html {
namespace rule {
std::string CodeBlock::render(const AstNode &p) const {
    std::ostringstream str;

    if (p.tag() == tag()) {
        str << "<pre><code";
        std::string lang;

        try {
            lang = p.extends("lang");
        } catch (...) {
            ;
        }

        if (!lang.empty())
            str << " class='" << lang << "'>";
        else
            str << ">";

        auto text = p.children(0);

        str << text.extends("text") << "</code></pre>";
    }

    return str.str();
}

std::string Head::render(const AstNode &p) const {
    std::stringstream str;

    if (p.tag() == tag()) {
        auto label = tag() + p.extends("level");

        str << "<" << label << ">" << html::render(p);
        str << "</" << label << ">";
    }

    return str.str();
}

std::string raw::render(const AstNode &p) const {
    std::stringstream str;

    str << p.extends("text");

    return str.str();
}

std::string text::render(const AstNode &p) const {
    std::stringstream str;

    str << p.extends("text");

    return str.str();
}
}  // namespace rule
}  // namespace html
