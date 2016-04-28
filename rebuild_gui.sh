#!/bin/sh

# This script rebuilds the GraviT attributes GUI
# Be sure to call this after you've finished running 
# bin/xmledit on GraviT.xml (remember to generate 
# plugin information and save the xml file)

cp ./avtGraviTFilter.* ./Backups
cp ./avtGraviTPlot.* ./Backups
cp ./CMakeLists.txt ./Backups
../../bin/xml2plugin -clobber GraviT.xml
make clean
rm CMakeCache.txt
cp ./Backups/avtGraviTFilter.* ./
cp ./Backups/avtGraviTPlot.* ./
cp ./Backups/CMakeLists.txt ./
sh ../../recmake_visit.sh
cp ./Backups/CMakeLists.txt ./
make -C .. -j 5
