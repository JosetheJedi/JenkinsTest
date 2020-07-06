#!/usr/bin/env bash

git add .

read -p "Give me a commit message: " commitMessage

if [ -z "$commitMessage"]
then
    echo "Your commit message cannot be empty! Try again!"
else
    echo "okay.. i see you"
    git commit -m "${commitMessage}"
fi