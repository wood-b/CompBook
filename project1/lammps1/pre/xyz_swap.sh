#!bin/sh

#this script makes a temporary directory and cuts up the lammps input file
#into top middle bottom. middle starting where the xyz coords begin.
#the middle section is then replaced with the new relaxed xyz coords

mydir=$(mktemp -dt "$0")

head -62 linear_57PEO.lmps > /tmp/top
tail -n 2033 linear_57PEO.lmps > /tmp/bottom

tail -n 407 relax_57PEO.xyz > /tmp/newXYZ 
grep -A 408 "Atoms" linear_57PEO.lmps | tail -n 407 > /tmp/oldXYZ

paste /tmp/oldXYZ /tmp/newXYZ | awk '{ print $1 " " $2 " " $3 " " $4 " " $11 " " $12 " " $13 " " $8 " " $9}' > /tmp/middle

cat /tmp/top /tmp/middle /tmp/bottom >> 57PEO.lmps 




