cmake_minimum_required(VERSION 3.15)
project(client)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")


include_directories(.)
include_directories(../include)
include_directories(../include/Imagine_Muduo)

add_executable(test_client
   test_client.cpp
)



link_directories(
   imagine_muduo
    ../lib
)

link_directories(
   imagine_time
    ../lib
)
link_directories(
   imagine_log
    ../lib
)
link_directories(
   imagine_tool
    ../lib
)
link_directories(
   imagine_tool_thirdparty
    ../lib
)
set(LIBS
imagine_muduo
imagine_time
imagine_log
imagine_tool
imagine_tool_thirdparty
)
add_executable(test_server
   test_server.cpp ${LIB}
)
target_link_libraries(test_server imagine_muduo ${LIBS})
target_include_directories(test_server PUBLIC ../include/Imagine_Muduo)

# find fmt and link it.
# find_package(fmt REQUIRED)
# target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE fmt::fmt)
# target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
#    src
# )


