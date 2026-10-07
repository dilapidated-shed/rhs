# Execution attempts

The experiment was preregistered at dc89a8185f717205fde0f822cc0800f60b5a44ae.
No model scores were inspected before the protocol was fixed.

- Model workflow run 37573636009 failed workflow validation before creating jobs.
  The job-level runner-context cache expression was replaced with a fixed /tmp
  cache path. This produced no semantic result.
- Deterministic run 37573637012 downloaded the exact Grease artifact, but the
  download action nested it under its artifact name. Runtime lookup rejected the
  absent declared file. The action now explicitly merges the single artifact into
  the declared directory. This produced no model result and was not a Grease
  language failure.
- Local qualification used the same executable SHA-256, whole-module Ithon checks,
  15 preserved legacy tests, and real Flexible Pipes → Grease → Ithon execution.
  Foreign result typing required explicit boundaries. Unsupported Unicode minus
  was kept out of Ithon source; ordinary subtraction is used. No frontend was
  weakened and no Python shim was added.
