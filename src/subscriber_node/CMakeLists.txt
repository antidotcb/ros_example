project(${CATKIN_PACKAGE_NAME}_subscriber_node)

add_executable(${PROJECT_NAME}
        include/TalkerSubscriber.h
        src/main.cpp
        src/TalkerSubscriber.cpp
        )
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME subscriber_node PREFIX "")

target_include_directories(${PROJECT_NAME}
        SYSTEM BEFORE PUBLIC ${catkin_INCLUDE_DIRS}
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC $<INSTALL_INTERFACE:include> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

target_link_libraries(${PROJECT_NAME}
        ${catkin_LIBRARIES}
        ${CATKIN_PACKAGE_NAME}_lib
        )