#!/bin/bash

if [ -e ~/.bash_aliases ] 
then
	source ~/.bash_aliases
fi

export PS1="\[\033[1;32m\][\!][\u@\h:\w]>\[\033[0m\] "
export EDITOR='nedit'
eval $(dircolors -b)
