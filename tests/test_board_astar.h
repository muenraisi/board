// test_indie_a_star_grid_2d.h
#ifndef TEST_BOARD_ASTAR_H
#define TEST_BOARD_ASTAR_H

#include "tests/test_macros.h"

#include "modules/board/board_astar.h"

namespace TestBoardAstar {

TEST_CASE("[Modules][TestBoardAstar]  ") {
	Ref<BoardAstar> astar = memnew(BoardAstar);
	
	astar->set_default_heuristic(BoardAstar::HEURISTIC_MANHATTAN);
	CHECK(astar->get_default_heuristic() == BoardAstar::HEURISTIC_MANHATTAN);

	astar->set_diagonal_mode(BoardAstar::DIAGONAL_MODE_NEVER);
	CHECK(astar->get_diagonal_mode() == BoardAstar::DIAGONAL_MODE_NEVER);

	astar->set_size(Vector2i(5,5));
	CHECK(astar->get_size() == Vector2i(5, 5));
	astar->set_cell_size(Vector2i(2,2));
	CHECK(astar->get_cell_size() == Vector2i(2, 2));


	astar->update();
	astar->set_point_solid(Vector2i(1, 1));


	CHECK(astar->get_id_path(Vector2i(0, 0), Vector2i(3, 3)) == astar->get_id_path_float(Vector2(0., 0.), Vector2i(3, 3)));

	Vector<Vector2> path = { Vector2(0.3, 0), Vector2(0, 0) };
	CHECK(astar->get_id_path_float(Vector2(0.3, 0), Vector2i(0, 0)) == path);

	path = { Vector2(0, 0.3), Vector2(0, 0), Vector2(1, 0), Vector2(2, 0), Vector2(2, 1) };
	CHECK(astar->get_id_path_float(Vector2(0, 0.3), Vector2i(2, 1)) == path);

	path = { Vector2(0, 0.7), Vector2(0, 0), Vector2(1, 0), Vector2(2, 0), Vector2(2, 1) };
	CHECK(astar->get_id_path_float(Vector2(0., 0.7), Vector2i(2, 1)) == path);

	path = { Vector2(0, 1.3), Vector2(0, 2), Vector2(1, 2), Vector2(2, 2), Vector2(2, 1) };
	CHECK(astar->get_id_path_float(Vector2(0, 1.3), Vector2i(2, 1)) == path);

    //s->reset();
    //CHECK(s->get_total() == 0);
}

} // namespace TestBoardAstar

#endif // TEST_BOARD_ASTAR_H
