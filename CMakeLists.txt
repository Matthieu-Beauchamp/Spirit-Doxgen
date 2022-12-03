set(PARENT_PROJECT ${CMAKE_PROJECT_NAME})
set(PARENT_VERSION ${CMAKE_PROJECT_VERSION})

set(DOC_NAME "${PARENT_PROJECT}-${PARENT_VERSION}")

# adapted from: https://stackoverflow.com/q/34878276

find_package(Doxygen)

option("${PARENT_PROJECT}_BUILD_DOCS" 
    "Build the ${PARENT_PROJECT}'s documentation(requires Doxygen)"
    ${DOXYGEN_FOUND}
    )

if(${SPIRIT_BUILD_DOCS})
    if(NOT ${DOXYGEN_FOUND})
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    message("-- Configuring Doxygen documentation generation for ${DOC_NAME}")

    # Input is set as ../include
    # Output will be in ./docs

    # TODO: Could allow specifying include root using @include = configFile
    #   where configFile would be generated right before calling doxygen
    #   and would only contain INPUT=${INCLUDE_DIR}
    # Also could be useful for output dir

    set(doxyfile ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)

    add_custom_target("${DOC_NAME}"
                      COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
                      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                      COMMENT "Generating API documentation with Doxygen"
                      VERBATIM)
endif()