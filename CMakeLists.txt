cmake_minimum_required(VERSION 3.10)

project(clip
				VERSION 0.1
				LANGUAGES C)

# Set C standard and warning level equivalent to Meson's warning_level=3
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add compiler warnings (equivalent to Meson's warning_level=3)
if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W3")
endif()

# Create the executable
add_executable(clip src/main.c)

# Install the executable to bin directory
install(TARGETS clip
				RUNTIME DESTINATION bin)
