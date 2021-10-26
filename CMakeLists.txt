cmake_minimum_required(VERSION 3.12)

project(CBT)

add_subdirectory(FMath)

if (DEFINED VCPKG_TOOLCHAIN)
    set (VCPKG_TOOLCHAIN_SAVED ${VCPKG_TOOLCHAIN})
    unset(VCPKG_TOOLCHAIN)
endif()

if (DEFINED VCPKG_TOOLCHAIN_SAVED)
    set (VCPKG_TOOLCHAIN ${VCPKG_TOOLCHAIN_SAVED})
    unset(VCPKG_TOOLCHAIN_SAVED)
endif()

add_executable(CBT
    main.cpp

    CBT.h
    CBT.cpp
)

target_link_libraries(CBT
    FMath::FMath
)