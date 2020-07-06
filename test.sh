#!/usr/bin/env bash

git add .

read -p "Give me a commit message: " commitMessage

git commit -m "${commitMessage}"

git log --oneline