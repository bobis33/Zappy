#!/bin/bash

function clean() {
    if [ -d "build" ]; then
        rm -rf build/*
        echo "build directory has been removed."
    else
        echo "build directory does not exist."
    fi
    if [ -d ".doxygen" ]; then
        rm -rf .doxygen/*
        echo ".doxygen directory has been removed."
    else
        echo ".doxygen directory does not exist."
    fi
    if [ -d "cmake-build-debug" ]; then
        rm -rf cmake-build-debug/*
        echo "cmake-build-debug directory has been removed."
    else
        echo "doc directory does not exist."
    fi
    if [ -f "zappy_server" ]; then
        rm zappy_server
        echo "zappy_server binary has been removed."
    else
        echo "zappy_server binary does not exist."
    fi
}

function build() {
    debug=$1
    if [ ! -d "build" ]; then
        mkdir -p build
    fi
    cd build || exit 1
    if [ "$debug" == "true" ]; then
        cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DUSE_CLANG_TIDY=ON && cmake --build .
    else
        cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release && cmake --build .
    fi
}

if [ $# -eq 0 ]; then
    echo "Usage $0 build [debug] | clean"
    exit 1
fi

case $1 in
    build)
        if [ "$2" == "debug" ]; then
            build true
        else
            build false
        fi
        ;;
    clean)
        clean
        ;;
    *)
        echo "Usage $0 build [debug] | clean"
        exit 1
        ;;
esac
