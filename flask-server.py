from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app, resources={r"/*": {"origins": "*"}})

@app.route('/ring', methods=['POST', 'OPTIONS'])
def ring_doorbell():
    if request.method == 'POST':
        # Logic to ring the doorbell
        return jsonify({'message': 'Doorbell rang successfully'})
    elif request.method == 'OPTIONS':
        # Handle the OPTIONS preflight request
        response = jsonify({'message': 'CORS preflight request successful'})
        response.headers.add('Access-Control-Allow-Origin', '*')
        response.headers.add('Access-Control-Allow-Headers', 'Content-Type')
        response.headers.add('Access-Control-Allow-Methods', 'POST')
        return response

if __name__ == '__main__':
    app.run(debug=True)