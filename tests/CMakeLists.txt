find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unit_tests test_main.cpp)
target_link_libraries(unit_tests
    PRIVATE
    core_lib
    GTest::GTest
    GTest::Main
)

add_test(NAME unit_tests COMMAND unit_tests)
