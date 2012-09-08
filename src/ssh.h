#ifndef SSH_H
#define SSH_H

#include <node.h>
#include <v8.h>

using namespace node;
using namespace v8;

class Ssh : public node::ObjectWrap {
    public:
        // Init method for node.js
        static void Init( Handle<Object> target );

    private:
        Ssh();
        ~Ssh();

        // Public methods for initialized object
        static Handle<Value> New( const Arguments& args );
        static Handle<Value> Connect( const Arguments& args );

        // Public properties
        Persistent<String> host;
};

#endif

