cmake_minimum_required(VERSION 3.2)
project (KenoGame VERSION 1.0.0 LANGUAGES CXX )

#=== Main App ===

include_directories( "core" )

add_executable( keno
                core/main.cpp
                core/keno_game.cpp
                core/keno_bet.cpp )

target_compile_features( keno PUBLIC cxx_std_17 )
