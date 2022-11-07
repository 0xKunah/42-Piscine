#!/bin/sh
find . \( -type f -or -type d \) -name "*" | wc -l | bc
