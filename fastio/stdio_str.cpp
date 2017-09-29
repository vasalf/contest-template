#include "FastInput.h"
#include "FastOutput.h"

FastInput<4096> fin;
FastOutput<(size_t)1e6> fout;

int main() {
    while (!fin.seekEof()) {
        string x = fin.readString();
        fout.writeString(x, "\n");
    }
    return 0;
}
