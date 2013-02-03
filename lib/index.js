'use strict';

var Ssh = require('../build/Release/ssh').Ssh;

var ssh = new Ssh();

ssh.connect('localhost', 'test', 'test');

ssh.close();
