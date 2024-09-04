add_executable(matrix-mult matrix-mult.c)
target_link_libraries(matrix-mult m)

add_executable(formation formation.c)
target_link_libraries(formation m)

set(CMAKE_BUILD_TYPE Debug)

add_executable(sudoku sudoku.c)
target_link_libraries(sudoku m)

add_executable(mines mines.c)
target_link_libraries(mines m)

add_executable(trace trace.c)
target_link_libraries(trace m)

add_executable(statistics statistics.c)
target_link_libraries(statistics m)