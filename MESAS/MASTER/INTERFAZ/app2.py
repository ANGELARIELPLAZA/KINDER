
import random
import time

from flask import Flask, render_template, request


app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def home():
    datos = request.form.to_dict(flat=True)
    print(datos)

    return render_template("/index.html")

if __name__ == '__main__':
     app.run(host='0.0.0.0',debug=True,port=8080)
     run()