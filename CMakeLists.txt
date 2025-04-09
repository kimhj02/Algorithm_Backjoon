cmake_minimum_required(VERSION 3.22)
project(Algorithm_Backjoon)

set(CMAKE_CXX_STANDARD 17)

# 현재 디렉토리의 모든 .cpp 파일을 SOURCES에 포함
file(GLOB SOURCES "*.cpp")

# 각 .cpp 파일마다 실행 파일 생성
foreach(src ${SOURCES})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})  # <-- 수정
endforeach()