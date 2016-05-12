################################################
#
#
# 	Third paty projects
#
#
#################################################

#######
# Paths
#
get_filename_component(THIRD_FIRST_REL ${THIRD_FIRST_SRC} REALPATH)

#find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
#include(ExternalProject)

# Download and install GoogleTest
# ExternalProject_Add(
	# first
	# #URL https://github.com/Nedja995/cpp-library-template/archive/master.zip
	# SOURCE_DIR D:/Projects/projectsProject/first-lib #${THIRD_FIRST}
	# PREFIX ${CMAKE_CURRENT_BINARY_DIR}/thirdparty/first
	# #Disable install step
	# INSTALL_COMMAND ""
# )

# Set gtest properties
# ExternalProject_Get_Property(first source_dir binary_dir)
# set_target_properties(first properties
	# "imported_location" "${binary_dir}/first.a"
	# "imported_link_interface_libraries" "${cmake_thread_libs_init}"
   # "interface_include_directories" "${source_dir}/include"
# )

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
#include_directories("${source_dir}/include")

#include_directories(first ${source_dir}/include)

#
# Add extern project for dev
#
# Second argument need when extern project is out of source tree directory
ADD_SUBDIRECTORY(${THIRD_FIRST_REL} "${CMAKE_CURRENT_BINARY_DIR}/first")





#TARGET_LINK_LIBRARIES(NameCppProjectTemplate ${CMAKE_CURRENT_BINARY_DIR}/gmock/src/gmock-build/${CMAKE_CFG_INTDIR}/gmock.lib)























#target_link_libraries(first ${LIBRARY_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}/first.lib)