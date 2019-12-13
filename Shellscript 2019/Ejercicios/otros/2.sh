#!/bin/bash
VAR=1
echo $VAR
unset VAR
echo ${VAR:-2}
echo $VAR
FICH=fichero.c
echo ${FICH%.c}.o


VAR=1
echo $VAR
unset VAR
echo ${VAR:=2}
echo $VAR
FICH=/usr/bin/prueba
echo ${FICH##*/}

VAR=`ls *.sh`
VAR2=$(ls *.sh)

echo "$VAR \n\n$VAR2"

hola='\x41'
#lo siguiente solo funciona con bash, no con sh
echo $'\x41' 
echo -e "Hola\n\n"


VAR=1
VAR=$VAR+1
echo $VAR
RES1=$(($VAR))+1
echo $RES1
VAR=1
RES2=$((VAR+1)) #VAR no necesita $
echo $RES2
VARb=b
echo $(($VARb+1)) #VARb necesita $