# General git guidelines

```
git checkout feature/<yours>
git pull origin main # bring in what has been merged
# ...work...
# if you want to switch branchs
git switch <branch>

make  # must compile before you push
git add <your files>
# or
git add .
git commit -m "message"
git push origin feature/<yours>
```

## Branches

| Branch | Contents | Owner |
|--------|----------|-------|
| `feature/core-interfaces` | Abstract bases and shared types (Incident, zones, response-unit and mediator interfaces, enums). Merged **first** to freeze the skeleton. | TBC |
| `feature/adapter` | Legacy system + adapter | TBC |
| `feature/state` | | TBC |
| `feature/composite` | | TBC |
| `feature/mediator` | Coordinator + concrete response teams | TBC |
| `feature/command` | Commands + operator console (invoker, history, undo) | TBC |
| `feature/facade` | Emergency workflows | TBC |
| `feature/integration` | `main.cpp` scenarios, wiring, failure cases | Everyone |
| `docs/uml-and-report` | Class diagram, 3 behavioural diagrams, PDF write-up | TBC |
| `chore/quality` | Valgrind/GDB evidence | TBC |

## Merge order
1. `feature/core-interfaces`
2. `feature/adapter`, `feature/state`, `feature/composite` (independent, any order)
3. `feature/mediator`
4. `feature/command`
5. `feature/facade`
6. `feature/integration`
7. `chore/quality`, `docs/uml-and-report`

## Github rules
- NEVER work on main!
- Before opening a PR: merge the latest `main` into your branch, resolve conflicts on your side, then confirm that `make` and `docker compose up --build` both work.
- If you have a merge conflict resolve it and make sure the code still does what it is supposed to.
- `git pull` before you start working.
- write clear commits and commit OFTEN...
    example that is NOT a valid message `Implemented State pattern`
    example of what is a valid message `Fix double delete in Incident state transition`