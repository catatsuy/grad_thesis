OUTPUT = thesis.tex
OUTPUTDVI = $(OUTPUT:%.tex=%.dvi)

all:
	make topdf
addtoc:
	platex $(OUTPUT)
	make topdf
topdf:
	platex $(OUTPUT)
	dvipdfmx -f ptex-hiragino.map -f otf-hiragino.map $(OUTPUTDVI)
