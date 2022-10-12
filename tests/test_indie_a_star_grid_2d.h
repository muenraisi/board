// test_indie_a_star_grid_2d.h
#ifndef TEST_INDIE_A_STAR_GRID_2D_H
#define TEST_INDIE_A_STAR_GRID_2D_H

#include "tests/test_macros.h"

#include "modules/indie/indie_a_star_grid_2d.h"

namespace TestIndieAStarGrid2D {

TEST_CASE("[Modules][TestIndieAStarGrid2D] ") {
	Ref<IndieAStarGrid2D> astar = memnew(IndieAStarGrid2D);
	
	astar->set_default_heuristic(IndieAStarGrid2D::HEURISTIC_MANHATTAN);
	CHECK(astar->get_default_heuristic() == IndieAStarGrid2D::HEURISTIC_MANHATTAN);


    //s->reset();
    //CHECK(s->get_total() == 0);
}

} // namespace TestIndieAStarGrid2D

#endif // TEST_INDIE_A_STAR_GRID_2D_H
