var socket = io('ws://localhost:3000/');
socket.onopen = function() {
  console.log('WebSocket connection established');
};

// Set up button click event listeners to send messages to the server
const rightButton = document.getElementById('right');
const leftButton = document.getElementById('left');
const forwardButton = document.getElementById('up');
const backButton = document.getElementById('down');

rightButton.addEventListener('click', () => {
  socket.emit('direction', 'right');
});

leftButton.addEventListener('click', () => {
  socket.emit('direction', 'left');
});

forwardButton.addEventListener('click', () => {
  socket.emit('direction', 'forward');
});

backButton.addEventListener('click', () => {
  socket.emit('direction', 'back');
});

// Handle incoming messages from the server
socket.onmessage = function(event) {
  let message = event.data;
  
  let messageElem = document.createElement('div');
  messageElem.textContent = message;
  document.getElementById('messages').prepend(messageElem);
};











