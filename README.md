# Pepa
An e-paper display for personalized information, including the time, weather, and bus departure time.
The program for the device is written in C++ with Arduino environment for ESP32.
The backend server uses Python and [flask](https://flask.palletsprojects.com/en/3.0.x/)

![](resource/img/WIP_20240119.jpg)

## File structure
```
📦 Pepa
├─ 3d                       # 3D model of the case for 3D printing
├─ pepa_arduino             
│  ├─ pepa_arduino.ino      # Arduino project for the ESP32 board
│  └─ src                   # Source code that runs on the ESP32 board
├─ pepa_server              # Source code that runs on the backend server
└─ resource                 # Misc, reference files & notes & etc
```

## Progress
- [x] Display time
- [ ] Bus arrival time
- [ ] Display temperature & humidity
- [ ] TODO list
- [ ] Pomodoro timer
- [ ] Buzzer

## Future TODO
- [ ] Chinese text

## Resource
- Driver board Wiki: https://www.waveshare.net/wiki/E-Paper_ESP32_Driver_Board