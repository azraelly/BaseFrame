SET(LIBBASEFRAME_SRC Exception.cpp)
ADD_LIBRARY(BaseFrame SHARED ${LIBHELLO_SRC})
ADD_LIBRARY(BaseFrame_static STATIC ${LIBHELLO_SRC})
SET_TARGET_PROPERTIES(BaseFrame_static PROPERTIES OUTPUT_NAME "BaseFrame")
GET_TARGET_PROPERTY(OUTPUT_VALUE BaseFrame_static OUTPUT_NAME)
MESSAGE(STATUS ��This is the hello_static
OUTPUT_NAME:��${OUTPUT_VALUE})

SET_TARGET_PROPERTIES( BaseFrame PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES( BaseFrame_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

SET_TARGET_PROPERTIES( BaseFrame PROPERTIES VERSION 1.2 SOVERSION 1)

INSTALL(TARGETS BaseFrame BaseFrame_static
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib)

#INSTALL(FILES hello.h DESTINATION include/hello)