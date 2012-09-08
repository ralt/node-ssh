#include <iostream>
#include <node.h>
#include <v8.h>

extern "C" {
    #include <libssh2.h>
}

using namespace std;
using namespace node;
using namespace v8;

int main() {
    string s = "Hello";
    clog << s << endl;
    return 0;
}

