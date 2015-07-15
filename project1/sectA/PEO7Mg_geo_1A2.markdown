# PEO oligomer N=7 and Mg+2 ion geometry optimization

## Method
The relaxed chain coordinates were taken from 1A1 and a Mg ion was added 2 Angstroms from the third ether oxygen. Also, it should be noted that the D3 vdW correction was included.

![1A2 image](https://github.com/wood-b/CompBook/blob/master/screenshots/071315_10.10.28.png?raw=true)

Level of theory
* Functional: BLYP 
* Basis Set: 3-21++G [basis set exchange](https://bse.pnl.gov/bse/portal)

## Issues
Self consistent field calculation did not converge.

## Ideas
Reasons why it did not converge:
* In vacuum
* Mg not coordinated properly
* Charged system
* ???

## Input Changes 0
* max SCF cycles increased
* SCF algorithm geometric direct minimization (GDM) instead of Pulay DIIS
* NAN convergence criterion met 

## Input Changes 1
* SCF algorithm changed to diis_gdm
* Convergence failed

## Input Changes 2
* SCF_guess = gwh instead of default
* Convergence failed
