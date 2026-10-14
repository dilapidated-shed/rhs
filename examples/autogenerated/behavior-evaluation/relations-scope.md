# Exact observation relations

These relations interpret an independently declared claim contract, never a variable name. Agreement concerns the supplied executions only. A declared matrix, normal, carrier, order or serializer is an input to the contract, not a meaning inferred from source spelling. Caller justification and executable observations remain separate evidence.

Values: exact integers; comma-separated integer coordinates; semicolon-separated matrix rows; positive common denominators for rational matrices/results; independent immutable state snapshots and canonical decimal UTF-8 serialization in hexadecimal. No floating-point approximation or arbitrary serializer semantics is supported.

Operations: `holds : relation × observation rows → Boolean`, with unsupported schemas raising a domain error and `checker.finding` preserving UNKNOWN. Count relations use nonnegative counts and positive widths. Transformation dimensions are 1–8; rotation matrices are square and at most 6-dimensional. General linear transformations may be rectangular or singular. Reflection is the Euclidean hyperplane reflection with a supplied nonzero normal. Rotation checks an exact rational matrix for orthogonality and determinant +1, then checks its action on supplied input. These algebraic matrix checks do not prove the source implements the transformation for every input.

Array rank, stored coordinate count and mathematical vector dimension are separate fields. `dimensions/scalar-vector` checks an explicit scalar-coordinate encoding; `dimensions/row-vectors` checks an explicit rank-two array of real row vectors. Unsupported carrier/encoding claims remain UNKNOWN.

For example, a 2×3 array has rank two and six stored coordinates. Under a declared flat encoding it represents one point in ℝ⁶; under row encoding it represents two points in ℝ³. Its array rank alone does not establish its mathematical vector dimension.

Call relations compare an independently specified required sequence to recorded calls, count and effect delta. Repeated-call relations require two recorded calls and immutable snapshots. Canonical integer state serialization is supported; universal serialization correctness, unknown encodings and source-wide purity are not claimed.

Implementation extends the established checked-Ithon observation adapter. Native observer fixtures remain execution witnesses, not definitions of the relation. Positive twins, deliberate errors and boundary/unsupported inputs must disagree with a broken checker.
