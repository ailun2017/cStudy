#!/bin/bash

#1.echo test
echo -n "welcome to study shell!" ; echo v1.0 by jack.lin
echo 'hello jack.lin!' ; echo "hello jack.lin/!"; echo hello jack.lin!

#env variable test
echo "=======test env var======="
export JACK=zhang # note that use source or. to execute shell script

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

#read n characters without pressing the return key
echo "please input 2 char:"
read -n 2 var
echo "you inout: $var"
echo "please input char ended with :"
read -d ":" var
echo "you inout: $var"

#run a command until it succeeds
repeat()
{
    #while true or
    while : # use while : to avoid spawning a process , this is shell built-in, which always returns an exit code 0
    do
       $@ && return
       sleep 1
    done
}
echo "please input 2 char:"
repeat read -n 2 var 
echo "repeat ok"

#field separators and iterators
line="root:x:0:0:root:/root:/bin/bash"
oldIFS=$IFS
IFS=":"
count=0
for item in $line
do
    [ $count -eq 0 ] && user=$item;
    [ $count -eq 6 ] && shell=$item;
    let count++
done

IFS=$oldIFS
echo $user\'s shell is $shell

#loop

for ((i=0;i<10;i++))
{
   echo "$i";
}

x=1
until [ $x -eq 9 ]
do
    let x++; echo $x
done

#compare and test
con=0
[ con ] && echo "con is true"; #note that there is a space between [ or ] and operands.
con=1
# [ false ] || echo "con is false" # error usage
if false
then
   echo "this is true"
else
   echo "this is false"
fi

fpath="/etc/passwd"
if [ -e $fpath ]; then
    echo file exists;
else
    echo file does not exist;
fi

#multiple test conditions can be combined as follows:
var=3
[ $var -ne 0 -a $var -gt 2 ] && echo "var > 2"
[ $var -ne 0 -o $var -gt 2 ] && echo "var > 2"

#compare string
str1="a"
str2="b"
[[ $str1 < $str2 ]] && echo "a < b"

str1="not empty"
str2=""
if [[ -n $str1 ]] && [[ -z $str2 ]];then
        echo str1 is not empty and str2 is empty string
fi

# test:the same set of test conditions enclosed with [] can be used for the test command
var=0
if test $var -eq 0 ; then echo "true"; fi

#good commands in shell
#cat cmd
cat temp.txt
cat temp2.txt temp.txt # to print contents of more than one file
echo 'text through stdin' | cat - temp2.txt
cat -b temp2.txt

#script and scriptreplay cmd: 记录执行命令的过程，相当于录回放视频
script -t 2> timing.log -a output.session
ls;
ls -l;
cat temp2.txt;
exit; # use exit to end it
scriptreplay timing.log output.session # 回放整个过程并执行

#study xargs command

cat temp_xargs.txt | xargs -n 3 ./temp.sh

#study shell at line 24 in 2022.5.10
