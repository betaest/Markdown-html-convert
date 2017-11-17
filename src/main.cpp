#include <translator.h>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
    auto gfm = ts::make_parser("gfm");
    auto html = ts::make_render("html");

    ts::set_default_render(html);

    if (argc == 2) {
        std::ifstream fin{argv[1]};
        std::ofstream fout{argv[2]};

        if (fin.is_open() && fout.is_open()) {
            fin >> gfm;
            fout << gfm;
        }

    } else {  //全部读取并输出
        std::cin >> gfm;
        std::cout << gfm;
        // out << html->render(gfm->document());
    }
}