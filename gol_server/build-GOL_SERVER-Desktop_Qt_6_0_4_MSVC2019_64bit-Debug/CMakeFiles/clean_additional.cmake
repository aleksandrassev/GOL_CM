# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GOL_SERV_CM_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GOL_SERV_CM_autogen.dir\\ParseCache.txt"
  "GOL_SERV_CM_autogen"
  )
endif()
