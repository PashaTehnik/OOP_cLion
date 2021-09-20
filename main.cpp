#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <iterator>
#include <map>
#include <cstring>
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
/*
list <string> distin(list<string> arr){
    list <string> new_list;
    for (auto i : arr){
        for (auto j : arr){

        }
    }
    return new_list;
}
*/
int main(int argc, char** argv) {

    ifstream inp(argv[1]);
    ofstream out(argv[2]);

    if (!inp) {
        cout << "incorrect input file\n";
        exit(-1);
    }

    string str;
    string word = "";
    while (inp) {
        next_line:
        getline(inp, str);
        int n = str.size();

        for (int i = 0; i < n; i++) {
            if ((str[i] == ' ') || (str[i] == '.') || (str[i] == ',') || (str[i] == ';') || (str[i] == ':') || (str[i] == '\n') || (str[i] == '\0')) {
                book[word] += 1;
                _list.push_front(word);
                if((str[i] == '\n') || (str[i] == '\0')) goto next_line;
                while((str[i] == ' ') || (str[i] == '.') || (str[i] == ',') || (str[i] == ';') || (str[i] == ':')) i++;
                word = "";
            }

            word += str[i];
        }
    }
    _list.sort(comp_str);
    _list.unique();
    _list.sort(comp);
    //for (it_list=_list.begin(); it_list != _list.end(); ++it)
        //cout << it_list->data() << endl;
        std::cout << '\n';
    //distin(_list);
    int count_words = 0;
    for (auto v : _list){
        count_words += book[v];
    }
    printf("             Word        freq.  freq(%%)\n");
    for (auto v : _list){
        printf("%20s    %3d    %4f%%\n", v.c_str(), book[v], ((float)book[v])/((float)count_words));

    }

/*
    for (it = book.begin(); it != book.end(); it++)
        cout << "key " << it->first << ", value " << it->second << endl;
*/
 }