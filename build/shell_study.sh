#!/bin/bash

#1.echo test
echo -n "welcome to study shell!" ; echo v1.0 by jack.lin
echo 'hello jack.lin!' ; echo "hello jack.lin/!"; echo hello jack.lin!

#env variable test
echo "=======test env var======="
export JACK=zhang

#find the length of a string
echo "=======test the length of string======="
str=1234zal
echo ${#str}
str="1234zal"
echo ${#str}
str = 1234zal
echo ${#str}
str="1234&zal"
echo ${#str}

#math with shell
echo "=====math with shell test======="
no1=4
no2=5
let res=no1+no2
echo "res=$res"
res=$[ $no1 + $no2 ]
echo "res=$res"
res=`expr $no1 + $no2`
echo "res=$res"
res=$(expr $no1 + $no2)
echo "res=$res"

echo "scale=2;3/8" | bc

#playing with file descriptors and redirection
echo "this is test01!" > temp.txt
echo "retore"
echo "\nthis is test02!" >> temp.txt
#study shell at line 15 in 2022.5.10
