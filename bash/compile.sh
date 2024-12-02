#!/usr/bin/bash

# Made with Basher
# Neovim fights against The Matrix???

buildDir="build"
execName="avc"

if [ -d "$buildDir" ]; then
	cd $buildDir
else
	mkdir $buildDir
	cd $buildDir
	cmake ..
fi

cmake --build .

if [ $# -gt 0 ] && [ $1 = "run" ]; then
	echo $'Running program:\n------------------'
	cd ..
	./$buildDir/$execName
fi
