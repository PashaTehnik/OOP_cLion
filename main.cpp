#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <map>

using namespace std;

list<string> _list;
map<string, int> book;

list<string>::iterator it_list;
map<string, int>::iterator it;

bool comp (const std::string& first, const std::string& second)
{
    return (book[first] >= book[second]);
}
bool comp_str (const std::string& first, const std::string& second)
{
    return first < second;
}

int main(int argc, char** argv) {
    ifstream inp(argv[1]);
    ofstream out(argv[2]);

    if (!inp) {
        cout << "incorrect input file\n";
        exit(-1);
    }

    string str;
    string word = "";
    while (!inp.eof()) {
        getline(inp, str);
        int n = str.size();

        for (int i = 0; i <= n; i++) {
            if(isalnum(str[i])) {
                word += str[i];
                if (str[i + 1] == '\n') {
                    book[word] += 1;
                    _list.push_front(word);
                    word = "";
                }
            }
            else {
                if(word != "") {
                    book[word] += 1;
                    _list.push_front(word);
                }
                word = "";
            }
        }
    }
    _list.sort(comp_str);
    _list.unique();
    _list.sort(comp_str);

    int count_words = 0;
    for (auto v : _list){
        count_words += book[v];
    }
    printf("             Word        freq.  freq(%%)\n");
    for (auto v : _list){
        out << v.c_str() << "," << book[v] <<  "," << ((float)book[v])/((float)count_words)*100 << "%\n";
    }
}