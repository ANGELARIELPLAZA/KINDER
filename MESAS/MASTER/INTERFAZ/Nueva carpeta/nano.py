import paho.mqtt.client as mqtt
from flask import Flask, render_template, request
app = Flask(__name__)

mqttc=mqtt.Client()
mqttc.connect("localhost",1883,60)
mqttc.loop_start()



@app.route("/", methods=["GET", "POST"])
def main():
   datos = request.form.to_dict(flat=True)
   print(datos)
   # Pass the template data into the template main.html and return it to the user
   return render_template('main.html')

def run():
    
    publish(client)

def publish(mqttc):
    mqttc.publish(topic, 2)
    

if __name__ == "__main__":
   app.run(host='0.0.0.0', port=8181, debug=True)