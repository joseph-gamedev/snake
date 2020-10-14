set(HEADER_FILES
	include/GameScene.h
	include/SnakeApplication.h)

set(SOURCE_FILES
	src/GameScene.cpp
	src/SnakeApplication.cpp)

set(EXTERNAL ${CMAKE_SOURCE_DIR}/extern)

set(SDL_LIBPATH ${EXTERNAL}/libsdl2/lib/x64)

add_executable(arcade ${SOURCE_FILES} ${HEADER_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/core/include)

target_link_libraries(arcade PUBLIC ${SDL_LIBPATH}/SDL2.lib
									core)


	