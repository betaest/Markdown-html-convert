//该文件为自动生成，请勿自行修改
#include <rules.h>
#include <rule/CodeBlock.h>
#include <rule/Head.h>
#include <rule/raw.h>
#include <rule/text.h>

namespace html { 
	std::vector<std::shared_ptr<ts::IRenderRule>> rules {
		std::make_shared<rule::CodeBlock>(),
		std::make_shared<rule::Head>(),
		std::make_shared<rule::raw>(),
		std::make_shared<rule::text>(),
	};
}