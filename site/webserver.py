import serial
from flask import Flask
# from flask import url_for
from flask import render_template
from flask import send_from_directory

# Initializes flask endpoint 
app = Flask(__name__)
	    
	    # unused	
            # static_url_path='/', 
            # static_folder='templates/my-app/build/',
            # template_folder='templates/my-app/build/')
            
# sets the serial port
ser = serial.Serial(
        port='/dev/ttyACM0',
        baudrate=9600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=0
        )
# serving index.html to the main website endpoint
@app.route("/")
def index():
     return render_template('index.html')

@app.route("/fancy")
def base():
    return send_from_directory('my-app/build', 'index.html')

# Path for all the static files (compiled JS/CSS, etc.)
@app.route("/<path:path>")
def home(path):
    return send_from_directory('my-app/build', path)

# Generate endpoint for speed
@app.route('/speed/<int:value>')
def speed(value):
    # Prints to the local console 
    print(f"Setting speed to {value}")
    # TODO check bounds
    # call set_speed function given value read from endpoint
    set_speed(value)
    # return value read to api
    return f"{value}"

# Generate endpoint up 
@app.route("/up")
def up():
    # prints to the local console
    print("Increasing incline")
    # call incline function given direction = 2
    incline(2)
    # return value Ok to api
    return "Ok"

# Generate endoint down
@app.route("/down")
def down():
    # prints to the local console
    print("Decreasing incline")
    # call incline function given direction = 1
    incline(1)
    # return value Ok to api
    return "Ok"

# Generate endoint inclineStop
@app.route("/inclineStop")
def stop():
    # prints to the local console
    print("Stopping incline")
    # call incline function given direction = 3
    incline(3)
    # return value Ok to api
    return "Ok"

# Function for Incline serial communcation
def incline(direction: int):
    
    # prints to the local console
    print(f"Setting incline to {direction}")
    # ser = serial.Serial('/dev/AMC0')
    
    # Prints the name of the physical port
    print(ser.name) 
    # Writes I {direction} to serial
    ser.write(f"I {direction}\n".encode("utf-8"))
    # Prints what it just wrote to serial to the local console
    print(f"I {direction}\n".encode("utf-8"))
    # ser.close()

def set_speed(speed: int):
    # prints to local console
    print(f"Setting speed to {speed}")
    # ser = serial.Serial('/dev/AMC0')
    
    # prints the name of the physical port
    print(ser.name) 
    # Writes S {speed} to serial
    ser.write(f"S {speed}\n".encode("utf-8"))
    # Prints what it just wrote to serial to the local console
    print(f"S {speed}\n".encode("utf-8"))
