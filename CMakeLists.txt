set(SOURCE src/main.c src/menu.h src/menu.c src/Map.h src/Map.c src/potion.c src/potion.h)
set(PROJECT_NAME project)

cmake_minimum_required(VERSION 3.12)

project(${PROJECT_NAME} C)

set(CMAKE_C_STANDARD 99)

set(SDL2_GFX_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/sdl2/sdl2-gfx-include")
set(SDL2_GFX_LIB_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/sdl2/sdl2-gfx-lib")
set(SDL2_INCLUDE_DIR     "${CMAKE_CURRENT_SOURCE_DIR}/sdl2/sdl2-include")
set(SDL2_LIB_DIR         "${CMAKE_CURRENT_SOURCE_DIR}/sdl2/sdl2-lib")
set(SDL2_FLAGS           "-mwindows -Wl,--no-undefined -static-libgcc")
add_library(SDL2     STATIC IMPORTED)
add_library(SDL2main STATIC IMPORTED)
add_library(SDL2_GFX STATIC IMPORTED)
set_property(TARGET SDL2     PROPERTY IMPORTED_LOCATION "${SDL2_LIB_DIR}/libSDL2.a")
set_property(TARGET SDL2main PROPERTY IMPORTED_LOCATION "${SDL2_LIB_DIR}/libSDL2main.a")
set_property(TARGET SDL2_GFX PROPERTY IMPORTED_LOCATION "${SDL2_GFX_LIB_DIR}/libsdl-gfx.a")
set(SDL2_LIBS SDL2 SDL2main SDL2_GFX m dinput8 dxguid dxerr8 user32 gdi32 winmm imm32 ole32 oleaut32 shell32 version uuid)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${SDL2_FLAGS}")

file(GLOB_RECURSE SOURCE "src/*.c" "src/*.h")
add_executable("${PROJECT_NAME}" "${SOURCE}")
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_GFX_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBS})
