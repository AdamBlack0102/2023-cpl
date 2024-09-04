add_executable(ASCII ASCII)
target_link_libraries(ASCII m)

add_executable(change change.c)
target_link_libraries(change m)

add_executable(pi pi.c)
target_link_libraries(pi m)

add_executable(time time.c)
target_link_libraries(time m)

add_executable(julian julian.c)
target_link_libraries(julian m)

add_executable(gravity gravity.c)
target_link_libraries(gravity m)

add_executable(equation equation.c)
target_link_libraries(equation m)