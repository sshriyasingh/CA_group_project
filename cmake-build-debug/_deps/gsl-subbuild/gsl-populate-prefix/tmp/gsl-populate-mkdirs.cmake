# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/sanjana/CA_group_project/cmake-build-debug/_deps/gsl-src"
  "/Users/sanjana/CA_group_project/cmake-build-debug/_deps/gsl-build"
  "/Users/sanjana/CA_group_project/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix"
  "/Users/sanjana/CA_group_project/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/tmp"
  "/Users/sanjana/CA_group_project/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp"
  "/Users/sanjana/CA_group_project/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/src"
  "/Users/sanjana/CA_group_project/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/sanjana/CA_group_project/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/sanjana/CA_group_project/cmake-build-debug/_deps/gsl-subbuild/gsl-populate-prefix/src/gsl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
