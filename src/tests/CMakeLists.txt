# Test behavior with too many inputs
add_test(NAME TooManyInputs
         COMMAND ${CMAKE_BINARY_DIR}/best_season [1 1 1])

# Test behavior with wrong type of input
add_test(NAME WrongInputs
         COMMAND ${CMAKE_BINARY_DIR}/best_season [one])

# Indicate that tests should fail, give these inputs
set_tests_properties(TooManyInputs WrongInputs PROPERTIES WILL_FAIL TRUE)
