
import random
import time
from paho.mqtt import client as mqtt_client
from flask import Flask, render_template, request

broker = '192.168.0.2'
port = 1883
topic = "mesa3"
# generate client ID with pub prefix randomly
client_id = f'python-mqtt-{random.randint(0, 1000)}'
username = 'ariel'
password = '123'

def publish(client):


        client.publish(topic, 2)



def run():
    client = connect_mqtt()
    client.loop_start()
    publish(client)

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def home():
    datos = request.form.to_dict(flat=True)
    print(datos)

    return render_template("/index.html")

if __name__ == '__main__':
     app.run(host='0.0.0.0',debug=True,port=8080)
     run()