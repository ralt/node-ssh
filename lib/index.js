'use strict';

var Ssh = require( '../build/Release/ssh' ).Ssh,
    ssh = new Ssh( 'test' );

console.log( ssh.connect() ); // Should log "test"

