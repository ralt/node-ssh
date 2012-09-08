#include <iostream>
#include <node.h>
#include <v8.h>

extern "C" {
    #include <libssh2.h>
}

using namespace std;
using namespace node;
using namespace v8;

Handle<Value> Connect(const Arguments& arg) {
    HandleScope scope;
    return scope.Close(String::New("working"));
}

void init(Handle<Object> target) {
    target->Set(String::NewSymbol("connect"),
        FunctionTemplate::New(Connect)->GetFunction());
}

NODE_MODULE(ssh, init)

