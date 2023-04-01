######################################################################
# CMakeLists.txt generated for component viterbi_decode
# Product type: static library
######################################################################
cmake_minimum_required(VERSION 3.12)
project(viterbi_decode)
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


######################################################################
## Path variables
######################################################################
get_filename_component(START_DIR . ABSOLUTE)

if(WIN32 AND NOT MINGW)
    set(SYSLIB_PREFIX "lib")
else()
    set(SYSLIB_PREFIX "")
endif()

######################################################################
## System libraries
######################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES}
    ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

######################################################################
## Target definition and commands
######################################################################
add_library(viterbi_decode STATIC ${START_DIR}/viterbi_decode_initialize.c
    ${START_DIR}/viterbi_decode_terminate.c
    ${START_DIR}/viterbi_decode.c
    ${START_DIR}/viterbi_decode_emxutil.c
    ${START_DIR}/viterbi_decode_emxAPI.c)
target_compile_features(viterbi_decode PUBLIC c_std_99)
target_compile_definitions(viterbi_decode PRIVATE -DMODEL=viterbi_decode)
target_link_libraries(viterbi_decode INTERFACE $<$<BOOL:${FOUND_LIBM}>:m>)


######################################################################
## Build success message
######################################################################
add_custom_command(TARGET viterbi_decode POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created library: $<TARGET_FILE:viterbi_decode>")

######################################################################
## Call toolchain hook function if defined
######################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(viterbi_decode)
endif()
