project(HelloBDD)

include_directories(${CUKE_INCLUDE_DIRS} src)

add_library(HelloBDD src/Hello)

if(GMOCK_FOUND)
    add_executable(HelloBDDSteps features/step_definitions/HelloBDDSteps)
    target_link_libraries(HelloBDDSteps HelloBDD ${CUKE_INCLUDES} ${CUKE_GTEST_LIBRARIES})
endif()