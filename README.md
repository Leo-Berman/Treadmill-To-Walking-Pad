Our [final writeup](https://github.com/Leo-Berman/Treadmill-To-Walking-Pad/blob/ad434f6aecd6edc79e3246cf7f7f194d2eee7e87/Final_Paper/Treadmill-To-Walking-Desk_Final_Paper.pdf) for this project! (Note the html website is only chrome compatible at the moment and I haven't yet been able to figure out how to launch the Svelte site from Github Pages so if you want to check it out you have to run it on your local machine).

In terms of the languages we used, LaTeX was only used for the final paper write up and the C++ was auto-detected where we were actually using Arduino. We really hope you guys enjoy this paper.
Here's our [google drive](https://drive.google.com/drive/folders/1N29aYL1at1YB_VjGNjzPlnmqFIkKpkeo?usp=drive_link) with pictures and videos.

Note: I need to add the part about setting up a venv for the site :o.
# Setting up to launch on startup
1. Run this command to generate a service
```sh
sudo nano /lib/systemd/system/tread.service
```
2. Enter this in the text file
```sh
[Unit]
 Description=My Sample Service
 After=multi-user.target

 [Service]
 Type=idle
 ExecStart=/home/laufband/Treadmill-To-Walking-Pad/site/venv/bin/flask --app /home/laufband/Treadmill-To-Walking-Pad/site/webserver.py run -h 10.0.0.91
 Restart=on-failure

 [Install]
 WantedBy=multi-user.target
```
3. Run these two commands
```sh
sudo systemctl daemon-reload
sudo systemctl enable tread
```



# Getting Started

## Flash the Arduino
1. Download the Aduino IDE and open the file to be flashed (Treadmill_Controller_1.ino).
2. Plugin the Arduino and flash the Arduino.
3. Connect the Arduino to the same device running the server. In our case this is the Raspberry Pi.
4. Start the web server.



## Run the Server on the Local Network
From the downloaded github repository main file.
```sh
cd site
```
```sh
flask --app webserver run --host your_local_ip
```
your_local_ip/ is the plain html and bootstrap site 
your_local_ip/fancy is the Svelte site

## Running / Building the Svelte App
```sh
cd site/my-app
```
```sh
pnpm -i
```

Run the site locally
```sh
pnpm run dev
```

Build the site 
```sh
pnpm run build
```

