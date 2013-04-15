PANDOC = pandoc.my
OPTS_SET = -f markdown -t latex --include-in-header header.tex -s
OPTS_VAR = -V fontsize=12pt -V documentclass=jsbook

INPUT = top.tex
OUTPUT = thesis.tex
OUTPUTDVI = $(OUTPUT:%.tex=%.dvi)

all:
	make tolatex
	make topdf
addtoc:
	make tolatex
	platex $(OUTPUT)
	make topdf
tolatex:
	ruby pandoc.rb
	$(PANDOC) $(OPTS_SET) $(INPUT) $(OPTS_VAR) -o $(OUTPUT)
topdf:
	platex $(OUTPUT)
	dvipdfmx $(OUTPUTDVI)
