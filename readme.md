# The Musical Playing Instrument

Backend code is located at

    /main_server/main_server

Frontend code is located at 

    /main_server/vue-frontend

Arduino code is located at

    /arduino

Hardware interfacing is located at 

    /processing

Fritzing, sketches are located in this folder. 

# Details about frontend and backend api interactions
Please see api.pdf

## Sending Music

HTML POST Request

URL: /api/input

Attributes:

type: MusicInButtoned OR MusicInTyped

arguments: music script (e.g C1D2E3R9)


## Current Status
HTML GET Request

URL: /api/status

Attributes Expected in Response:

machineStatus

All strings

 
## Robot Control Mode
HTML Post Request

URL: /api/toggle

Attributes:

type:changeMode

arguments: arduino,online

## Music Selector
HTML POST Request

type: MusicSelection

arguments: Mario, RickRoll, GoukurakuJoudo




