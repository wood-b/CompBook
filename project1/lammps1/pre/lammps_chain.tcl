#!usr/bin/tclsh

package require topotools
package require pbctools

mol new /Users/wood/Documents/lammps_preprocess/linear_57polymer.xyz autobonds yes waitfor all

set selc [atomselect top {name C}]
$selc set type Ce
$selc set mass 12.01100
$selc set charge 0.020

set selo [atomselect top {name O}]
$selo set type O
$selo set mass 15.9994
$selo set charge -0.3166

set selh [atomselect top {name H}]
$selh set type H
$selh set mass 1.00800
$selh set charge 0.0461

$selc delete
set selc [atomselect top {index 0 403}]
$selc set type Cm
$selc set charge 0.0661

set sel [atomselect top all]

topo retypebonds 
vmdcon -info "assigned [topo numbondtypes] bond types to [topo numbonds] bonds:"
vmdcon -info "bondtypes: [topo bondtypenames]"

topo guessangles
vmdcon -info "assigned [topo numangletypes] angle types to [topo numangles] angles:"
vmdcon -info "angletypes: [topo angletypenames]"

topo guessdihedrals
vmdcon -info "assigned [topo numdihedraltypes] dihedral types to [topo numdihedrals] dihedrals:"
vmdcon -info "dihedraltypes: [topo dihedraltypenames]"

mol reanalyze top

pbc set {250.0 250.0 250.0} -all -molid top
pbc box -center origin -shiftcenter {100.0 -100.0 0.0}
#pbc set {200.0 200.0 200.0}
#pbc set [pbc box_draw -shiftcenterrel {200.0 200.0 200.0}
#set cell [pbc get -now]
#pbc box -center origin 
#pbc wrap -centersel
#pbc box {100.0, 100.0, 100.0} -center origin 

topo writelammpsdata /Users/wood/Documents/lammps_preprocess/linear_57PEO.lmps full

#animate write pdb /Users/wood/Documents/lammps_preprocess/linear_57PEO.pdb

#quit
