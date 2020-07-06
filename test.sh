#!/usr/bin/env bash

git add .

read -p "Give me a commit message: " commitMessage

git commit -m "${commitMessage}"

git log --oneline

osascript -e "display notification 'pushed to remote' with title 'SUCCESS'"