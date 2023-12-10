import serial

ser = serial.Serial()
ser.baudrate = 9600
ser.port = 'COM3'
ser.open()

values = bytearray([4, 9, 62, 144, 56, 30, 147, 3, 210, 89, 111, 78, 184, 151, 17, 129])
ser.write(values)

total = 0

while total < len(values):
    print(ord(ser.read(1)))
    total = total + 1

ser.close()


# import serial
# import time
#
# ser = serial.Serial('/dev/ttyUSB0', baudrate=115200)
# time.sleep(0.5) #wait 0.5s for serial connection
#
# cw = [0xff,0x00,0x00,0x00,0x00,0x00]
#
# ser.write(serial.to_bytes(cw))
# print(serial.to_bytes(cw))