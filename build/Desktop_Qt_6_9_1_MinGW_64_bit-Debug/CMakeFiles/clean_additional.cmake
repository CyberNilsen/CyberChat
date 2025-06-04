# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CyberChat_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CyberChat_autogen.dir\\ParseCache.txt"
  "CyberChat_autogen"
  )
endif()
