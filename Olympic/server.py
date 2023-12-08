from flask import Flask, render_template, redirect, request
import webbrowser
import threading

app = Flask(__name__)

@app.route('/command', methods=['POST'])
def handle_command():
    command = request.data.decode('utf-8')  # Get the command from the request body
    print(f"Received command: {command}")  # Log the command
    # Process the command...
    return f"Command received: {command}"

@app.route('/reset-state', methods=['POST'])
def reset_state():

    return 'PIAP has been reset.'

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/landing')
def landing():
    return render_template('landing.html')

@app.route('/divinr')
def divinr():
    return render_template('Olympus/Divinr/index.html')


@app.route('/go-to-youtube')
def go_to_youtube():
    return redirect('https://www.youtube.com/watch?v=MSb_31SUEXE')

def open_browser():
    webbrowser.open('http://127.0.0.1:5000/')

if __name__ == '__main__':
    threading.Timer(1.25, open_browser).start()
    app.run(port=5000)
