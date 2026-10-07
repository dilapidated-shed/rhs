# RHS-2: predeclared grounding experiment

This protocol is fixed before any RHS-2 model outputs are inspected. No model is
trained or tuned. Historical results remain unchanged.

## Questions and primary rules

1. **Textual transformation recovery:** nearest cosine to prefix-difference
   prototypes built only from training context bundles. A prefix-only lookup is
   the lexical baseline. It can recover an operation without knowing its meaning.
2. **Full-word meaning correspondence:** classify a held-out abbreviated edge
   against full-word difference prototypes from training bundles, within the
   same model. Compare it with length-matched nonsense prefixes and deliberately
   substituted prefixes. This tests the declared association, not behavior.
3. **Name/computation agreement (primary):** independently classify the name
   and the supplied computation/observation against predeclared textual meaning
   anchors, then predict agreement iff both classifications agree. Primary
   statistic is balanced accuracy, macro-averaged over storage, positions, and
   integer-width families, with abstentions counted as errors. Report ordinary
   counts, each condition, each family, and paired interventions too. No threshold
   is selected from held-out scores; exact cosine ties (1e-12) and zero vectors
   abstain. This is a fixed zero-shot decision rule, not a trained code verifier.

All related examples of one context bundle share a partition. The nine bundles
have distinct paired stems. One bundle per independent semantic family is
training; the other two are held out. This is a small public synthetic corpus,
not a contamination-free claim about model pretraining or general code meaning.
No held-out examples contribute to prototypes. Report family denominators;
multiple names for one computation do not create independent observations.

An additional **whole-facet zero-shot** question withholds element-count from
training prototypes altogether. Its held-out abbreviated/full-word names are
classified using standalone meaning anchors only. This result is separate from
ordinary context holdout; training context data contain no element-count edges.

## Ground truth and inputs

Independent meanings are fixed in `primitives.tsv`. Computations in `fixtures.pi`
produce their own expected values; labels never come from the encoder. Storage
distinguishes element count from byte count (including three four-byte elements:
3 versus 12). No text/character counting is used. Grid indices, rows and columns
are zero based, in row-major order. WORD/DWORD mean unsigned truncation modulo
2¹⁶/2³², independently of host C integer widths. They are type-oriented controls.

Transformation input: literal off/on identifiers only. Meaning correspondence:
literal identifier differences only, compared with training full-word differences.
Agreement conditions: (a) name only, (b) computation plus observed value only,
(c) name and computation plus value together. The primary rule uses (a) and (b)
separately; (c) is an exploratory direct-text comparison against the same anchors.
Name-only agreement is deliberately underdetermined; its baseline predicts agree
for all pairs and obtains balanced accuracy 0.5. Computation-only agreement is
also underdetermined without the name claim. Neither condition receives a truth
label, semantic family identifier, partition label, or answers in its model input.

Each behavior is paired with each plausible claim in its family. Names stay fixed
across changed behaviors; behaviors stay fixed across changed names. Abbreviated,
full-word, and misleading names have declared claims. Nonsense has no independent
claim and is excluded from agreement ground truth; its anchor predictions are
recorded as a diagnostic rather than inventing a meaning.

Prefix variants preserve character length, not guaranteed tokenizer length.
Token IDs, tokens, masks, token lengths and residual matching failures are retained.
Misleading substitutions intentionally put another family's plausible prefix on
the same stem; score both the lexical spelling and the intended replacement label.

## Controls, model space, null

Keep aBcd → aBcD and ABcd → ABcD plus their leading-case square. Retain tokens,
case collapse, exact zero directions, norms, final-layer attention-mask mean pooling
(including special tokens), and the originating model identity. No cross-model
coordinate comparisons. All input lengths are checked; no silent truncation.

The null rotates labels within each family before scoring frozen predictions;
retain every rotation, including the identity separately. This conditional null
preserves class balance and pairing. It is descriptive, not a randomization p-value
for independent observations. Lexical prefix recovery and a name-only always-agree
baseline are reported separately; a deterministic explicit-prefix + observed-value
oracle is an upper-bound fixture control, not model acceptance.

Run CodeBERTa, CodeBERT, MiniLM, BERT cased, BERT uncased at immutable historical
revisions. Resolve and verify each model/tokenizer revision with Hugging Face;
record dependencies, host, source and runtime pins. A download or adapter failure
is UNAVAILABLE, never a negative semantic score or a passing model execution.
Rerun all 28 old edges under their unchanged scorer and final-layer pooling; the
new provider changes revision pinning, checked language, and raw-evidence capture.

## Ownership and evidence

RHS owns meanings, fixtures, scoring, and its task-specific checked Ithon provider.
Ithon owns frontend and foreign-library checking. Cat Food owns runtime lookup;
Flexible Pipes owns the existing command-stage controller and receipts. That
controller is unchanged, explicitly named Python migration debt; model inference
has an additional provider receipt satisfying its model-stage contract. No new
Python shim, compiler, vector database, phone port, or shared geometry API.
Idriç remains the semantic/type-system owner; this experiment does not reimplement
its geometry or claim dependent proofs from floating-point embedding coordinates.

Deterministic PR checks run without downloads; heavyweight model runs use separate
GitHub Ubuntu jobs. Raw inputs, partitions, tokens, vectors, score candidates,
predictions and failures must be retained so reports can be recomputed offline.
