#!/bin/sh

for project in `basename -s .mk projects/*.mk`; do \
    make $project; \
done
