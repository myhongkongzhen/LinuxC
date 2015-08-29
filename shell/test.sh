#!/bin/bash

file=[^42]*
echo ${file}

a=30
b=30
d=$((a++))
e=$((++b))
f=$(((a++),6))
echo $d
echo $e
echo $f

a="hello this is maomaochong"
echo ${a#hello}
echo ${a#world}
echo ${a#this}

