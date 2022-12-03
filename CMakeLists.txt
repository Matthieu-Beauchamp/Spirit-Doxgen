cmake_minimum_required(VERSION 3.0)
project("Documentation")

message("-- Configuring Doxygen documentation generation for ${SPIRIT_DOXYGEN_PARENT_PROJECT}")

# Check Parent exists
if ("${SPIRIT_DOXYGEN_PARENT_PROJECT}" STREQUAL "")
    message(SEND_ERROR "No parent project name to generate documentation")
    return()
endif()

if (NOT EXISTS ${SPIRIT_DOXYGEN_INPUT_DIR})
    message(SEND_ERROR "No input directory found, ${SPIRIT_DOXYGEN_INPUT_DIR} does not exist")
    return()
endif()


# adapted from: https://stackoverflow.com/q/34878276
find_package(Doxygen)

option("${SPIRIT_DOXYGEN_PARENT_PROJECT}_BUILD_DOCS" 
    "Build the ${SPIRIT_DOXYGEN_PARENT_PROJECT}'s documentation(requires Doxygen)"
    ${DOXYGEN_FOUND}
)

if(${${SPIRIT_DOXYGEN_PARENT_PROJECT}_BUILD_DOCS})
    if(NOT ${DOXYGEN_FOUND})
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    # Input dir for doxygen is set to ${SPIRIT_DOXYGEN_INPUT_DIR}
    # Output will be placed in ${SPIRIT_DOXYGEN_OUTPUT_DIR}
    # Those paths will be relative to *this* directory, 
    #   Absolute paths are recommended
    # Project name will also be set to ${SPIRIT_DOXYGEN_PARENT_PROJECT}

    configure_file(Doxyfile.base ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile @ONLY)

    add_custom_target("${SPIRIT_DOXYGEN_PARENT_PROJECT}-docs"
        COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating ${SPIRIT_DOXYGEN_PARENT_PROJECT} documentation with Doxygen"
        VERBATIM
    )
endif()