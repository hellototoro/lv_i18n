cmake_minimum_required(VERSION 3.12.4)

project(lv_i18n)

file(GLOB_RECURSE SOURCES ./src/*.c)

add_library(lv_i18n STATIC ${SOURCES})
