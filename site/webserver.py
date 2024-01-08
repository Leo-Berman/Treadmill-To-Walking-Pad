import serial
from flask import Flask
# from flask import url_for
from flask import render_template
from flask import send_from_directory


app = Flask(__name__)

@app.route("/")
def index():
    return render_template('index.html')
# @app.route("/<path:path>")
# def svelte_client(path):
#     return send_from_directory('../svelte/public/', path)


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
    incline(2)
    return "Ok"

@app.route("/down")
def down():
    print("Decreasing incline")
    incline(1)
    return "Ok"

@app.route("/inclineStop")
def stop():
    print("Stopping incline")
    incline(3)
    return "Ok"

def incline(direction: int):
    print(f"Setting incline to {direction}")
    ser = serial.Serial('/dev/tty.usbmodem1101')
    print(ser.name) 
    ser.write(f"I {direction}".encode("utf-8"))
    ser.close()

def speed(speed: int):
    print(f"Setting speed to {speed}")
    ser = serial.Serial('/dev/tty.usbmodem1101')
    print(ser.name) 
    ser.write(f"S {speed}".encode("utf-8"))
    ser.close()