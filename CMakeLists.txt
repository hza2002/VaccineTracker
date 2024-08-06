cmake_minimum_required(VERSION 3.28)
project(VaccineTracker)

set(CMAKE_C_STANDARD 11) # 设置 C 标准

include_directories("include")

file(GLOB MAIN_SOURCE_FILES "src/main/*.c")
file(GLOB GENERATOR_SOURCE_FILES "src/generator/*.c")
file(GLOB SHARED_SOURCE_FILES "src/shared/*.c")

add_executable(VaccineTracker
        ${MAIN_SOURCE_FILES}
        ${SHARED_SOURCE_FILES}
)

add_executable(Generator
        ${GENERATOR_SOURCE_FILES}
        ${SHARED_SOURCE_FILES}
)
