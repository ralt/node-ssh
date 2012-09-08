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

void Ssh::Init( Handle<Object> target ) {
    // Prepare the constructor
    Local<FunctionTemplate> tpl = FunctionTemplate::New( New );

    // Set the class name
    tpl->SetClassName( String::New( "Ssh" ) );

    // Set the prototype methods
    tpl->PrototypeTemplate()->Set( String::NewSymbol( "connect" ),
        FunctionTemplate::New( Connect )->GetFunction() );

    // Set the constructor
    Persistent<Function> constructor = Persistent<Function>::New(
        tpl->GetFunction() );

    // Set the constructor on the object
    target->Set( String::NewSymbol( "Ssh" ), constructor );
}

Handle<Value> Ssh::New( const Arguments& args ) {
    HandleScope scope;

    // Spawn a new object and assign the property
    Ssh* obj = new Ssh();
    obj->host = Persistent<String>::New( args[ 0 ]->ToString() );
    obj->Wrap( args.This() );

    // And return the new object
    return args.This();
}

Handle<Value> Ssh::Connect( const Arguments& args ) {
    HandleScope scope;

    // Get the current object
    Ssh* obj = ObjectWrap::Unwrap<Ssh>( args.Holder() );

    // And return its host property
    return scope.Close( obj->host );
}

