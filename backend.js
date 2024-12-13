const mysql = require('mysql');

// Create a connection to the MySQL database
const connection = mysql.createConnection({
  host: 'your-database-host',  // e.g., 'localhost' or database server
  user: 'your-database-username',
  password: 'your-database-password',
  database: 'LetsGo'
});

// Connect to the database
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to the database:', err.stack);
    return;
  }
  console.log('Connected to the database');
});

module.exports = connection;
const express = require('express');
const connection = require('./database');
const app = express();
const port = 3000;

// Use JSON middleware
app.use(express.json());

// Example: Get all users (for login or displaying data)
app.get('/users', (req, res) => {
  connection.query('SELECT * FROM Users', (err, results) => {
    if (err) {
      return res.status(500).send('Error retrieving users');
    }
    res.json(results);
  });
});

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
fetch('http://localhost:3000/users')
  .then(response => response.json())
  .then(data => {
    console.log('Users:', data);
  })
  .catch(error => console.error('Error:', error));
