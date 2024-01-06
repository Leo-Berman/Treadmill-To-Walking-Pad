import serial
from flask import Flask
# from flask import url_for
from flask import render_template

app = Flask(__name__)

@app.route("/")
def index():
    return render_template('index.html')

@app.route('/speed/<int:value>')
def speed(value):
    print(f"Setting speed to {value}")
    # TODO check bounds
    # TODO send to Arduino with PySerial
    speed(value)
    return f"{value}"

@app.route("/up")
def up():
    print("Increasing incline")
    # TODO send to Arduino with PySerial
    return "Ok"

@app.route("/down")
def down():
    print("Decreasing incline")
    # TODO send to Arduino with PySerial
    return "Ok"

def speed(speed: int):
    ser = serial.Serial('/dev/tty.usbmodem1101')
    print(ser.name) 
    ser.write(f"S {speed}".encode("utf-8"))
    ser.close()