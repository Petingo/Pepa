from flask import Flask, make_response
import server_time

app = Flask(__name__)

def create_plain_response(text):
    response = make_response(text, 200)
    response.mimetype = "text/plain"
    return response

@app.route("/test")
def server_test():
    return create_plain_response("succeed")

@app.route("/time")
def get_time():
    return create_plain_response(server_time.get_current_time())