// test_summator.h
#ifndef TEST_DYNAMICPROPERTY_H
#define TEST_DYNAMICPROPERTY_H

#include "tests/test_macros.h"

#include "modules/summator/summator.h"

namespace TestDynamicProperty {

TEST_CASE("[Modules][TestDynamicProperty] Adding numbers") {
    Ref<TestDynamicProperty> s = memnew(TestDynamicProperty);
    CHECK(s->get_total() == 0);

    s->add(10);
    CHECK(s->get_total() == 10);

    s->add(20);
    CHECK(s->get_total() == 30);

    s->add(30);
    CHECK(s->get_total() == 60);

    s->reset();
    CHECK(s->get_total() == 0);
}

} // namespace TestSummator

#endif // TEST_DYNAMICPROPERTY_H