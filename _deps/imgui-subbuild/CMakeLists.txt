# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.16.3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(imgui-populate NONE)

include(ExternalProject)
ExternalProject_Add(imgui-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/ocornut/imgui" "GIT_TAG" "719d9313041b85227a3e6deb289a313819aaeab3"
                    SOURCE_DIR          "/home/raf/Desktop/path-finding-visualizer/_deps/imgui-src"
                    BINARY_DIR          "/home/raf/Desktop/path-finding-visualizer/_deps/imgui-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
