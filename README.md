
# 😺 Kucing v0.1.0 🐾

Kucing is a lightweight interpreted programming language inspired by C, Python, and BASIC, with a feline twist.

## 🚀 Features (v0.1.0)
- Variable assignment with math
  ```kucing
  let x = 2 + 3;
  ```
- Printing
  ```kucing
  print("Hello");
  print(x);
  ```
- Function definition & call
  ```kucing
  function greet {
      print("Meow!");
  }

  greet();
  ```
- Conditional expressions (`if x > 2 { ... }`)
- `for` loops with custom syntax: `for i from 0 to 5 step 1 { ... }`

## ⚙️ Running Code

Compile:
```bash
gcc src/*.c -Iinclude -o kucing
```

Run a `.kc` file:
```bash
./kucing hello.kc
```

---

## 🔄 How Kucing Compares

| Feature        | C        | Python     | Kucing     |
|----------------|----------|------------|------------|
| Static typing  | Yes      | No         | No         |
| Braces `{}`    | Yes      | No         | Yes        |
| Semicolons     | Yes      | Optional   | Yes        |
| Decl: `int x`  | Yes      | `x = 5`    | `let x = 5` |
| Easy loops     | No       | Yes        | Yes        |
| Function call  | `foo()`  | `foo()`    | `foo();`    |

---

## 🧬 C Lineage

Kucing is implemented in C, just like the original **Python interpreter (CPython)**.

Many great languages — including Python, Lua, and Kucing — are written in C and interpret their own source syntax. This gives Kucing:

- Fast, portable execution
- Fine control over memory and flow
- Direct access to C-style parsing and evaluation

You’re not just using a new language — you’re standing on the shoulders of C giants. 🧱🐱

---

## 📁 File Type & Branding

- Source file extension: `.kc` (Kucing Code) 🐾
- Interpreter mascot: 😺
- Source file icon: 🐾
- Terminal output splash:
  ```
  😺 KUCING v0.1.0 🐾
  ```

---

More features coming soon! 🐈‍⬛


---

## 📣 Pronunciation

**Kucing** is pronounced **"koo-ching"**, like the sound of a curious cat triggering a terminal command.

---

## 🧪 Test File

Run the included `test.kc` file to try out Kucing's syntax and logic:

```bash
./kucing test.kc
```

It demonstrates basic loops, printing, and syntax structure.
