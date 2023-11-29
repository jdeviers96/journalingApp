CMAKE_MINIMUM_REQUIRED(VERSION 3.21 FATAL_ERROR)

SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_POLICY_DEFAULT_CMP0126 ON) # Ensures cache variables (passed with -D) and normal variables interact correctly.

PROJECT(journalingApp
  VERSION 0.0.1
  DESCRIPTION "A simple timecoded-note-taking app."
  LANGUAGES CXX
  )

INCLUDE(CTest)

SET(INCLPATH "${CMAKE_SOURCE_DIR}/libs/module1/include")
SET(SRCSPATH "${CMAKE_SOURCE_DIR}/libs/module1/src")

IF(NOT DEFINED LGF_PATH)
  SET(LGF_PATH "/home/jean/.local/logs")
ENDIF(NOT DEFINED LGF_PATH)

# Whether set via -DLGF_PATH=... or the above IF(...) block:
MESSAGE(STATUS "Logfiles stored in ${LGF_PATH}")


# *.h.in contains the CMake variables to replace
# (via preprocessor directive) inside globalVars.h
CONFIGURE_FILE(
  ${INCLPATH}/globalVars.h.in 
  ${INCLPATH}/globalVars.h
  )

INCLUDE_DIRECTORIES(${INCLPATH})
ADD_SUBDIRECTORY(libs/module1)
