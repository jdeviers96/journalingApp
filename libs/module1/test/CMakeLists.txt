# Libraries definitions:
ADD_LIBRARY(E
  ${CMAKE_SOURCE_DIR}/libs/module1/src/entry.cpp
  )

ADD_LIBRARY(EEV
  ${CMAKE_SOURCE_DIR}/libs/module1/src/entry.cpp
  ${CMAKE_SOURCE_DIR}/libs/module1/src/entryvec.cpp
  )

ADD_LIBRARY(EEVTD
  ${CMAKE_SOURCE_DIR}/libs/module1/src/entry.cpp
  ${CMAKE_SOURCE_DIR}/libs/module1/src/entryvec.cpp
  ${CMAKE_SOURCE_DIR}/libs/module1/src/timedata.cpp
  )


# Tests executables compilation (target and files):
ADD_EXECUTABLE(t_loadLibs
  t_loadLibs.cpp
  )

ADD_EXECUTABLE(t_createEntryObj
  t_createEntryObj.cpp
  )

ADD_EXECUTABLE(t_createEntryVecObj
  t_createEntryVecObj.cpp
  )

ADD_EXECUTABLE(t_createTimeDataObj
  t_createTimeDataObj.cpp
  )
  

# Tests executables linking:
TARGET_LINK_LIBRARIES(t_loadLibs PRIVATE EEVTD)
TARGET_LINK_LIBRARIES(t_createEntryObj PRIVATE E)
TARGET_LINK_LIBRARIES(t_createEntryVecObj PRIVATE EEV)
TARGET_LINK_LIBRARIES(t_createTimeDataObj PRIVATE EEVTD)


# Tests commands:
ADD_TEST(
  NAME t_loadLibs
  COMMAND $<TARGET_FILE:t_loadLibs>
)

ADD_TEST(
  NAME t_createEntryObj
  COMMAND $<TARGET_FILE:t_createEntryObj>
)

ADD_TEST(
  NAME t_createEntryVecObj
  COMMAND $<TARGET_FILE:t_createEntryVecObj>
)

ADD_TEST(
  NAME t_createTimeDataObj
  COMMAND $<TARGET_FILE:t_createTimeDataObj>
)
