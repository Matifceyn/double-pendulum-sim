#!/bin/bash

alias ls='ls --color=auto'
alias ll='ls -l'
alias l.='ls -al'
alias ldir='ls -l | grep "^d"'

get_pendulum() {
	svn checkout https://double-pendulum-sim.googlecode.com/svn/trunk/ \
	double-pendulum-sim --username philmb
}

ne() {
	nedit $* &
}

pbdisp() {
	export DISPLAY=':0.0'
}

gox() {
	X -multiwindow &
	pbdisp
}
