#!bin/sh

{ time (
: > ete_dist.txt
#count=0
#NR_CPUS=4
for i in {99999..0..1}
do 
    ./PEOmake >> ete_dist.txt
    #let count+=1
    #[[ $((count%NR_CPUS)) -eq 0 ]] && wait
done

echo All done ) } 2> runtime.txt
