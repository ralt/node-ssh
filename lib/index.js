'use strict';

var Ssh = require( '../build/Release/ssh' );

var ssh = new Ssh( 'test' );
console.log( ssh.connect() ); // Should log "test"

