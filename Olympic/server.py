import webbrowser
import threading
from flask import Flask, render_template

app = Flask(__name__)

def open_browser():
    webbrowser.open_new('http://127.0.0.1:5000/')

@app.route('/')
def index():
    return render_template('/templates/template.html')

if __name__ == '__main__':
    threading.Timer(1.25, open_browser).start()  # Wait for server to start before opening browser
    app.run(port=5000)
