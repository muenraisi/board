/* register_types.cpp */

#include "register_types.h"

#include "core/object/class_db.h"

#include "board_astar.h"
#include "board_property.h"

void initialize_board_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
            return;
    }
  GDREGISTER_CLASS(BoardAstar);
	//GDREGISTER_NATIVE_STRUCT(BoardProperty, "	Variant var;Variant min;Variant max;");
	GDREGISTER_CLASS(BoardPropertyManager);

}

void uninitialize_board_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
            return;
    }
   // Nothing to do here in this example.
}
