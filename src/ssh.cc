#include <node.h>
#include <v8.h>
#include "ssh.h"

extern "C" {
#include <libssh2.h>
}

using namespace node;
using namespace v8;

Ssh::Ssh() {}
Ssh::~Ssh() {}

void Ssh::Init(Handle<Object> target) {
    HandleScope scope;

    // Prepare the constructor
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);

    // Set the class name
    tpl->SetClassName(String::New("Ssh"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // Set the prototype methods
    tpl->PrototypeTemplate()->Set(String::NewSymbol("connect"),
        FunctionTemplate::New(Connect)->GetFunction());

    // Set the constructor
    Local<Function> constructor = Local<Function>::New(
        tpl->GetFunction());

    // Set the constructor on the object
    target->Set( String::NewSymbol("Ssh"), constructor);
}

Handle<Value> Ssh::New(const Arguments& args) {
    HandleScope scope;

    // Return the new object
    return args.This();
}

Handle<Value> Ssh::Connect(const Arguments& args) {
    HandleScope scope;

    // Get the current object
    Ssh* obj = ObjectWrap::Unwrap<Ssh>(args.Holder());

    // Add the session to it
    obj->session = Persistent<LIBSSH2_SESSION>::New(libssh2_session_init());

    // And return the current object
    return scope.Close(obj);
}
