#!/usr/bin/env bash

if cmake --build build; then
	exec ./build/avc
else
	echo "Build failed"
	exit 1
fi
