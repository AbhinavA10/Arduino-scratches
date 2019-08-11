# Arduino-scratches
Collection of test programs

## IMU Notes

https://www.sparkfun.com/pages/accel_gyro_guide
Accelerometers measure acceleration
- they are affected by acceleration of gravity --> can therefore do tilt sensing
- measured along axis

Gryoscopes measure angular velocity - velocity around an axis
- not affected by gravity
- measured about axis

IMU
- combination of accelerometer, gyroscope (and magnetometer)
- by combining, we can comfortably calculate things like orientation, position, and velocity.

I2C Notes:
https://learn.sparkfun.com/tutorials/i2c/all

### interfacing gy-521 with arduino mega 2560
Elegoo pdf: https://images-na.ssl-images-amazon.com/images/I/D1oC-c3G5TS.pdf

Tutorial: https://maker.pro/arduino/tutorial/how-to-interface-arduino-and-the-mpu-6050-sensor
- download libraries from site in above link: i2cdev and MPU6050.
- copy the extracted zip files into <User>/Documents/Arduino/libraries

DMP stands for Digital Motion Processing

Processing:
- install toxiclibs library through Processing IDE

## Sonar RADAR
https://howtomechatronics.com/projects/arduino-radar-project/
