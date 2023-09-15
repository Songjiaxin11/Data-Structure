#!/bin/bash
mkdir VE280
cd VE280
mkdir projects exercises
touch projects/info.txt
cd projects
echo "This is the directory for project files." > info.txt
cd ..  
cp projects/info.txt exercises
echo "This is the directory for exercise files.">exercises/info.txt
mkdir templates
touch templates/Makefile templates/main.cpp
cp -r templates projects
cp -r templates exercises
rm -r templates
touch dir_info.txt test.txt
ls -l>dir_info.txt
diff projects/info.txt exercises/info.txt >test.txt
