# --------------------------------
# Create the logger static library
# --------------------------------
# https://gitlab.com/CLIUtils/modern-cmake/tree/master/examples/extended-project
file(GLOB headers "${logger_SOURCE_DIR}/include/logger/*.h")
file(GLOB sources "${logger_SOURCE_DIR}/lib/logger/*.cpp")

add_library(logger ${headers} ${sources})
target_include_directories(logger PUBLIC ${logger_SOURCE_DIR}/include)
target_compile_features(logger PUBLIC cxx_std_14)
