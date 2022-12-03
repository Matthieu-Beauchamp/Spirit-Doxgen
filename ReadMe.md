# Spirit-Doxygen

Spirit-Doxygen allows fast integration of the Doxygen documentation tool
along with a better looking output thanks to doxygen-awesome-css.

Add Spirit-Doxygen as a top level submodule and use it as a subdirectory from
your CmakeLists.txt

You must define those before calling add_subdirectory:
Input directory (recursive) for doxygen is set to ${SPIRIT_DOXYGEN_INPUT_DIR} <br>
Output will be placed in ${SPIRIT_DOXYGEN_OUTPUT_DIR} <br>

Those paths will be relative to *this* directory, absolute paths are recommended.


Spirit-Doxygen will create a CMake target with the name and version of your project
provided by CMake: <br>
[NAME]-[VERSION (optional)]-docs

It will also add a CMake option for building docs: <br>
[NAME]_BUILD_DOCS    
