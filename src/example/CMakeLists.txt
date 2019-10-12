project(${CATKIN_PACKAGE_NAME}_lib)

add_library(${PROJECT_NAME}
        include/Node.h
        include/ProgramArguments.h
        include/Publisher.h
        src/Node.cpp
        src/ProgramArguments.cpp
        include/Listener.cpp include/Subscriber.h)

target_include_directories(${PROJECT_NAME}
        SYSTEM BEFORE PUBLIC ${catkin_INCLUDE_DIRS}
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC $<INSTALL_INTERFACE:include> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

target_link_libraries(${PROJECT_NAME}
        ${catkin_LIBRARIES}
        )