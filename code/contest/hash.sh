# bash hash.sh arquivo.cpp l1 l2 -> retorna o hash das linhas l1 e l2
sed -n $2','$3' p' $1 | cpp -dD -P -fpreprocessed | tr -d '[:space:]' | md5sum | cut -c-6