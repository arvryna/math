#!/bin/bash
rm -rf out; mkdir out
echo "Compiling TEX file $1"
pdflatex -interaction=batchmode -output-directory=out $1.tex
#xdg-open out/$1.pdf
