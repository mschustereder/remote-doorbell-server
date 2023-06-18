from http.server import BaseHTTPRequestHandler, HTTPServer
import json

# HTTPRequestHandler class
class RequestHandler(BaseHTTPRequestHandler):
    # Handle POST requests
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        data = json.loads(post_data.decode('utf-8'))
        print('Received data:', data)

        # Send response
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.wfile.write(b'Request received')

# Define the server address
server_address = ('', 8000)

# Create an HTTP server with the custom handler
httpd = HTTPServer(server_address, RequestHandler)
print('Server running on port 8000...')

# Start the server
httpd.serve_forever()