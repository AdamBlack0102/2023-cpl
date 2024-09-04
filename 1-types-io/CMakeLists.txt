add_executable(circle circle.c)
add_executable(sphere sphere.c)
add_executable(mol mol.c)


add_executable(administration administration.c)
target_link_libraries(administration m)

add_executable(admin-scanf admin-scanf.c)
