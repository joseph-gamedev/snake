file (GLOB SDL2_HEADER_FILES
include/*.h
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SDL2_HEADER_FILES})

include_directories(${SDL2_HEADER_FILES})
