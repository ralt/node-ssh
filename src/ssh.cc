#include <node.h>
#include <v8.h>
#include "ssh.h"

extern "C" {
#include <libssh2.h>
}

using namespace node;
using namespace v8;

Handle<Value> Ssh::New( const Arguments& args ) {
    HandleScope scope;

    // Spawn a new object and assign the property
    Ssh* obj = new Ssh();
    obj->host = args[ 0 ]->StringValue();
    obj->Wrap( args.This() );

    // And return the new object
    return args.This();
}

Handle<Value> Ssh::Connect( const Arguments& args ) {
    HandleScope scope;

    // Get the current object
    Ssh* obj = ObjectWrap::Unwrap<Ssh>( args.Holder() );

    // And return its host property
    return scope.Close( String::New( obj->host ) );
}

