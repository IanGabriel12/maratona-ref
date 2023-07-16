if [ ! -d "output" ]
then
  mkdir output
fi

g++ latex/genlatex.cpp -o genlatex
./genlatex
pdflatex --output-directory=output output/library.tex
rm genlatex