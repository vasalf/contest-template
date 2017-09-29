#ifndef CONTEST_TEMPLATE_FASTINPUT_H
#define CONTEST_TEMPLATE_FASTINPUT_H

#include <cstdio>
#include <cassert>
#include <string>

using namespace std;

#define pb push_back

template<size_t buf_size>
class FastInput {
    char buf[buf_size];
    size_t clen = 0;
    size_t cpos = 0;
    FILE *infl;
    bool cl = false;
public:
    inline bool isEof() {
        if (cpos == clen) {
            cpos = 0;
            clen = fread(buf, 1ul, buf_size, infl);
            return clen == 0;
        } else
            return false;
    }

    inline int nextChar() {
        return isEof() ? -1 : buf[cpos++];
    }

    inline bool seekEof() {
        int res = nextChar();
        while (res == ' ' || res == '\n')
            res = nextChar();
        if (res == -1)
            return true;
        assert(cpos != 0);
        cpos--;
        return false;
    }
    
    inline char readChar() {
        int res = nextChar();
        while (res == ' ' || res == '\n')
            res = nextChar();
        assert(res != -1);
        return (char)res;
    }

    inline void copyWord(char *wbuf) {
        int w = readChar();
        while (w != ' ' && w != '\n' && w != -1) {
            *(wbuf++) = (char)w;
            w = nextChar();
        }
    }

    inline string readString() {
        int w = readChar();
        std::string res;
        while (w != ' ' && w != '\n' && w != -1) {
            res.pb((char)w);
            w = nextChar();
        }
        return res;
    }

    template<class rint_t = int>
    rint_t readInt() {
        int sgn = readChar();
        rint_t res = 0, b = 1;
        if (sgn == '-')
            b = -1;
        else if (sgn != '+')
            res = sgn - '0';
        int w = nextChar();
        while (w != ' ' && w != '\n' && w != -1) {
            res *= 10;
            res += w - '0';
            w = nextChar();
        }
        return b * res;
    }

    FastInput(const string& filename = "stdin") {
        cl = filename != "stdin";
        if (filename == "stdin")
            infl = stdin;
        else
            infl = fopen(filename.c_str(), "r");
    }

    ~FastInput() {
        if (cl)
            fclose(infl);
    }
};

#endif //CONTEST_TEMPLATE_FASTINPUT_H
