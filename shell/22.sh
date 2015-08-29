#!/bin/bash
chmod u+x *.sh

a=4
b=hello
c=

echo ${a} ${b} ${c}

d=30+${a}
echo ${d}

declare -i e=30+${a}
echo ${e}

declare -i f
f=300+${a}
echo ${f}

