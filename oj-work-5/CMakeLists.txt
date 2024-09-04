add_executable(behaviors behaviors.c)
target_link_libraries(behaviors m)

add_executable(sum sum.c)
target_link_libraries(sum m)

add_executable(magic-square magic-square.c)
target_link_libraries(magic-square m)

add_executable(absolute-prime absolute-prime.c)
target_link_libraries(absolute-prime m)

add_executable(trail trail.c)
target_link_libraries(trail m)

add_executable(radix radix.c)
target_link_libraries(radix m)

add_executable(next next.c)
target_link_libraries(next m)

add_executable(pair pair.c)
target_link_libraries(pair m)