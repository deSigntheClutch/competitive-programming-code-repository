# Competitive Programming Code Repository

Solutions and templates from various competitive programming judges and contests.
Mostly C++, with some Rust (recent AtCoder rounds).

## Layout

One folder per contest; solution files are named by problem letter (`A.cpp`, `B.cpp`, …).

| Folder | Contents |
|---|---|
| `Atcoder/` | AtCoder Beginner / Regular / Grand Contests (C++ and Rust) |
| `Codeforces/` | Codeforces rounds (Div. 1/2, Educational, Global) |
| `Codeforces Gym/` | Codeforces Gym contests |
| `Google CodeJam/` | Code Jam & Kick Start |
| `Team USC/` | ICPC team contests (NAC, NAIPC, Pacific Northwest) |
| `Leetcode/`, `CSAcademy/`, `China OI/` | Misc judges |
| `template/` | Algorithm templates: Data Structure, Flow, Geometry, Graph, Math, String |
| `bits-stdcpp-library/` | `bits/stdc++.h` for non-GCC toolchains |

## Building & running

**C++** — most folders have a `Makefile`; `make A` compiles `A.cpp` and runs it:
```sh
make A            # g++ -std=c++11 A.cpp -o A && ./A
```
Or directly:
```sh
g++ -std=c++17 -O2 A.cpp -o A && ./A < input.in
```

**Rust** (AtCoder folders that are Cargo crates) — one binary per problem via `[[bin]]` in `Cargo.toml`:
```sh
cargo run --bin A < input.in
```

## Notes

- `input.in` (local scratch input), build output (`target/`, `cmake-build-*/`),
  and compiled binaries are git-ignored — see `.gitignore`.
- Solutions are for learning/reference; correctness is not guaranteed for every file.
