
from paho.mqtt import client as mqtt_client
from flask import Flask, render_template, request

broker = 'localhost'
port = 1883
topic1 = "mesa1"  # Mesa 1
topic2 = "mesa2"  # Mesa 2
topic3 = "mesa3"  # Mesa 3
topic4 = "mesa4"  # Mesa 4
topic5 = "tubo"   # tubo led

# generate client ID with pub prefix randomly
client_id = f'python-mqtt-{random.randint(0, 1000)}'
username = 'ariel'
password = '123'


def connect_mqtt():
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect, return code %d\n", rc)

    client = mqtt_client.Client(client_id)
    client.username_pw_set(username, password)
    client.on_connect = on_connect
    client.connect(broker, port)
    return client


app = Flask(__name__)


@app.route("/", methods=["GET", "POST"])
def home():
    client = connect_mqtt()
    datos = request.form.to_dict(flat=True)
    print(datos)

#########################################
    valores1 = datos.get("mesa1") #Convierte  en string y busca el elemento dentro del diccionario 
    # print(valores1)
    valores2 = datos.get("mesa2") #Convierte  en string y busca el elemento dentro del diccionario 
    # print(valores2)
    valores3 = datos.get("mesa3") #Convierte  en string y busca el elemento dentro del diccionario 
    # print(valores3)
    valores4 = datos.get("mesa4") #Convierte  en string y busca el elemento dentro del diccionario
    # print(valores4)
    valores5 = datos.get("tubo") #Convierte  en string y busca el elemento dentro del diccionario
    # print(valores4)
######################################### 
    # MESA 1
    if valores1 == 'ON':
        dato = 1 
        if dato == 1:
            color = datos.get("color")
            print(color)
            if color == '#ff0000':  # color rojo
                client.publish(topic1, 1)
            if color == '#00ff00':  # color Green
                client.publish(topic1, 2)
            if color == '#0000ff':  # color Blue
                client.publish(topic1, 3)
            if color == '#cccc66':  # color rasperry
                client.publish(topic1, 4)
            if color == '#00f000':  # color cyan
                client.publish(topic1, 5)
            if color == '#ff00ff':  # color magenta
                client.publish(topic1, 6)
            if color == '#fff000':  # color amarrillo
                client.publish(topic1, 7)
            if color == '#ffffff':  # color blanco
                client.publish(topic1, 8)

    if valores1 == 'OFF':
        client.publish(topic1, 0)        
#########################################
    # MESA 2
    if valores2 == 'ON':
        dato = 1
        if dato == 1:
            color = datos.get("color")
            print(color)
            if color == '#ff0000':  # color rojo
                client.publish(topic2, 1)
            if color == '#008f39':  # color Green
                client.publish(topic2, 2)
            if color == '#0000ff':  # color Blue
                client.publish(topic2, 3)
            if color == '#ff00ff':  # color magenta
                client.publish(topic2, 4)
            if color == '#ffaa00':  # color amarrillo
                client.publish(topic2, 5)

    if valores2 == 'OFF':
        client.publish(topic2, 0)
#########################################
    # MESA 3
    if valores3 == 'ON':
        dato = 1
        if dato == 1:
            color = datos.get("color")
            print(color)
            if color == '#ff0000':  # color rojo
                client.publish(topic3, 1)
            if color == '#008f39':  # color Green
                client.publish(topic3, 2)
            if color == '#0000ff':  # color Blue
                client.publish(topic3, 3)
            if color == '#ff00ff':  # color magenta
                client.publish(topic3, 4)
            if color == '#ffaa00':  # color amarrillo
                client.publish(topic3, 5)
            

    if valores3 == 'OFF':
        client.publish(topic3, 0)

#########################################
    # MESA 4
    if valores4 == 'ON':
        dato = 1
        if dato == 1:
            color = datos.get("color")
            print(color)
            if color == '#ff0000':  # color rojo
                client.publish(topic4, 1)
            if color == '#008f39':  # color Green
                client.publish(topic4, 2)
            if color == '#0000ff':  # color Blue
                client.publish(topic4, 3)
            if color == '#ff00ff':  # color magenta
                client.publish(topic4, 4)
            if color == '#ffaa00':  # color amarrillo
                client.publish(topic4, 5)

    if valores4 == 'OFF':
        client.publish(topic4, 0)
#########################################
    # TUBO
    if valores5 == 'ON':
        dato = 1
        if dato == 1:
            color = datos.get("color")
            print(color)
            if color == '#ff0000':  # color rojo
                client.publish(topic5, 1)
            if color == '#008f39':  # color Green
                client.publish(topic5, 2)
            if color == '#0000ff':  # color Blue
                client.publish(topic5, 3)
            if color == '#ff00ff':  # color magenta
                client.publish(topic5, 4)
            if color == '#ffaa00':  # color amarrillo
                client.publish(topic5, 5)

    if valores5 == 'OFF':
        client.publish(topic5, 0)
#########################################
    return render_template("/index.html")


if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=True, port=5000)
