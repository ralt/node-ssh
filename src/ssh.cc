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
    int rc = libssh2_init(0);
    string status;
    if ( rc == 0 ) {
        status = "working";
    }
    else {
        status = "not working";
    }
    return scope.Close(String::New(status));
}

void init(Handle<Object> target) {
    target->Set(String::NewSymbol("connect"),
        FunctionTemplate::New(Connect)->GetFunction());
}

NODE_MODULE(ssh, init)

