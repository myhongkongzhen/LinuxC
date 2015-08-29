#!/bin/bash

for((i=1;i<10;i++));do
	echo ${i}
done

read -p "input number : " a

c=0;
for((b=2;b<a;b++));do
	if((a%i==0));then
		c=1
		break
	fi
done

if((c==0));then
	echo "${a} is ood"
else
	echo "${a} is event"
fi

