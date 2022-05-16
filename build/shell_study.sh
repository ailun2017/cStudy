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
#use >> to append file
echo "\nthis is test02!" >> temp.txt

#redirect stderr and stdout to a single file by converting stderr to stdout using this prefered method:
ls + 2>&1 | tee temp.txt 
ls = 2>&1 > temp.txt

#array test
declare -A fruit
fruit[apple]=8
echo "apple price is ${fruit[apple]}"
echo ${!fruit[*]}

#debug shell script
set -x
echo "test debuging"
set +x

#function
test_func()
{
    echo $1, $2;#print arg1, arg2
    echo "$@";
    echo "$*";
    return 0;
}

test_func arg1 arg2
#echo $? # print return value of test_func
if [ $? -eq 0 ];
then 
        echo "test_func ok"
else
        echo "test_func failed"
fi
export -f test_func # like env variable

#spawn a separate process with subshell
pwd
(cd /home; ls)
pwd
#study shell at line 24 in 2022.5.10
