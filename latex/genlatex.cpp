#include<fstream>
#include<map>
#include<filesystem>
#include<iostream>
using namespace std;

/**
 * @brief Remove space characters from string extremes
 * 
 */
void trim(string &str) {
  while(str.front() == ' ') {
    str.erase(str.begin());
  }

  while(str.back() == ' ') {
    str.pop_back();
  }
}
string get_dir_name(filesystem::__cxx11::directory_entry dir) {
  string dir_path = dir.path().string();
  string dir_name = dir_path.substr(dir_path.find('/')+1);
  return dir_name;
}

/**
 * @brief Reads the first line of the code to get its title
 * 
 * @param file The code file
 * @return the title read
 */
string get_code_title(ifstream &file) {
  string first_line;
  getline(file, first_line);
  string title = first_line.substr(2); // Discarding comment slashes

  trim(title);
  return title;
}

int main() {
  ifstream ifile;
  ofstream ofile;
  ifile.open("latex/start.tex");
  ofile.open("output/library.tex");

  // Section titles for code directories
  map<string, string> dir_to_title = {
    {"math", "Matemática"},
    {"graphs", "Grafos"},
    {"strings", "Strings"}
  };

  // Put preamble in output code
  string line;
  while(getline(ifile, line)) {
    ofile << line << '\n';
  }

  for(const auto &dir : filesystem::directory_iterator{"code"}) {
    string dir_name = get_dir_name(dir);
    string section_title = dir_to_title[dir_name];
    ofile << "\\section{" << section_title << "}\n";
    for(const auto &file: filesystem::directory_iterator{dir}) {
      ifstream code_stream{file.path()};

      string subsection_title = get_code_title(code_stream);
      ofile << "\\subsection{" << subsection_title << "}\n";

      // Writes the code
      ofile << "\\begin{lstlisting}\n";
      while(getline(code_stream, line)) {
        ofile << line << '\n';
      }
      ofile << "\\end{lstlisting}\n";
      code_stream.close();
    }
  };

  ofile << "\\end{document}";
  ofile.close();
  ifile.close();
}