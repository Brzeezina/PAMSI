cmake_minimum_required(VERSION 3.15)


#set(CMAKE_BUILD_TYPE Debug "build/Project_1 -exec -enable-pretty-printing")
#set(CMAKE_BUILD_TYPE RelWithDebInfo)
project(project1)



include(CTest)
enable_testing()

add_compile_options(-Wall -Wextra)
add_compile_options(-pedantic)
add_compile_options(-Werror=return-type)
add_compile_options(-Werror=parentheses)
add_compile_options(-Werror=vla)
add_compile_options(-Werror=array-bounds)
add_compile_options ( -Wcast-qual )
add_compile_options ( -Wmaybe-uninitialized )
#add_compile_options(-lsfml-graphics -lsfml-window -lsfml-system)

# add this  flags "-exec -enable-pretty-printing" to Cmake to use gdb


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CMAKE_CXX_STANDARD 14)

# to add all librries in a file
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


add_library(libProject_1 STATIC
  "${PROJECT_SOURCE_DIR}/src/vector_custom.cpp"
  "${PROJECT_SOURCE_DIR}/src/file_opener.cpp"
  "${PROJECT_SOURCE_DIR}/src/sender.cpp"
  "${PROJECT_SOURCE_DIR}/src/reciever.cpp"
)
#"${PROJECT_SOURCE_DIR}/lib/src/display.cpp"

target_include_directories(libProject_1 PUBLIC 
  "${PROJECT_SOURCE_DIR}"
  "${PROJECT_SOURCE_DIR}/inc"
)

add_executable(project1 main.cpp)
set(LIBS libProject_1)

target_link_libraries(${PROJECT_NAME} ${LIBS})
#target_link_libraries(Project_1 PRIVATE libProject_1 sfml-graphics sfml-audio sfml-system sfml-window)