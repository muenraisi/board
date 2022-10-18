// test_board_property.h
#ifndef TEST_BOARD_PROPERTY_H
#define TEST_BOARD_PROPERTY_H

#include "tests/test_macros.h"
#include "modules/board/board_property.h"

namespace TestBoardProperty {

TEST_CASE("[Modules][TestBoardProperty] Adding numbers") {
    Ref<BoardProperty> property = memnew(BoardProperty);

	//1.添加属性
	property->insert_base("atk", 100);
	CHECK(property->has("atk"));

	//2. 自动生成各属性接口
	property->set_base("atk", 50);
	CHECK((property->get_base("atk")) == Variant(50));

	//3. 获取最终属性
	CHECK((property->get("atk")) == Variant(50));
	//set buff
	//CHECK buff
	
	//# 3. buff接口
	// buff = memew(Buffer)
	// property->add_buff(buff);
	// CHECK(property->get_final("atk")==?);
}
} // namespace TestBoardProperty

#endif // TEST_DYNAMICPROPERTY_H
