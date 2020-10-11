#!/bin/bash

make

ctnr[0]="list"
ctnr[1]="vector"
ctnr[2]="map"
ctnr[3]="stack"
ctnr[4]="queue"
ctnr[5]="deque"

i=0;

red="\033[0;31m"
green="\033[0;32m"
none="\033[0m"

cmd="diff <(./ft_containers ${ctnr[$i]} ft) <(./ft_containers ${ctnr[$i]} std)"

while [ "$i" -lt 6 ]
do
    c=$(echo ${ctnr[$i]} | wc -c | tr -d ' ')
    # echo $c
    if [ "$c" -eq '1' ]
    then
        break
    fi
    echo "---${ctnr[$i]}---"
    result=$(diff <(./ft_containers ${ctnr[$i]} ft) <(./ft_containers ${ctnr[$i]} std) | wc -c | tr -d ' ')
    # echo $result
    if [ "$result" -eq '0' ]
    then
        r=$(./ft_containers ${ctnr[$i]} ft)
        # echo $r
        if [ "$r" = "Wrong arguments" ]
        then
            echo -e "$red pas ok $none"
            echo "$r"
        else
            echo -e "$green ok $none"
        fi
    else
        echo -e "$red pas ok $none"
        diff <(./ft_containers ${ctnr[$i]} ft) <(./ft_containers ${ctnr[$i]} std)
    fi
    echo ""
    i=$((i+1))
done