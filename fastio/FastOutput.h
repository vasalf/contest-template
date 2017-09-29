#ifndef CONTEST_TEMPLATE_FASTOUTPUT_H
#define CONTEST_TEMPLATE_FASTOUTPUT_H

#include <cstring>
#include <cstdio>
#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

template<size_t buf_size>
class FastOutput {
    char buf[buf_size];
    int cpos = 0;
    FILE *outfl;
    bool lf, cl;
public:
    inline void flush() {
        fwrite(buf, buf_size, 1, outfl);
        cpos = 0;
    }
    
    inline void putChar(char c) {
        if (cpos == buf_size)
            flush();
        buf[cpos++] = c;
    }

    inline void putBuf(const char *to_w) {
        while (*to_w != 0)
            putChar(*(to_w++));
    }

    inline void writeString(const string &s, const char *after = " ") {
        putBuf(s.c_str());
        putBuf(after);
    }

    template<class rint_t>
    inline void writeInt(rint_t x, const char *after = " ") {
        char to_w[100];
        int cur = 0;
        if (x == 0)
            putBuf("0");
        else {
            if (x < 0) {
                putChar('-');
                x = -x;
            }
            while (x > 0) {
                to_w[cur++] = (x % 10) + '0';
                x /= 10;
            }
            reverse(to_w, to_w + cur);
            to_w[cur] = 0;
            putBuf(to_w);
        }
        putBuf(after);
    }

    inline void writeEndl() {
        putChar('\n');
#ifdef LOCAL
        if (lf)
            flush();
#endif
    }

    FastOutput(const string &filename = "stdout", bool lflush = true) {
        lf = lflush;
        cl = filename != "stdout";
        if (filename == "stdout")
            outfl = stdout;
        else
            outfl = fopen(filename.c_str(), "w");
        memset(buf, 0, sizeof(buf));
    }

    ~FastOutput() {
        flush();
        if (cl)
            fclose(outfl);
    }
};

#endif //CONTEST_TEMPLATE_FASTOUTPUT_H
