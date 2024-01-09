import serial
from flask import Flask
# from flask import url_for
from flask import render_template
from flask import send_from_directory


app = Flask(__name__)
            # static_url_path='/', 
            # static_folder='templates/my-app/build/',
            # template_folder='templates/my-app/build/')
            
ser = serial.Serial(
        port='/dev/ttyACM0',
        baudrate=9600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=0
        )

# @app.route("/")
# def index():
#     return render_template('index.html')

@app.route("/")
def base():
    return send_from_directory('my-app/build', 'index.html')

# Path for all the static files (compiled JS/CSS, etc.)
@app.route("/<path:path>")
def home(path):
    return send_from_directory('my-app/build', path)

@app.route('/speed/<int:value>')
def speed(value):
    print(f"Setting speed to {value}")
    # TODO check bounds
    # speed(value)
    return f"{value}"

@app.route("/up")
def up():
    print("Increasing incline")
    # incline(2)
    return "Ok"

@app.route("/down")
def down():
    print("Decreasing incline")
    # incline(1)
    return "Ok"

@app.route("/inclineStop")
def stop():
    print("Stopping incline")
    # incline(3)
    return "Ok"

def incline(direction: int):
    print(f"Setting incline to {direction}")
    # ser = serial.Serial('/dev/AMC0')
    print(ser.name) 
    ser.write(f"I {direction}".encode("utf-8"))
    # ser.close()

def speed(speed: int):
    print(f"Setting speed to {speed}")
    # ser = serial.Serial('/dev/AMC0')
    print(ser.name) 
    ser.write(f"S {speed}".encode("utf-8"))
    # ser.close()