#ifndef SSH_H
#define SSH_H

#include <node.h>
#include <v8.h>

extern "C" {
#include <libssh2.h>
}

using namespace node;
using namespace v8;

class Ssh : public node::ObjectWrap {
    public:
        // Init method for node.js
        static void Init(Handle<Object> target);

    private:
        Ssh();
        ~Ssh();

        // Public methods for initialized object
        static Handle<Value> New(const Arguments &args);
        static Handle<Value> Connect(const Arguments &args);
        static Handle<Value> Close(const Arguments &args);

        // Properties
        LIBSSH2_SESSION *session;

        // Close the Ssh connection and cleanup memory
        void close();
};

#endif
