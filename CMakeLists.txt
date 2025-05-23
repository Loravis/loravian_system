	# Minimum CMake version required, we'll just use the latest version.
	cmake_minimum_required(VERSION 3.22)
	# Project name, version and description
	project(loravian-system VERSION 1.0 DESCRIPTION "Loravian automation")

	find_package(SQLite3 REQUIRED)
	 
	list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
	 
	file(GLOB SOURCES
		src/cmd/*.cpp
		src/db/*.cpp
		headers/*.h
	)

	# Create an executable
	add_executable(${PROJECT_NAME}
	    src/main.cpp
			${SOURCES}
	)
	 
	# Find our pre-installed DPP package (using FindDPP.cmake).
	find_package(DPP REQUIRED)
	 
	# Link the pre-installed DPP package.
	target_link_libraries(${PROJECT_NAME} 
	    ${DPP_LIBRARIES}
			SQLite::SQLite3
	)
	 
	# Include the DPP directories.
	target_include_directories(${PROJECT_NAME} PRIVATE
	    ${DPP_INCLUDE_DIR}
	)
	 
	# Set C++ version
	set_target_properties(${PROJECT_NAME} PROPERTIES
	    CXX_STANDARD 20
	    CXX_STANDARD_REQUIRED ON
	)