cmake_minimum_required(VERSION 3.5.0)
project(sb VERSION 0.1.0 LANGUAGES C CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB SOURCES "src/*.cpp")

add_executable(sb ${SOURCES})
target_include_directories(sb PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(sb GTest::gtest_main)
enable_testing()

include(GoogleTest)

