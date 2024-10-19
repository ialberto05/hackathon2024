const express = require('express');
const bodyParser = require('body-parser');
const musicData = require('./musicData.json');

const app = express();
const PORT = process.env.PORT || 3000;

app.use(bodyParser.json());
app.use(express.static('frontend'));

// Endpoint to get music recommendations based on personality type
app.post('/api/recommend-music', (req, res) => {
    const personalityType = req.body.personalityType;
    const recommendations = musicData[personalityType] || [];
    res.json({ recommendations });
});

// Start the server
app.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});
