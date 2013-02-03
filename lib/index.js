'use strict';

var Ssh = require('../build/Release/ssh').Ssh;

var ssh = new Ssh();

ssh.connect('localhost');

ssh.close();
