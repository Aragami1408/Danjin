if(WIN32)
  add_compile_definitions(DANJIN_PLATFORM_WINDOWS)
  remove_definitions("-DDANJIN_BUILD_DLL")
endif(WIN32)

function(add_example EXAMPLE_NAME)
	add_executable(${EXAMPLE_NAME} ${ARGN})
	target_link_libraries(${EXAMPLE_NAME} PRIVATE Danjin)
    #file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endfunction()

add_example(Danjin ExampleApp.cpp)
