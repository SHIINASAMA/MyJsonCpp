add_library(libjson STATIC)

target_include_directories(
        libjson
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_sources(
        libjson
        PRIVATE
            include/json/Type.h
            include/json/Util.h
        PUBLIC
            src/Util.cpp
)