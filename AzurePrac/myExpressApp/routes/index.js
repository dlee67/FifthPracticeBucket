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

module.exports = router;
