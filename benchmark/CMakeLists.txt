
include_directories(${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/CToolbox/Modules
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/fi_lib
        ${CMAKE_SOURCE_DIR}/src/rts)

link_directories(
  ${CMAKE_SOURCE_DIR/src}
)

add_executable(benchmark benchmark.cpp)

target_link_libraries(benchmark cxsc)
