# Test behavior with too many inputs
add_test(NAME TooManyInputs
         COMMAND ${CMAKE_BINARY_DIR}/best_season 1 1 2021-2022 1)

# Test behavior with wrong type of input
add_test(NAME WrongInputs
         COMMAND ${CMAKE_BINARY_DIR}/best_season one)

# Test behavior with unavailable season
add_test(NAME WrongSeason
         COMMAND ${CMAKE_BINARY_DIR}/best_season 2 2 2019-20)

 # Test behavior with normal inputs
add_test(NAME NormalInputs
         COMMAND ${CMAKE_BINARY_DIR}/best_season 2 2 2020)

# Test behavior with no inputs
add_test(NAME NoInputs
         COMMAND ${CMAKE_BINARY_DIR}/best_season)

# Indicate that tests should fail, give these inputs
set_tests_properties(TooManyInputs WrongInputs WrongSeason
         PROPERTIES WILL_FAIL TRUE)
