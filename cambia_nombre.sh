#!/bin/bash

for fich in $1/*
do
	mv "$fich" "${fich}"."$2"
done
