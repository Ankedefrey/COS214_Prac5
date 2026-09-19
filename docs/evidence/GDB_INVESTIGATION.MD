# GDB investigation

e.g. a crash, a double delete, or a dangling pointer after a state transition.

## 1. Symptom
Paste the terminal output.

## 2. Reproduce
```
docker compose run --rm gdb
(gdb) run
```

## 3. Investigation
```
(gdb) bt # where it crashed
(gdb) frame N # jump to our code
(gdb) print <ptr> # inspect the suspect pointer
(gdb) info locals
(gdb) break File.cpp:LINE
(gdb) watch <var> # if a value changes unexpectedly
```
Paste the actual session output here.

## 4. Root cause

## 5. Fix
Code before/after

## 6. Verification
Re-run under GDB and Valgrind
