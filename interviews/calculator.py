"""
Basic Calculator (Snapchat variant of LeetCode 772 - Basic Calculator III)

Evaluate a string expression containing:
  - non-negative integer literals
  - binary operators + - * /
  - unary minus / plus (e.g. "-2", "2*(-3)", "-(3+2)", "7/-3")
  - parentheses ( )

Rules:
  - Standard precedence: * and / bind tighter than + and -.
  - Division truncates toward zero: 5/2 == 2, -7/3 == -2.
  - The input is always a valid expression.

Approach — single left-to-right scan, a running stack, recursion for parens:
  * Keep a `stack` of terms; the value of an expression is sum(stack).
    +  -> push v            -  -> push -v
    *  -> pop, *v, push      /  -> pop, trunc-div by v, push   (eager => higher precedence)
  * `op` is the binary operator preceding the current operand; it is applied
    (flushed) only when we reach the NEXT binary operator, a ')', or the end.
  * Unary +/-: a '+' or '-' seen where an OPERAND is expected (at the start,
    right after '(' , or right after another binary operator) is a sign, not a
    binary op. We fold it into `sign`, which multiplies the next operand. This
    is why "7/-3" works: the '-' after '/' sets sign=-1 instead of flushing '/'
    against a zero operand.
  * '(' recurses; the call returns (value, index_of_matching_')').

Time  O(n) — each char visited once.
Space O(d) — recursion depth = parenthesis nesting depth.
"""


class Solution:
    def calculate(self, s: str) -> int:
        n = len(s)

        def helper(i: int) -> tuple[int, int]:
            stack: list[int] = []
            num = 0
            sign = 1  # sign of the operand currently being built (for unary +/-)
            op = "+"  # pending binary operator to apply on flush
            expect_operand = True  # True when a +/- here would be unary

            def flush(value: int) -> None:
                if op == "+":
                    stack.append(value)
                elif op == "-":
                    stack.append(-value)
                elif op == "*":
                    stack.append(stack.pop() * value)
                elif op == "/":
                    # int() truncates toward zero (// would floor).
                    stack.append(int(stack.pop() / value))

            while i < n:
                c = s[i]

                if c.isdigit():
                    num = num * 10 + int(c)
                    expect_operand = False
                elif c == "(":
                    # Sub-expression value; i lands on the matching ')'.
                    num, i = helper(i + 1)
                    expect_operand = False
                else:  # one of + - * / )
                    if c in "+-" and expect_operand:
                        # Unary sign, not a binary operator.
                        if c == "-":
                            sign = -sign
                    else:
                        flush(sign * num)
                        if c == ")":
                            return sum(stack), i
                        op = c
                        num = 0
                        sign = 1
                        expect_operand = True

                i += 1

            flush(sign * num)  # flush the final operand
            return sum(stack), i

        return helper(0)[0]


# ---------------------------------------------------------------------------
# Tests
# ---------------------------------------------------------------------------

def _run_tests() -> None:
    solve = Solution().calculate

    cases: list[tuple[str, int]] = [
        # --- from the problem statement ---
        ("10+(-2)*3", 4),
        ("6/(-2)", -3),
        ("-2+8/2", 2),
        # --- unary minus in various positions ---
        ("2*(-3)", -6),
        ("-4/2", -2),
        ("-(3+2)", -5),
        ("-2", -2),
        ("(-2)", -2),
        # --- unary sign right after * or / (no parens) ---
        ("7/-3", -2),
        ("-7/-3", 2),
        ("2*-3", -6),
        # --- truncation toward zero ---
        ("5/2", 2),
        ("-7/3", -2),
        # --- precedence & basics ---
        ("3+2*2", 7),
        ("3/2", 1),
        ("3+5/2", 5),
        ("2*3+4", 10),
        ("2+3*4-6/2", 11),
        # --- parentheses / nesting ---
        ("(1+2)*3", 9),
        ("2*(5-(3+1))", 2),
        ("((2+3)*(4-1))", 15),
        ("(2+6*(3-2))/2", 4),
        ("-(-(-5))", -5),
        # --- single number / large multi-digit ---
        ("42", 42),
        ("100*100", 10000),
        # --- chained same-precedence (left to right) ---
        ("100/10/2", 5),
        ("2-3-4", -5),
        ("8/3*3", 6),
    ]

    passed = 0
    for expr, expected in cases:
        got = solve(expr)
        ok = got == expected
        passed += ok
        mark = "PASS" if ok else "FAIL"
        print(f"[{mark}]  {expr!r:<24} -> got {got!r:>6}  expected {expected!r:>6}")
        assert ok, f"FAILED: {expr!r} -> {got}, expected {expected}"

    print(f"\nAll {passed}/{len(cases)} tests passed!")


if __name__ == "__main__":
    _run_tests()
