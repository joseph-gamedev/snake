set(HEADER_FILES 
	include/Application.h
	include/ApplicationBase.h
	include/ArcadeCore.h
	include/Board.h
	include/Color.h
	include/gui/Widget.h
	include/gui/WidgetContainer.h
	include/gui/WidgetManager.h
	include/SDLInput.h
	include/SDLView.h
	include/SDLRenderer.h
	include/SDLPainter.h
	include/SDLPrimitives.h
	include/IInput.h
	include/imgui_sdl.h
	include/imgui_impl_sdl.h
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
	src/gui/WidgetContainer.cpp
	src/gui/WidgetManager.cpp
	src/SDLInput.cpp
	src/SDLPainter.cpp
	src/SDLPrimitives.cpp
	src/SDLRenderer.cpp
	src/SDLView.cpp
	src/imgui_sdl.cpp
	src/imgui_impl_sdl
	src/Vector2.cpp
	PlatformEntry.cpp)

set(EXTERNAL ${CMAKE_SOURCE_DIR}/extern)

add_library(core STATIC ${SOUCRCE_FILES} ${HEADER_FILES})

target_precompile_headers(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/pch.h)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(core PUBLIC ${EXTERNAL}/libsdl2/include)
target_include_directories(core PUBLIC ${EXTERNAL}/imgui)

