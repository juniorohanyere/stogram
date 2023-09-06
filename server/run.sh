#!/bin/bash

# Start the Python server in the background
python3 server.py &

# Sleep for a moment to allow the server to start
sleep 1

# Run the C client
../client/./a.out
