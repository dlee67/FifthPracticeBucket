const mod=require('./modules').module;
var app = mod.express();

// view engine setup
app.set('views', mod.path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

app.use(mod.logger('dev'));
app.use(mod.express.json());
app.use(mod.express.urlencoded({ extended: false }));
app.use(mod.cookieParser());
app.use(mod.express.static(mod.path.join(__dirname, 'public')));

app.use(mod.cors({
  origin:['http://localhost:4200'],
  methods:['GET','PUT','POST','DELETE']
}))

app.use(mod.cookieSession({
  name:'sess', //name of the cookie in the browser
  secret:'asdfgh',
  httpOnly:true
}))
const indexRouter = require('./routes/index');


app.use('/oauth', indexRouter);


// error handler
app.use(function(err, req, res, next) {
  res.status(err.status).send();
});

app.listen(mod.config.APP_PORT,function()
{
  console.log("app listening on port"+mod.config.APP_PORT);
})

module.exports = app;
