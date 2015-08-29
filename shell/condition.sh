#!/bin/bash

if ls $1 >&/dev/null;
then
	echo "file exists!"
else
	echo "file not exists!"
fi

read -p "input number:" a

if((a%2==0));then
	echo "${a} is ood"
else
	echo "${a} is not ood"
fi



