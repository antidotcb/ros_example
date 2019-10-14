project(${CATKIN_PACKAGE_NAME}_publisher_nodelet)

add_library(${PROJECT_NAME}
        include/nodelet.h
        src/nodelet.cpp
        )
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME publisher_nodelet PREFIX "")

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