# Spirit-Doxygen

Spirit-Doxygen allows fast integration of the Doxygen documentation tool
along with a better looking output thanks to doxygen-awesome-css.

--------------------------------------------------------------------------------
## Integration

Add Spirit-Doxygen as a submodule and use it as a subdirectory from
your CmakeLists.txt

```
$ cd MyProject
$ git submodule add https://github.com/Matthieu-Beauchamp/Spirit-Doxgen libs/Spirit-Doxygen
$ git submodule update --init --recursive
```

MyProject/CmakeLists.txt
```
add_subdirectory(libs/Spirit-Doxygen)
```

Spirit-Doxygen will create a CMake target with the name and version of your project
provided by CMake: <br>
`[NAME]-[VERSION (optional)]-docs`

It will also add a CMake option for building docs: <br>
`[NAME]_BUILD_DOCS`

--------------------------------------------------------------------------------
## Parameters

You must define those before calling add_subdirectory: <br>
Input directory (recursive) for doxygen is set to `${SPIRIT_DOXYGEN_INPUT_DIR}` <br>
Output will be placed in `${SPIRIT_DOXYGEN_OUTPUT_DIR}` <br>

Those paths will be relative to *this* directory, absolute paths are recommended.
