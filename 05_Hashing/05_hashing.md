Yes. These three are **hashing techniques** used to convert a key into a **hash table index**.

The basic idea is:

> We have a key (number/string), and we need to decide **where to store it in a hash table**.

---

# 1. What is Hashing?

Suppose you have these numbers:

```text
23, 45, 12, 37, 18
```

and you have a table with 10 positions:

```text
Index:
0  1  2  3  4  5  6  7  8  9
```

Instead of searching through all numbers, we use a **hash function** to calculate where each number should go.

For example:

```text
key = 23

hash(23) = 3
```

So we store 23 at index 3:

```text
0  1  2  3  4  5  6  7  8  9
         ↓
        23
```

Another:

```text
hash(45) = 5
```

So:

```text
0  1  2  3  4  5  6  7  8  9
         23       45
```

The function that converts the key into an index is called a **hash function**.

---

# 2. Why do we need hashing?

Imagine you have:

```text
10,000 numbers
```

and you want to find whether `739` exists.

Without hashing, you might have to search:

```text
1 → 2 → 3 → 4 → ... → 739
```

With hashing:

```text
739
 ↓
hash function
 ↓
index 9
 ↓
check table[9]
```

So we can potentially find it very quickly.

---

# 3. Division Method

This is probably the **simplest hashing method**.

### Formula

\[
h(k) = k \% m
\]

Where:

- `k` = key
- `m` = size of hash table
- `h(k)` = index

---

### Example

Suppose:

```text
Hash table size = 10
Key = 37
```

Then:

```text
h(37) = 37 % 10
      = 7
```

So `37` goes to index `7`.

```text
Index:  0  1  2  3  4  5  6  7  8  9
                              ↑
                             37
```

Another example:

```text
Key = 52

52 % 10 = 2
```

So:

```text
Index:  0  1  2  3  4  5  6  7  8  9
         ↑
        52
```

### Multiple keys

Suppose:

```text
23, 45, 12, 37, 18
```

Using:

```text
h(k) = k % 10
```

we get:

```text
23 % 10 = 3
45 % 10 = 5
12 % 10 = 2
37 % 10 = 7
18 % 10 = 8
```

Therefore:

```text
Index    Value
----------------
0
1
2        12
3        23
4
5        45
6
7        37
8        18
9
```

---

# 4. Problem: Collision

What happens if:

```text
23 % 10 = 3
33 % 10 = 3
43 % 10 = 3
```

All three want index `3`.

```text
23 ──┐
33 ──┼──→ index 3
43 ──┘
```

This is called a **collision**.

A collision occurs when:

> Two or more keys produce the same hash index.

There are techniques like **chaining** and **open addressing** to handle collisions.

---

# 5. Folding Method

Now let's look at the **folding method**.

The basic idea:

> Break the key into smaller parts, then add those parts together.

### Example

Suppose:

```text
Key = 12345678
```

Break it into groups:

```text
12 | 34 | 56 | 78
```

Add them:

```text
12 + 34 + 56 + 78 = 180
```

If our hash table has size `10`:

```text
180 % 10 = 0
```

Therefore:

```text
hash(12345678) = 0
```

---

### Another example

Key:

```text
123456
```

Divide into groups:

```text
12 | 34 | 56
```

Add:

```text
12 + 34 + 56 = 102
```

If table size = 10:

```text
102 % 10 = 2
```

So:

```text
123456 → index 2
```

### Illustration

```text
123456
  ↓
12 | 34 | 56
 ↓    ↓    ↓
12 + 34 + 56
      ↓
     102
      ↓
   % table size
      ↓
      2
```

So the hash index is `2`.

---

# 6. Mid-Square Method

This one is slightly more interesting.

The idea is:

> **Square the key and take the middle digits of the result.**

That's why it's called **mid-square**.

### Example

Suppose:

```text
Key = 123
```

Square it:

```text
123² = 15129
```

Now take the middle digits.

```text
1 5 1 2 9
  ↑ ↑
  1 2
```

So:

```text
hash(123) = 12
```

If your hash table has size 10, you could then do:

```text
12 % 10 = 2
```

So index:

```text
2
```

---

### Another example

Take:

```text
Key = 44
```

Square:

```text
44² = 1936
```

Middle digits:

```text
19 36
   ↑
   93? 
```

Be careful here: for an even-length result, you need to define how many middle digits your hash function uses. For a simple example, taking the middle two digits gives:

```text
1936
 ↑↑
 93
```

So:

```text
hash = 93
```

If table size is 10:

```text
93 % 10 = 3
```

Therefore:

```text
44 → index 3
```

The exact number of middle digits depends on the hash table size/design.

---

# 7. Why square the number?

The purpose is to make **different parts of the original key influence the hash value**.

For example:

```text
123
 ↓ square
15129
```

The middle digits are influenced by the entire number.

This can sometimes distribute keys better than simply using the last digit.

---

# 8. Comparison

| Method | Basic idea | Example |
|---|---|---|
| **Division** | `key % table_size` | `37 % 10 = 7` |
| **Folding** | Break key → add parts | `12+34+56=102` |
| **Mid-square** | Square key → take middle digits | `123²=15129 → 12` |

---

# 9. Easy way to remember

### Division

```text
KEY
 ↓
% TABLE SIZE
 ↓
INDEX
```

Example:

```text
37 % 10 = 7
```

### Folding

```text
KEY
 ↓
BREAK INTO PARTS
 ↓
ADD PARTS
 ↓
INDEX
```

Example:

```text
123456
 ↓
12 + 34 + 56
 ↓
102
 ↓
% 10
 ↓
2
```

### Mid-square

```text
KEY
 ↓
SQUARE
 ↓
TAKE MIDDLE DIGITS
 ↓
INDEX
```

Example:

```text
123
 ↓
123² = 15129
 ↓
middle = 12
 ↓
index
```

---

## One important thing for your exam

Don't confuse **hashing** with the **hash array** you were doing earlier in DSA.

When you wrote:

```cpp
int hash[13] = {0};
```

and:

```cpp
hash[arr[i]]++;
```

you were using a **direct-address/frequency array**.

Hashing in the formal DSA sense is when we use a **hash function** to map a potentially large key into a smaller table index:

```text
Large key
   ↓
Hash function
   ↓
Small index
   ↓
Hash table
```

And because multiple keys can map to the same index, we need **collision handling**.