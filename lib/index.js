'use strict';

var Ssh = require( '../build/Release/ssh' ).Ssh;

var ssh = new Ssh( 'test' );

console.log( ssh.connect() ); // Should log "test"

