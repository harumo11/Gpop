cmake_minimum_required(VERSION 3.5)

set(SRC_DIR src)
set(INCLUDE_DIR ./include/gpop)
include_directories(${INCLUDE_DIR})

add_library(gpop ${SRC_DIR}/Bar.cpp
	               ${SRC_DIR}/Gnuplot.cpp
				   ${SRC_DIR}/Pie.cpp
				   ${SRC_DIR}/Series.cpp
				   ${SRC_DIR}/Vector.cpp
				   ${SRC_DIR}/Hist.cpp
				   )

install(TARGETS gpop
	    RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib
		)

install(
		DIRECTORY include/gpop
		DESTINATION /usr/local/include
		)
