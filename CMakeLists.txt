cmake_minimum_required(VERSION 3.23)

set(PRJ_NAME "cpp_calculator")
project(${PRJ_NAME})

get_filename_component(THIS_DIR ./ ABSOLUTE)
set(OUT_DIR "${THIS_DIR}/bin/$<CONFIG>")

add_executable(${PRJ_NAME})
target_compile_features(${PRJ_NAME} PUBLIC cxx_std_20)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

set_target_properties(${PRJ_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR}
)

target_compile_definitions(${PRJ_NAME}
	PUBLIC
		$<$<CONFIG:Debug>:CALC_DEBUG>
		$<$<CONFIG:Debug>:CALC_ASSERTS>
		PLATFORM_WIN32
)

#START of linking - FMT
target_include_directories(${PRJ_NAME} SYSTEM PUBLIC "${THIS_DIR}/Vendors/fmt/include")
add_subdirectory("${THIS_DIR}/Vendors/fmt" "${THIS_DIR}/bin/Vendors/fmt")
target_link_libraries(${PRJ_NAME} PUBLIC fmt)
#END of linking - FMT

#START of linking - GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

target_include_directories(${PRJ_NAME} SYSTEM PUBLIC "${THIS_DIR}/Vendors/glfw/include")
add_subdirectory("${THIS_DIR}/Vendors/glfw" "${THIS_DIR}/bin/Vendors/GLFW")
target_link_libraries(${PRJ_NAME} PUBLIC glfw)
#END linking - GLFW

target_include_directories(${PRJ_NAME} PUBLIC "${THIS_DIR}/Source")
add_subdirectory("Source")