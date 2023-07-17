if [ ! -d "output" ]
then
  mkdir output
fi

g++ latex/genlatex.cpp -o genlatex
./genlatex
rubber --into output -d output/library.tex
rm genlatex