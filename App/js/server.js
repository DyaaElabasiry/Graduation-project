const express = require('express');
const app = express();
const http = require('http');
const server = http.createServer(app);
const { Server } = require("socket.io");
const cors = require("cors");
app.use(cors());
const io = new Server(server, {
  cors: {
    origin: "*",
    methods: ["GET", "POST"],
  },
});


server.listen(3000, () => {
  console.log('listening on *:3000');

  io.on('connection', (socket) => {
    console.log(`A new client has connected with ID ${socket.id}`);

    // Listen for direction events
    socket.on('direction', (direction) => {
      console.log(`Received direction event from client ${socket.id}: ${direction}`);

      // Do something with the direction here, e.g. move a robot in the specified direction.
    });

    socket.on('disconnect', () => {
      console.log(`Client ${socket.id} has disconnected.`);
    });
  });
});
