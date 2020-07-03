from flask import Flask, jsonify, request, url_for, redirect, session, render_template

app = Flask(__name__)

app.config['DEBUG'] = True
app.config['SECRET_KEY'] = 'Thisisasecret!'

@app.route('/')
def index():
    return '<h1>Hello, World!</h1>'

@app.route('/home', methods=['POST', 'GET'], defaults={'name' : 'Default'})
@app.route('/home/<string:name>', methods=['POST', 'GET'])
def home(name):
    session['name'] = name
    return render_template('home.html', name=name, display=False, mylist=['one', 'two', 'three', 'four'], listofdictionaries=[{'name' : 'Zach'}, {'name':'Zoe'}])

@app.route('/json')
def json():
    if 'name' in session:
        name = session['name']
    else:
        name = 'Nothing in Session!'   
    return jsonify({'key': 'value', 'key2': [1,2,3], 'name':name})

@app.route('/query')
def query():
    name = request.args.get('name')
    location = request.args.get('location')
    return '<h1>Hi {}. You are from {}. are on the query page!</h1>'.format(name, location)

@app.route('/theform', methods=['GET', 'POST'])
def theform():
    if request.method == 'GET':
        return render_template('form.html')
    else:
        name = request.form['name']
        return redirect(url_for('home', name=name))                     

@app.route('/process', methods=['POST'])
def process():
    name = request.form['name']
    location = request.form['location']
    return 'Hello {}. You are from {}. You are submitted the form successfully!'.format(name, location)

@app.route('/processjson', methods=['POST'])
def processjson():

    data = request.get_json()

    name = data['name']
    location = data['location']
    randomlist = data['randomlist']

    return jsonify({'result': 'Success!', 'name': name, 'location': location, 'radomkeyinlist': randomlist[1]})

if __name__ == '__main__':
    app.run(debug=True)