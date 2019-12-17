var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index');
});

router.get('/journal', function(req, res, next) {
  res.render('journal');
});

router.get('/links', function(req, res, next) {
  res.render('links');
});

router.get('/devops', function(req, res, next) {
  res.render('devops');
});

router.get('/cppagain', function(req, res, next) {
  res.render('cppagain');
});

router.get('/githubtut', function(req, res, next) {
  res.render('./ForDoncey/githubtut');
});

router.get('/aiedge', function(req, res, next) {
  res.render('./aiedge');
});

module.exports = router;
