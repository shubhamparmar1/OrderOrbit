from flask import Flask, render_template, request
from ctypes import cdll, c_double, c_char_p, c_void_p, c_int

app = Flask(__name__)

# Load the shared library
lib = cdll.LoadLibrary('../CPP/cpp_library.so')

# Define the MenuItem class
class MenuItem:
    def __init__(self, name, price):
        self.name = name
        self.price = price

    def getName(self):
        return lib.MenuItem_getName(self.name)

    def getPrice(self):
        return lib.MenuItem_getPrice(self.price)

# Define the Table class
class Table:
    def __init__(self, number):
        self.obj = lib.Table_new(number)

    def getNumber(self):
        return lib.Table_getNumber(self.obj)

# Define the Order class
class Order:
    def __init__(self, tableNumber):
        self.obj = lib.Order_new(tableNumber)

    def addItem(self, item):
        lib.Order_addItem(self.obj, item.obj)

    def getTotal(self):
        return lib.Order_getTotal(self.obj)

    def applyDiscount(self, percentage):
        lib.Order_applyDiscount(self.obj, c_double(percentage))

    def setSpecialRequest(self, request):
        lib.Order_setSpecialRequest(self.obj, c_char_p(request.encode('utf-8')))

    def getStatus(self):
        return lib.Order_getStatus(self.obj)

    def setStatus(self, status):
        lib.Order_setStatus(self.obj, status)

# Define the OrderManager class
class OrderManager:
    def __init__(self):
        self.obj = lib.OrderManager_new()

    def placeOrder(self, order):
        lib.OrderManager_placeOrder(self.obj, order.obj)

    def updateOrderStatus(self, orderId, status):
        lib.OrderManager_updateOrderStatus(self.obj, orderId, status)

    def getOrderHistory(self):
        # This method would need to be implemented depending on how you want to handle order history in Python
        pass

@app.route('/')
def index():
    return render_template('index.html')

if __name__ == '__main__':
    app.run(debug=True)