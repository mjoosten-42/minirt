#!/bin/bash

FILE=scenes/random.rt
AMOUNT=10

echo 'C  -10,-10,-10          1,1,1 70'  > $FILE
echo 'A  0.2               255,255,255' >> $FILE
echo                                    >> $FILE
echo 'L  0,0,0         0.5 255,255,255' >> $FILE
echo 'L  100,0,0       0.5 255,255,255' >> $FILE
echo 'L  0,100,0       0.5 255,255,255' >> $FILE
echo 'L  100,100,0     0.5 255,255,255' >> $FILE
echo 'L  0,0,100       0.5 255,255,255' >> $FILE
echo 'L  100,0,100     0.5 255,255,255' >> $FILE
echo 'L  0,100,100     0.5 255,255,255' >> $FILE
echo 'L  100,100,100   0.5 255,255,255' >> $FILE
echo                                    >> $FILE
echo 'pl 110,110,110   1,1,1  63,63,63' >> $FILE
echo                                    >> $FILE

function randomObject
{
	case $(($RANDOM % 3)) in
		0)
			echo -n 'sp ' >> $FILE
			randomPoint
			randomNumber "20"
			randomColor
			randomMaterial
			;;
		1)
			echo -n 'cy ' >> $FILE
			randomPoint
			randomPoint
			randomNumber "30"
			randomNumber "30"
			randomColor
			randomMaterial
			;;
		2)
			echo -n 'co ' >> $FILE
			randomPoint
			randomPoint
			randomNumber "30"
			randomNumber "30"
			randomColor
			randomMaterial
			;;
	esac
	echo >> $FILE
}

function randomMaterial
{
	case $(($RANDOM % 4)) in
		0)
			MAT=
			;;
		1)
			MAT="mirror"
			;;
		2)
			MAT="glass"
			;;
		3)
			MAT="metal"
			;;
	esac
	echo -n $MAT >> $FILE
}

function randomNumber
{
	echo -n "$(($RANDOM % $1)).$(($RANDOM % 100)) " >> $FILE
}

function randomColor
{
	echo -n "$(($RANDOM % 256)),$(($RANDOM % 256)),$(($RANDOM % 256)) " >> $FILE
}

function randomPercentage
{
	echo -n "0.$(($RANDOM % 100)) " >> $FILE
}

function randomDouble
{
	echo -n "$(($RANDOM % 100)).$(($RANDOM % 100))" >> $FILE
}

function randomPoint
{
	randomDouble
	echo -n "," >> $FILE
	randomDouble
	echo -n "," >> $FILE
	randomDouble
	echo -n " " >> $FILE
}

echo -n "["
printf -- '-%.0s' {1..$(seq 0 $(($AMOUNT - 1)))}
echo -n "]"
PROGRESS=""
for i in {1..$(seq 0 $AMOUNT)} ; do
	randomObject
	echo -ne "\r[$PROGRESS"
	PROGRESS+="#"
done
echo
