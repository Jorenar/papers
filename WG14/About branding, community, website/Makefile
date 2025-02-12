.POSIX:

FILE := paper

all: $(FILE).pdf

%: assets/%
	./pad.sh $< $@

logo.png: assets/logo.svg
	magick -background transparent -density 400 $< $@

$(FILE).pdf: logo.png logo.svg wg14link.html homepage.html ref.bib $(FILE).latex
	tectonic $(FILE).latex

clean:
	$(RM) *.png *.pdf logo.svg wg14link.html homepage.html
