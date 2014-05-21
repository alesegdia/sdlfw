set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

# SET SOURCES AND STUFF
file(GLOB_RECURSE CORE_SRC core/*)
file(GLOB_RECURSE FROG_SRC games/frog/*)
file(GLOB_RECURSE TORTAS_SRC games/tortas/*)
file(GLOB_RECURSE BOXEDIT_SRC tools/boxedit/*)

# FIND LIBRARIES
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# NAME THE TARGETS
add_executable(tortas ${CORE_SRC} ${TORTAS_SRC})
add_executable(frog ${CORE_SRC} ${FROG_SRC})
add_executable(boxedit ${CORE_SRC} ${BOXEDIT_SRC})

if(SDL2_FOUND AND SDL2IMAGE_FOUND)
	include_directories(${SDL2_INCLUDE_DIR})
	include_directories(${SDL2IMAGE_INCLUDE_DIR})

	# GAMES
	target_link_libraries(tortas ${SDL2_LIBRARY})
	target_link_libraries(tortas ${SDL2IMAGE_LIBRARY})
	target_link_libraries(frog ${SDL2_LIBRARY})
	target_link_libraries(frog ${SDL2IMAGE_LIBRARY})

	# TOOLS
	target_link_libraries(boxedit ${SDL2_LIBRARY})
	target_link_libraries(boxedit ${SDL2IMAGE_LIBRARY})
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY})

