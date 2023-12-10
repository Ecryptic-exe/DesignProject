import serial
import time
import paho.mqtt.client as paho
from paho import mqtt

client = paho.Client()
client.connect("localhost", 1883)

# Serial port communication function
def communicate_with_serial(values):
    ser = serial.Serial('COM3', 9600)

    try:
        ser.write(values)
        for value in values:
            response = ser.read(1)
            print(ord(response))
            # time.sleep(0.1)
    except serial.SerialException as e:
        print("Serial port communication error:", e)
    finally:
        ser.close()


# MQTT callback functions
def on_connect(client, userdata, flags, rc, properties=None):
    print("CONNACK received with code %s." % rc)


def on_publish(client, userdata, mid, properties=None):
    print("mid: " + str(mid))


def on_subscribe(client, userdata, mid, granted_qos, properties=None):
    print("Subscribed: " + str(mid) + " " + str(granted_qos))


def on_message(client, userdata, msg):
    print(msg.topic + " " + str(msg.qos) + " " + str(msg.payload))


# Initialize MQTT client
client.on_connect = on_connect
client.tls_set(tls_version=mqtt.client.ssl.PROTOCOL_TLS)
client.username_pw_set("", "")
client.on_subscribe = on_subscribe
client.on_message = on_message
client.on_publish = on_publish

# Connect to MQTT broker and subscribe to topics
client.subscribe("testing/#")

# Publish a message via MQTT
client.publish("testing", payload="I did it!!!!")

# Communicate with the serial port
values = bytearray([4, 9, 62, 144, 56, 30, 147, 3, 210, 89, 111, 78, 184, 151, 17, 129])
communicate_with_serial(values)

# Start the MQTT client loop
client.loop_forever()