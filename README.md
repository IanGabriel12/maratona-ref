# Referência de estudos para a maratona de programação
## Sobre
Esse projeto é uma versão bem nerfada do [brunomaletta/Biblioteca](https://github.com/brunomaletta/Biblioteca).
A ideia é condensar o que os assuntos que sabemos ou que ouvimos falar para estudar depois.

## Rodando o projeto
### Requisitos
Instale o `texlive-full` e o `rubber` (texlive é pesadinho).
```bash
sudo apt install texlive-full rubber
```

### Obtendo o PDF
Rode o script `./getpdf.sh` na pasta raiz do projeto. O PDF estará em `output/library.pdf`.

## Adicionando novos códigos
Crie o arquivo em `code/<pasta>` onde `<pasta>` é a seção em que o assunto mais se encaixa.
Na primeira linha do arquivo, faça um comentário indicando qual será o título do código que aparecerá
no PDF.

Se você for criar uma nova pasta, não se esqueça de alterar o `dir_to_title` em `latex/genlatex.cpp` da seguinte maneira:
```cpp
map<string, string> dir_to_title = {
  ...,
  {"nome_da_pasta", "Título da seção no documento"},
  ...
};
```
