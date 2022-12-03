# Spirit-Doxygen

Spirit-Doxygen allows fast integration of the Doxygen documentation tool
along with a better looking output thanks to doxygen-awesome-css.

Settings are aimed at C++ documentation generation and are not the default 
doxygen settings.

--------------------------------------------------------------------------------
## Installation

Add Spirit-Doxygen as a submodule and use it as a subdirectory from
your CmakeLists.txt

In your shell:
```sh
cd MyProject
git submodule add https://github.com/Matthieu-Beauchamp/Spirit-Doxgen libs/Spirit-Doxygen
git submodule update --init --recursive
```

--------------------------------------------------------------------------------
## Usage

MyProject/CmakeLists.txt
```cmake
set(SPIRIT_DOXYGEN_PROJECT_NAME MyProject)
set(SPIRIT_DOXYGEN_INPUT_DIR includeDirectory)
set(SPIRIT_DOXYGEN_OUTPUT_DIR )
add_subdirectory(libs/Spirit-Doxygen)
```

The input and output directories are relative to Spirit-Doxygen's root directory
if they are not absolute paths.
(On my Windows machine absolute paths are not interpreted correctly)

Spirit-Doxygen will create a CMake target with the provided name: <br>
`${SPIRIT_DOXYGEN_PROJECT_NAME}-docs`

It will also add a CMake option for building docs: <br>
`${SPIRIT_DOXYGEN_PROJECT_NAME}_BUILD_DOCS`

--------------------------------------------------------------------------------
