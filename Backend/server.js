const elasticsearch = require('@elastic/elasticsearch');
const express = require('express');

const config = require('/etc/arconf/config.json');
// const config = require('./kube/secrets/config.json');

const events = require('events.json');

es = new elasticsearch.Client({ node: config.ES_HOST, log: 'error' });

const app = express();

app.get('/eventserver/:eventid', async (req, res) => {
    const eventid = req.params.eventid;
    console.log('asked for eventID:', eventid);
    res.status(200).send(events[eventid]);
});

app.get('/netservers', async (req, res) => {
    res.status(200).send('OK');
});

app.post('/', async (req, res) => {
    console.log('recieved app usage info.');
    let data = req.body;
    console.log(' data:\t', data);
    res.status(200).send('OK');
});


app.get('/healthz', function (_req, res) {
    res.status(200).send('OK');
});

app.listen(80);


async function main() {
    try {
        await es.ping(function (err, resp, status) {
            console.log('ES ping:', resp.statusCode);
        });
    } catch (err) {
        console.error('Error: ', err);
    }
}

main();
