#include <html_render.h>
#include <rules.h>
#include <sstream>

namespace html {
std::string render(const ts::AstNode &root) {
    std::stringstream str;

    for (auto &node : root) {
        bool done = false;
        for (auto &rule : rules) {
            if (rule->tag() == node.tag()) {
                done = true;
                str << rule->render(node);
            }
        }

        if (!done) {
            str << "<" << node.tag();

            if (node.extends()->size() != 0) {
                auto keys = ts::keys(node.extends_r());
                for (auto &key : keys)
                    str << " " << key << "=\"" + node.extends(key) + "\"";
            }

            str << ">" << html::render(node) << "</" << node.tag() << ">";
        }
    }

    return str.str();
}

std::string Render::render(const ts::AstNode &root) {
    std::stringstream str;

    str << R"(<!doctype><html><script src="//cdnjs.cloudflare.com/ajax/libs/highlight.js/9.4.0/languages/go.min.js"></script></html><body>)";
    str << html::render(root);
    str << "</body></html>";

    return str.str();
}
}  // namespace html