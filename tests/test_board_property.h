// test_board_property.h
#ifndef TEST_BOARD_PROPERTY_H
#define TEST_BOARD_PROPERTY_H

#include "tests/test_macros.h"
#include "modules/board/board_property_manager.h"

namespace TestBoardProperty {

TEST_CASE("[Modules][TestBoardProperty] Adding numbers") {
    Ref<BoardPropertyManager> property = memnew(BoardPropertyManager);

	//1.添加属性
	property->insert("atk", 100);
	CHECK(property->has("atk"));

	//2. 自动生成各属性接口
	property->set_var("atk", 50);
	CHECK((property->get_var("atk")) == Variant(50));

	//3. 获取最终属性
	CHECK((property->get_final_var("atk")) == Variant(50));
	//set buff
	//CHECK buff

	//4. 设置和获取属性最大值和最小值
	property->set_low("atk", 0);
	CHECK((property->get_low("atk")) == Variant(0));
	property->set_upp("atk", 999999);
	CHECK((property->get_upp("atk")) == Variant(999999));
	property->set_range("atk", 0, 100);
	CHECK((property->get_low("atk")) == Variant(0));
	CHECK((property->get_upp("atk")) == Variant(100));


	//5. 获取值时，确保在范围内
	property->set_var("atk", 500000);
	CHECK((property->get_final_var("atk")) == Variant(100));
	property->set_var("atk", 90);
	CHECK((property->get_final_var("atk")) == Variant(90));
	property->set_var("atk", -5);
	CHECK((property->get_final_var("atk")) == Variant(0));

	
	//# 3. buff接口
	// buff = memew(Buffer)
	// property->add_buff(buff);
	// CHECK(property->get_final("atk")==?);
}
} // namespace TestBoardProperty

#endif // TEST_DYNAMICPROPERTY_H
