# Exact observation relations

These relations interpret an independently declared claim contract, never a variable name. Agreement concerns the supplied executions only. A declared matrix, normal, carrier, order or serializer is an input to the contract, not a meaning inferred from source spelling. Caller justification and executable observations remain separate evidence.

Values: exact integers; comma-separated integer coordinates; semicolon-separated matrix rows; positive common denominators for rational matrices/results; independent immutable state snapshots and canonical decimal UTF-8 serialization in hexadecimal. No floating-point approximation or arbitrary serializer semantics is supported.

Operations: `holds : relation × observation rows → Boolean`, with unsupported schemas raising a domain error and `checker.finding` preserving UNKNOWN. Count relations use nonnegative counts and positive widths. Transformation dimensions are 1–8; rotation matrices are square and at most 6-dimensional. General linear transformations may be rectangular or singular. Reflection is the Euclidean hyperplane reflection with a supplied nonzero normal. Rotation checks an exact rational matrix for orthogonality and determinant +1, then checks its action on supplied input. These algebraic matrix checks do not prove the source implements the transformation for every input.

Array rank, stored coordinate count and mathematical vector dimension are separate fields. `dimensions/scalar-vector` checks an explicit scalar-coordinate encoding; `dimensions/row-vectors` checks an explicit rank-two array of real row vectors. Unsupported carrier/encoding claims remain UNKNOWN.

For example, a 2×3 array has rank two and six stored coordinates. Under a declared flat encoding it represents one point in ℝ⁶; under row encoding it represents two points in ℝ³. Its array rank alone does not establish its mathematical vector dimension.

Call relations compare an independently specified required sequence to recorded calls, count and effect delta. Repeated-call relations require two recorded calls and immutable snapshots. Canonical integer state serialization is supported; universal serialization correctness, unknown encodings and source-wide purity are not claimed.

Implementation extends the established checked-Ithon observation adapter. Native observer fixtures remain execution witnesses, not definitions of the relation. Positive twins, deliberate errors and boundary/unsupported inputs must disagree with a broken checker.

## Exact oriented affine hyperplane contracts

The following three relations are supported for **declared finite observations**,
not inferred meanings of names. Point and normal have matching integer
coordinates (dimension 1–8); the normal must be nonzero. The offset is an
integer. Side is encoded as −1 (negative), 0 (on the plane), or +1 (positive),
with the positive side defined by normal·point + offset > 0.

- `hyperplane/affine-side`: input `point`, `normal`, `offset` and observed
  `side`. The exact sign must match the reported side.
- `hyperplane/scale-and-side`: add nonzero integer `scale`,
  `scaled.normal`, `scaled.offset`, `side.before`, and `side.after`.
  The coefficients must be scaled by precisely the declared factor. A positive
  factor preserves the oriented side; a negative factor reverses nonzero signs,
  without changing the zero set.
- `hyperplane/orthogonal-frame`: add a square rational orthogonal matrix,
  encoded as semicolon-separated `basis.numerators` and positive
  `basis.denominator`. The two observed transformed numerator vectors,
  `point.after.numerators` and `normal.after.numerators`, share the same
  denominator. Both point and normal must be transformed consistently;
  the offset does not change. Recorded `side.before` and `side.after`
  must agree. Dimensions 1–6, including orientation-reversing orthogonal
  transformations, are supported.

All checks use integer arithmetic; none tests approximate angles. Malformed
dimensions, missing observations, a zero normal, or zero scaling are UNKNOWN.
A fully specified, nonorthogonal matrix or false reported side is a
contradiction. Exact checks concern only the recorded point, not an entire
program.

The repository-local positive/negative tests are **static checker controls**.
They are not compiled native witnesses and are not independently admitted by
AI-CI. The previously accepted 20 native case pairs remain unchanged. Native
evidence for these new relations requires separate executable producers and
independent reconstruction in the AI-CI verifier.
