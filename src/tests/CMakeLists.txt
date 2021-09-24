# Test behavior with too many inputs
add_test(NAME "Too Many Inputs"
         COMMAND "${CMAKE_BINARY_DIR}/best_season 0 0 0"
         --target WILL_FAIL)

# Test behavior with wrong type of input
