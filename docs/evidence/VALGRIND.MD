# Valgrind evidence

**Command (inside Docker):**
```
docker compose build
docker compose run --rm valgrind | tee docs/evidence/valgrind_final.txt
```

**Result summary** (paste the tail of the output):


**Earlier issues found and fixed**

| Date | Leak/error | Cause | Fix (commit) | Proof |
|------|-----------|-------|--------------|--------|
| 21/09| none| n/a |n/a |==332== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
