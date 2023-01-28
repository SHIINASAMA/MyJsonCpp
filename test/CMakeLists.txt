enable_testing()

add_executable(Test1 Test1.cpp)
target_link_libraries(Test1 libjson)

add_executable(Test2 Test2.cpp)
target_link_libraries(Test2 libjson)