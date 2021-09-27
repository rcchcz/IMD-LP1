cmake_minimum_required(VERSION 3.5)
project (EBNF VERSION 1.0.0 LANGUAGES CXX )

#=== SETTING VARIABLES ===#
set( GCC_COMPILE_FLAGS "-Wall -pedantic" )
set( APP_NAME "tinyexp" )

#=== MAIN APP ===
include_directories( "core" )
add_executable( ${APP_NAME} "core/main.cpp"
                        "core/parser.cpp" )
target_compile_features( ${APP_NAME} PUBLIC cxx_std_17 )
