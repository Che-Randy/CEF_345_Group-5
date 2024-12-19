const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const PORT = 3000;

// Middleware
app.use(bodyParser.json());

// Test API routes
app.get('/api/users', (req, res) => {
    res.json({ message: 'GET all users' });
});

app.post('/api/users', (req, res) => {
    const user = req.body;
    res.json({ message: 'POST a new user', user });
});

app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});