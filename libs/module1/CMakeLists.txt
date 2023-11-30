FIND_PACKAGE(Boost 
  COMPONENTS program_options REQUIRED)

ADD_EXECUTABLE(journalApp
  src/entry.cpp
  src/entryvec.cpp
  src/timedata.cpp
  src/main.cpp
  )

TARGET_INCLUDE_DIRECTORIES(journalApp
  PUBLIC
    include
  )

TARGET_LINK_LIBRARIES(journalApp Boost::program_options)

ADD_SUBDIRECTORY(test)

# Create the dir to store logfiles
INSTALL(DIRECTORY DESTINATION ${LGF_PATH})

# Install the bin
INSTALL(
  TARGETS journalApp
  RUNTIME
  DESTINATION bin
  )

