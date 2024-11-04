# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/sanjana/CA_group_project/build/_deps/gsl-src")
  file(MAKE_DIRECTORY "/Users/sanjana/CA_group_project/build/_deps/gsl-src")
endif()
file(MAKE_DIRECTORY
  "/Users/sanjana/CA_group_project/build/_deps/gsl-build"
  "/Users/sanjana/CA_group_project/build/_deps/gsl-subbuild/gsl-populate-prefix"
  "/Users/sanjana/CA_group_project/build/_deps/gsl-subbuild/gsl-populate-prefix/tmp"
  "/Users/sanjana/CA_group_project/build/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp"
  "/Users/sanjana/CA_group_project/build/_deps/gsl-subbuild/gsl-populate-prefix/src"
  "/Users/sanjana/CA_group_project/build/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/sanjana/CA_group_project/build/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/sanjana/CA_group_project/build/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
