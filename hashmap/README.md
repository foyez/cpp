# Hashmap

In C, there's no built-in hash map like in JavaScript ({}) or Python (dict), but we can implement similar behavior using:

---

One of the best approaches to mimic a hash map in C:

## 1. **Static arrays (for small, fixed key domains like ASCII)**

Great for problems like character frequency/counting.

```c
int freq[256] = {0};  // Keys: ASCII codes (0–255), Values: counts or flags
freq['a']++;          // Increment count for character 'a'
```

✔️ _Best for: character lookups, flags, simple mappings with small key ranges._

---

### 🔹 1. **ASCII character frequency (all 256 ASCII values)**

```c
int freq[256] = {0};  // For all characters

char *str = "Hello World!";
for (int i = 0; str[i]; i++)
    freq[(unsigned char)str[i]]++;

printf("Count of 'o': %d\n", freq['o']);  // Output: 2
```

✔️ Use when: You need to count all possible characters (including punctuation, control chars, etc.)

---

### 🔹 2. **Lowercase English letters only (`a`–`z`)**

```c
int freq[26] = {0};

char *str = "banana";
for (int i = 0; str[i]; i++)
    if (str[i] >= 'a' && str[i] <= 'z')
        freq[str[i] - 'a']++;

printf("Count of 'a': %d\n", freq['a' - 'a']);  // Output: 3
```

✔️ Use when: You are only dealing with lowercase letters.

---

### 🔹 3. **All English letters (`a`–`z`, `A`–`Z`)**

```c
int freq[52] = {0};

char *str = "AbBaCc";
for (int i = 0; str[i]; i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
        freq[str[i] - 'a']++;
    else if (str[i] >= 'A' && str[i] <= 'Z')
        freq[str[i] - 'A' + 26]++;
}

printf("Lowercase 'a': %d\n", freq['a' - 'a']);      // Output: 1
printf("Uppercase 'A': %d\n", freq['A' - 'A' + 26]); // Output: 1
```

✔️ Use when: You care about letter **case sensitivity**.

---

### 🔹 4. **Digits only (`0`–`9`)**

```c
int freq[10] = {0};

char *str = "a1b2c3d1";
for (int i = 0; str[i]; i++)
    if (str[i] >= '0' && str[i] <= '9')
        freq[str[i] - '0']++;

printf("Count of '1': %d\n", freq[1]);  // Output: 2
```

✔️ Use when: You're analyzing or validating numeric characters.

---

### 🔹 5. **Hex digits (`0`–`9`, `a`–`f`, `A`–`F`)**

```c
int freq[16] = {0};

char *str = "1aA2fF";
for (int i = 0; str[i]; i++) {
    char c = str[i];
    if (c >= '0' && c <= '9')
        freq[c - '0']++;
    else if (c >= 'a' && c <= 'f')
        freq[c - 'a' + 10]++;
    else if (c >= 'A' && c <= 'F')
        freq[c - 'A' + 10]++;
}

printf("Count of 'f' or 'F': %d\n", freq[15]);  // Output: 2
```

✔️ Use when: You're parsing hex strings.

---

### 🔹 6. **Letter pair comparison (e.g., is anagram?)**

```c
int freq[26] = {0};

char *s1 = "listen", *s2 = "silent";
for (int i = 0; s1[i]; i++) freq[s1[i] - 'a']++;
for (int i = 0; s2[i]; i++) freq[s2[i] - 'a']--;

int is_anagram = 1;
for (int i = 0; i < 26; i++) {
    if (freq[i] != 0) {
        is_anagram = 0;
        break;
    }
}

printf("Are anagrams: %s\n", is_anagram ? "yes" : "no");
```

✔️ Use when: Comparing character distributions efficiently.

---
