ADD_EXECUTABLE(journalApp
  src/entry.cpp
  src/timedata.cpp
  src/main.cpp
  )

TARGET_INCLUDE_DIRECTORIES(journalApp
  PUBLIC
    include
  )

ADD_SUBDIRECTORY(test)

# Create the dir to store logfiles
INSTALL(DIRECTORY DESTINATION ${LGF_PATH})

# Install the bin
INSTALL(
  TARGETS journalApp
  RUNTIME
  DESTINATION ${CMAKE_SOURCE_DIR}/bin
  )

