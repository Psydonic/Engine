# Minimum CMake version required (min and max)
cmake_minimum_required(VERSION 3.10...3.31.5)

# Project name and type
project(engine LANGUAGES CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable generation of compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the engine library
add_library(engine)

# Set raylib version
set(RAYLIB_VERSION 5.5)

# Find and include raylib, or build it if not found
find_package(raylib ${RAYLIB_VERSION} )
if(NOT raylib_FOUND)
    message(STATUS "raylib not found, building from source...")
    include(FetchContent)

    Set(FETCHCONTENT_QUIET FALSE)
    FetchContent_Declare(
      raylib
      DOWNLOAD_EXTRACT_TIMESTAMP OFF
      URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if(NOT raylib_POPULATED)
      FetchContent_MakeAvailable(raylib)
      set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    endif()
endif()

# Web configuration
if(${PLATFORM} STREQUAL "Web")
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
endif()



# Include directories for the engine
# Assuming the engine's header files are in the 'include' folder
# Change this path if your headers are in a different location
target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files for the engine
# Assuming all source files are in the 'src' folder
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS "*.cpp")

# Add sources to the engine library
target_sources(engine PRIVATE ${ENGINE_SRC})

# Link raylib to the engine library
target_link_libraries(engine PUBLIC raylib)

# Optional: Add compile definitions or options if needed
# target_compile_definitions(engine PUBLIC MY_ENGINE_DEFINE)
target_compile_options(engine PRIVATE -Wall -Wextra)
# Build examples if BUILD_EXAMPLE is enabled

option(BUILD_EXAMPLE "Build example executables" ON)
if(BUILD_EXAMPLE)
    file(GLOB EXAMPLE_DIRS "examples/**")

    # Create an executable for each subdirectory
    foreach(DIR ${EXAMPLE_DIRS})
      get_filename_component(DIR_NAME ${DIR} NAME_WE)

        set(EXAMPLE_SOURCES
            "${DIR}/main.cpp"
        )

        add_executable(${DIR_NAME} ${EXAMPLE_SOURCES})
        target_link_libraries(${DIR_NAME} PUBLIC engine)
        target_compile_options(${DIR_NAME} PRIVATE -Wall -Wextra)

    endforeach()
    
endif()
