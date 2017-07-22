file(GLOB DD_SRC  "*.c")
set(LIB_DD ${DD_SRC})
add_library(libdd ${LIB_DD})
set_target_properties(libdd PROPERTIES OUTPUT_NAME "dd")