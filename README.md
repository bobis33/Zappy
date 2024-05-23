# EPITECH | B-YEP-400 | Zappy

![Epitech](doc/png/Epitech_banner.png)


## Description

The goal of this project is to create a network game where several teams confront on a tiles map
containing resources.
The winning team is the first one where at least 6 players who reach the maximum elevation.


## Prerequisites

- CMake 3.27
- C++20
- SFML 2.5.1
- Python 3.8


## Usage

### Build

```bash
$> make
[...]
```

## Protocols


### AI protocol

Each player responds to the following actions and only to these ones, with the following syntax :

|            Action            |      Command       | Time limit |          Response          |
|:----------------------------:|:------------------:|:----------:|:--------------------------:|
|       move up one tile       |    __Forward__     |    7/f     |             ok             |
|        turn 90° right        |     __Right__      |    7/f     |             ok             |
|        turn 90° left         |      __Left__      |    7/f     |             ok             |
|         look around          |      __Look__      |    7/f     |     [tile1, tile2,...]     |
|          inventory           |   __Inventory__    |    1/f     | [linemate n, sibur n, ...] |
|        broadcast text        | __Broadcast text__ |    7/f     |             ok             |
| number of team unused slots  |  __Connect_nbr__   |     -      |           value            |
|        fork a player         |      __Fork__      |    42/f    |             ok             |
| eject players from this tile |     __Eject__      |    7/f     |           ok/ko            |
|      death of a player       |        _-_         |     -      |            dead            |
|        fork a player         |      __Fork__      |    42/f    |             ok             |
|         take object          |  __Take object__   |    7/f     |           ok/ko            |
|       set object down        |   __Set object__   |    7/f     |           ok/ko            |
|      start incantation       |  __Incantation__   |   300/f    |     Elevation underway     | Current level: k/ko |


> In case of a bad/unknown command, the server must answer “ko”.


The AI client’s connection to the server happens as follows:

    1. the client opens a socket on the server’s port,

    2. the server and the client communicate the following way:
        Server --> WELCOME\n
               <-- TEAM-NAME\n
               --> game informations (see tha above array)

X and Y indicate the world’s dimensions.

CLIENT-NUM indicates the number of slots available on the server for the TEAM-NAME team. If this number is greater than or equal to 1, a new client can connect.

> The client can send up to 10 requests in a row without any response from the server. Over 10, the server will drop the incomming commands.

The server executes the client’s requests in the order they were received.

The requests are buffered and a command’s execution time only blocks the player in question.

Trantorians have adopted an international time unit.
The time unit is seconds.

An action’s execution time is calculated with the following formula:

action / f

Where f is an integer representing the reciprocal (multiplicative inverse) of time unit.

For instance, if f=1, “forward” takes 7 / 1 = 7 seconds.

By default f=100.


### GUI protocol


| SYMBOL |               MEANING               |
|:------:|:-----------------------------------:|
|   X    |    width or horizontal position     |
|   Y    |     height or vertical position     |
|   q0   |     resource 0 (food) quantity      |
|   q1   |   resource 1 (linemate) quantity    |
|   q2   |   resource 2 (deraumere) quantity   |
|   q3   |     resource 3 (sibur) quantity     |
|   q4   |   resource 4 (mendiane) quantity    |
|   q5   |    resource 5 (phiras) quantity     |
|   q6   |   resource 6 (thystame) quantity    |
|   n    |            player number            |
|   O    | orientation: 1(N), 2(E), 3(S), 4(W) |
|   L    |     player or incantation level     |
|   e    |             egg number              |
|   T    |              time unit              |
|   N    |          name of the team           |
|   R    |         incantation result          |
|   M    |               message               |
|   i    |          resource  number           |

<br>

|                   SERVER                   |  CLIENT   |                    DETAILS                    |                    TO A GUI client                     |                        TO ALL GUI client                        |
|:------------------------------------------:|:---------:|:---------------------------------------------:|:------------------------------------------------------:|:---------------------------------------------------------------:|
|                 msz X Y\n                  |   msz\n   |                   map size                    |        new GUI client connection or msz command        |                                                                 |
|       bct X Y q0 q1 q2 q3 q4 q5 q6\n       | bct X Y\n |               content of a tile               |                      bct command                       |                                                                 |
| bct X Y q0 q1 q2 q3 q4 q5 q6\n * nbr_tiles |   mct\n   |      content of the map (all the tiles)       | new GUI client connection or mct command or map refill |                                                                 |
|            tna N\n * nbr_teams             |   tna\n   |             name of all the teams             |               new GUI client connection                |                                                                 |
|             pnw #n X Y O L N\n             |           |          connection of a new player           |               new GUI client connection                |                    new AI client connection                     |
|               ppo n X Y O\n                | ppo #n\n  |               player’s position               |                      ppo command                       |         AI left, right forward action or AI is ejected          |
|                 plv n L\n                  | plv #n\n  |                player’s level                 |        new GUI client connection or plv command        |                    AI sucessfully incantate                     |
|      pin n X Y q0 q1 q2 q3 q4 q5 q6\n      | pin #n\n  |              player’s inventory               |        new GUI client connection or pin command        | new AI client connection or AI set, take action or AI lost food |
|                  pex n\n                   |           |                   expulsion                   |                                                        |                         AI eject action                         |
|                 pbc n M\n                  |           |                   broadcast                   |                                                        |                       AI broadcast action                       |
|            pic X Y L n n ...\n             |           | start of an incantation (by the first player) |                                                        |                      AI incantation action                      |
|                pie X Y R\n                 |           |             end of an incantation             |                                                        |                        AI incatation end                        |
|                  pfk n\n                   |           |           egg laying by the player            |                                                        |                         AI fork action                          |
|                 pdr n i\n                  |           |               resource dropping               |                                                        |                          AI set action                          |
|                 pgt n i\n                  |           |              resource collecting              |                                                        |                         AI take action                          |
|                  pdi n\n                   |           |               death of a player               |                                                        |        AI client disconnection or AI lost all it's food         |
|               enw e n X Y\n                |           |          an egg was laid by a player          |               new GUI client connection                |                 AI fork action end (after 42/f)                 |
|                  ebo e\n                   |           |         player connection for an egg          |                                                        |                    new AI client connection                     |
|                  edi e\n                   |           |                death of an egg                |                                                        |                     egg is ejected by an AI                     |
|                  sgt T\n                   |   sgt\n   |               time unit request               |            new GUI client connection or sgt            |                           sst command                           |
|                  sst T\n                   |  sst T\n  |            time unit modification             |                                                        |                                                                 |
|                  seg N\n                   |           |                  end of game                  |                                                        |             an AI team reach the victory conditions             |
|                  smg M\n                   |           |            message from the server            |                                                        |                      server send a message                      |
|                   suc\n                    |           |                unknown command                |                                                        |                    empty or unknown command                     |
|                   sbp\n                    |           |               command parameter               |                                                        |              invalide command (wrong parameter.s)               |
|                  eht e\n                   |           |                 egg is mature                 |               new GUI client connection                |    server create an egg or egg create by an AI become mature    |

<br>

The GUI client’s connection to the server happens as follows:

    1. the client opens a socket on the server’s port,

    2. the server and the client communicate the following way:
        Server --> WELCOME\n
               <-- GRAPHIC\n
               --> game informations (see the above array)


## Commit Norms

| Commit Type | Description                                                                                                               |
|:------------|:--------------------------------------------------------------------------------------------------------------------------|
| build       | Changes that affect the build system or external dependencies (npm, make, etc.)                                           |
| ci          | Changes related to integration files and scripts or configuration (Travis, Ansible, BrowserStack, etc.)                   |
| feat        | Addition of a new feature                                                                                                 |
| fix         | Bug fix                                                                                                                   |
| perf        | Performance improvements                                                                                                  |
| refactor    | Modification that neither adds a new feature nor improves performance                                                     |
| style       | Change that does not affect functionality or semantics (indentation, formatting, adding space, renaming a variable, etc.) |
| docs        | Writing or updating documentation                                                                                         |
| test        | Addition or modification of tests                                                                                         |
