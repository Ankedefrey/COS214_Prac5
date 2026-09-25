# CampusGuard : Emergency Response Coordination

COS214 Practical 5 (UP, 2026)

CampusGuard coordinates a campus emergency from the moment an incident is reported until it is resolved: dispatching security, medical and facilities teams, locking or restricting building areas, issuing alerts, and integrating a legacy campus system.

## Team

| Name | Student number |
|------|----------------|
| Anke de Frey | uXXXXXXXX |
|   | uXXXXXXXX |
|  | uXXXXXXXX |

## Run with Docker

Requires Docker Desktop, with the daemon running.

```
git clone https://github.com/Ankedefrey/COS214_Prac5.git
cd COS214_Prac5
docker compose up --build
```

This builds the image (installs g++, make, Valgrind and GDB, then compiles with `make`) and starts the application container.

To rebuild from scratch:

```
docker compose down
docker compose build --no-cache
docker compose up
```

## Valgrind and GDB (inside Docker)

```
docker compose build
docker compose run --rm valgrind   # full leak check of the final executable
docker compose run --rm gdb        # interactive GDB session
```

## Design patterns

| Pattern | Role in CampusGuard |
|---------|---------------------|
| Command | Operator actions (dispatch, secure area, alert, cancel) as objects, executed by the operator console |
| Mediator | Response components coordinate through the incident coordinator |
| Adapter | Legacy campus system integrated behind CampusGuard's interface |
| Facade | One-call emergency workflows over several subsystems |
| State | Each incident's lifecycle (Reported → Active → Contained → Resolved). Each state decides which operations are allowed, e.g. dispatching to a resolved incident is rejected. |
| Composite | Campus layout as a tree (Campus → Building → Floor → Room). Locking, unlocking or restricting any zone recurses to every room, and each room goes through the door adapter. |