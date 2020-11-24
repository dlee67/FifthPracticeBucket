const express=require('express');
const cookieParser = require('cookie-parser');
const path = require('path');
const logger = require('morgan');
const axios=require('axios');
const bodyParser=require('body-parser');
const cors=require('cors');
const config=require('./config');
const crypto=require('crypto');
const cookieSession=require('cookie-session');


exports.module={
express:express,
cookieParser:cookieParser,
path:path,
logger:logger,
axios:axios,
bodyParser:bodyParser,
cors:cors,
config:config,
crypto:crypto,
cookieSession:cookieSession

}