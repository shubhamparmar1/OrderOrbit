from flask import Flask, render_template, request
from ctypes import cdll, c_double, c_char_p

app = Flask(__name__)

# Load the shared library
lib = cdll.LoadLibrary('./cpp/your_cpp_library.so')

# Define the MenuItem class
class MenuItem:
    def __init__(self, name, price):
        self.name = name
        self.price = price

    def getName(self):
        return lib.MenuItem_getName(self.name)

    def getPrice(self):
        return lib.MenuItem_getPrice(self.price)

@app.route('/')
def index():
    return render_template('index.html')

if __name__ == '__main__':
    app.run(debug=True)