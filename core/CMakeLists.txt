set(HEADER_FILES 
	include/Application.h
	include/ApplicationBase.h
	include/ArcadeCore.h
	include/Board.h
	include/Color.h
	include/SDLView.h
	include/SDLRenderer.h
	include/SDLPainter.h
	include/ILifeCycle.h
	include/IPainter.h
	include/IRenderer.h
	include/IView.h
	include/NonCopyable.h
	include/Vector2.h)

set(SOUCRCE_FILES 
	src/Application.cpp
	src/ApplicationBase.cpp
	src/Board.cpp
	src/SDLPainter.cpp
	src/SDLRenderer.cpp
	src/SDLView.cpp
	src/Vector2.cpp
	PlatformEntry.cpp)

set(EXTERNAL ${CMAKE_SOURCE_DIR}/extern)

add_library(core STATIC ${SOUCRCE_FILES} ${HEADER_FILES})

target_precompile_headers(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pch.h)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(core PUBLIC ${EXTERNAL}/libsdl2/include)
