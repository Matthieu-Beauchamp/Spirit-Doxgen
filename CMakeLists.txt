cmake_minimum_required(VERSION 3.0)

set(PARENT_PROJECT ${CMAKE_PROJECT_NAME})
set(PARENT_VERSION ${CMAKE_PROJECT_VERSION})

if ("${PARENT_VERSION}" STREQUAL "")
    set(DOC_NAME "${PARENT_PROJECT}")
else()
    set(DOC_NAME "${PARENT_PROJECT}-${PARENT_VERSION}")
endif()

project("Docs")

message("-- Configuring Doxygen documentation generation for ${DOC_NAME}")

# Check Parent exists
if ("${PARENT_PROJECT}" STREQUAL "")
    message(SEND_ERROR "No parent project to generate documentation")
    return()
endif()

if (NOT EXISTS ${SPIRIT_DOXYGEN_INPUT_DIR})
    message(SEND_ERROR "No input directory found, ${INPUT_DIR} does not exist")
    return()
endif()


# adapted from: https://stackoverflow.com/q/34878276
find_package(Doxygen)

option("${PARENT_PROJECT}_BUILD_DOCS" 
    "Build the ${PARENT_PROJECT}'s documentation(requires Doxygen)"
    ${DOXYGEN_FOUND}
    )

if(${${PARENT_PROJECT}_BUILD_DOCS})
    if(NOT ${DOXYGEN_FOUND})
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    # Input dir for doxygen is set to ${SPIRIT_DOXYGEN_INPUT_DIR}
    # Output will be placed in ${SPIRIT_DOXYGEN_OUTPUT_DIR}
    # Project name will also be set
    # Those paths will be relative to *this* directory, 
    #   Absolute paths are recommended

    configure_file(Doxyfile.base ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile @ONLY)

    add_custom_target("${DOC_NAME}-docs"
                      COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
                      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                      COMMENT "Generating ${DOC_NAME} documentation with Doxygen"
                      VERBATIM)
endif()