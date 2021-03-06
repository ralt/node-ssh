#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <v8.h>
#include <exception>
#include "main.h"
#include "ssh.h"

extern "C" {
#include <libssh2.h>
}

using namespace node;
using namespace v8;

void InitAll(Handle<Object> target) {
    HandleScope scope;

    // Initialize the library
    libssh2_init(0);

    // And our object
    Ssh::Init(target);
}

NODE_MODULE(ssh, InitAll)
