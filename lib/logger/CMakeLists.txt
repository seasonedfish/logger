# --------------------------------
# Create the logger static library
# --------------------------------
# https://gitlab.com/CLIUtils/modern-cmake/tree/master/examples/extended-project

add_library(logger ${logger_SOURCE_DIR}/include/logger/Logger.h ${logger_SOURCE_DIR}/lib/logger/Logger.cpp)
target_include_directories(logger PUBLIC ${logger_SOURCE_DIR}/include)
target_compile_features(logger PUBLIC cxx_std_14)
