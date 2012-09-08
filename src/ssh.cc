#include <node.h>
#include <v8.h>

extern "C" {
#include <libssh2.h>
}

using namespace node;
using namespace v8;

Handle<Value> Connect( const Arguments& arg ) {
    HandleScope scope;
    int rc = libssh2_init( 0 );
    if ( rc == 0 ) {
        return scope.Close( String::New( "working" ) );
    }
    else {
        return scope.Close( String::New( "not working" ) );
    }
}

void init( Handle<Object> target ) {
    target->Set( String::NewSymbol( "connect" ),
        FunctionTemplate::New( Connect )->GetFunction() );
}

NODE_MODULE( ssh, init )

