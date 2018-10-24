#!/bin/bash

# require bibtex2html (OCaml) and pandoc
cat "$1" | bibtex2html --unicode --style "apa" | pandoc -f html -t markdown

