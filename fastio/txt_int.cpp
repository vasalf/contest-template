#include "FastInput.h"
#include "FastOutput.h"

FastInput<4096> fin("input.txt");
FastOutput<(size_t)1e6> fout("output.txt");

int main() {
    while (!fin.seekEof()) {
        int x = fin.readInt();
        fout.writeInt(x);
    }
    fout.writeEndl();
    return 0;
}
