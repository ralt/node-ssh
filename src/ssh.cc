#include <node.h>
#include <v8.h>
#include "ssh.h"

extern "C" {
#include <libssh2.h>
}

using namespace node;
using namespace v8;

Ssh::Ssh() {
    session = NULL;
}

Ssh::~Ssh() {
    close();
}

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
    tpl->PrototypeTemplate()->Set(String::NewSymbol("close"),
        FunctionTemplate::New(Close)->GetFunction());

    // Set the constructor
    Local<Function> constructor = Local<Function>::New(
        tpl->GetFunction());

    // Set the constructor on the object
    target->Set(String::NewSymbol("Ssh"), constructor);
}

Handle<Value> Ssh::New(const Arguments &args) {
    HandleScope scope;

    // Create an Ssh object
    Ssh *obj = new Ssh();
    obj->Wrap(args.This());

    // Return the new object
    return args.This();
}

Handle<Value> Ssh::Connect(const Arguments &args) {
    HandleScope scope;

    // Get the current object
    Ssh *obj = ObjectWrap::Unwrap<Ssh>(args.This());

    // New session
    LIBSSH2_SESSION *session = libssh2_session_init();

    if (obj->session) {
        libssh2_session_free(session);
    }
    obj->session = session;

    // Get the address

    // If everything went fine, return true
    return True();
}

Handle<Value> Ssh::Close(const Arguments &args) {
    HandleScope scope;

    Ssh *obj = ObjectWrap::Unwrap<Ssh>(args.This());
    obj->close();

    return True();
}

void Ssh::close() {
    int rc = libssh2_session_free(session);
    if (!rc) {
        ThrowException(Exception::Error(
            String::New("Error when closing the connection.")));
    }
    session = NULL;
}
