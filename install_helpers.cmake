
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-function -Werror-implicit-function-declaration -Wno-missing-field-initializers ${CMAKE_CXX_FLAGS} -fno-strict-aliasing")
    set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-unused-function -Werror-implicit-function-declaration -Wno-missing-braces -Wno-missing-field-initializers ${CMAKE_C_FLAGS} -std=gnu99 -fno-strict-aliasing")

    option(USE_LIBC++ "Use libc++ instead of libstdc++" ${APPLE})
    if(USE_LIBC++)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    endif()
elseif(MSVC)
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()

    # Disable pointless constant condition warnings
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4127 /wd4201")
endif()

set(INSTALL_DIRS ${CMAKE_BINARY_DIR} CACHE FILEPATH "install dirs are now set " FORCE)
option(TEST_OPTION "test option var -> " FALSE)


function(install_lib_core target)
    message("add lib target "
            ${target}
            ${INSTALL_DIRS}
            )

#    if(APPLE)
#        set(_bit_suffix "")
#    elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
#        set(_bit_suffix "64bit/")
#    else()
#        set(_bit_suffix "32bit/")
#    endif()
#
    if("${ARGV1}" STREQUAL "EXPORT")
#        export_obs_core("${target}" "${ARGV2}")
    else()
        install(TARGETS ${target}
                LIBRARY DESTINATION "${INSTALL_DIRS}"
                RUNTIME DESTINATION "${INSTALL_DIRS}")
    endif()
#
    add_custom_command(TARGET ${target} POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy
            "$<TARGET_FILE:${target}>"
            "${CMAKE_BINARY_DIR}/$<TARGET_FILE_NAME:${target}>"
            VERBATIM)
    message("debugg ${CMAKE_BINARY_DIR}/$<TARGET_FILE_NAME:${target}>")
#
#    if(DEFINED ENV{obsInstallerTempDir})
#        get_property(target_type TARGET ${target} PROPERTY TYPE)
#        if("${target_type}" STREQUAL "EXECUTABLE")
#            set(tmp_target_dir "${OBS_EXECUTABLE_DESTINATION}")
#        else()
#            set(tmp_target_dir "${OBS_LIBRARY_DESTINATION}")
#        endif()
#
#        add_custom_command(TARGET ${target} POST_BUILD
#                COMMAND "${CMAKE_COMMAND}" -E copy
#                "$<TARGET_FILE:${target}>"
#                "$ENV{obsInstallerTempDir}/${tmp_target_dir}/$<TARGET_FILE_NAME:${target}>"
#                VERBATIM)
#    endif()

    #	install_obs_pdb(CORE ${target})
endfunction()
