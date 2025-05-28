# Pointers

## Function pointers

<details>
<summary>View contents</summary>

A **function pointer** is just a **variable that stores the address of a function**, so you can **call the function later** or **pass it to another function**.

👉 Think of it like a remote control:

* Instead of calling the function directly, you give someone the remote (pointer), and they decide when to press the button (call the function).

---

## ✅ Example: Basic Function Pointer

```c
#include <stdio.h>

void greet(void) {
    printf("Hello!\n");
}

int main(void) {
    void (*fptr)(void);  // declare a function pointer
    fptr = greet;        // store address of greet in fptr
    fptr();              // call greet through the pointer
    return 0;
}
```

---

### 🧠 **Treat behavior as data**

You're passing **what to do** (the function) to another function, just like you pass values like `int` or `char`.

---

## 🔧 When and Why We Use Function Pointers

### 1. **Callbacks**

You let a function caller provide custom logic.

```c
void run_callback(void (*cb)(void)) {
    cb(); // call the function passed in
}
```

✅ Example:

```c
void hello() { printf("Hello\n"); }
void bye() { printf("Bye\n"); }

run_callback(hello); // prints "Hello"
run_callback(bye);   // prints "Bye"
```

---

### 2. **Higher-order behavior (like sorting with custom logic)**

```c
int compare_ints(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

qsort(arr, n, sizeof(int), compare_ints); // pass comparison logic
```

✅ You pass the comparison function as a pointer to `qsort`.

---

### 3. **Plug-and-play design (strategy pattern)**

You can switch between behaviors at runtime by passing different functions.

```c
typedef void (*strategy_t)(void);

void execute(strategy_t s) {
    s(); // execute the chosen strategy
}
```

---

### 4. **State machines / command dispatchers**

You can store an array of function pointers to implement a dispatcher.

```c
void state_idle(void) { puts("Idle"); }
void state_running(void) { puts("Running"); }

void (*state_handlers[2])(void) = { state_idle, state_running };

state_handlers[0](); // calls state_idle
```

---

### 5. **Custom implementations: map/reduce/filter style programming**

You can pass a function to operate on each element of an array.

### 🔁 `map`: Apply a function to each element

```c
void map(int *arr, int size, int (*func)(int)) {
    for (int i = 0; i < size; i++) {
        arr[i] = func(arr[i]);
    }
}

int square(int x) {
    return x * x;
}
```

---

### 🎯 `filter`: Keep elements that match condition

```c
int filter(int *src, int *dst, int size, int (*cond)(int)) {
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (cond(src[i])) {
            dst[j++] = src[i];
        }
    }
    return j; // number of elements in dst
}

int is_even(int x) {
    return x % 2 == 0;
}
```

---

### 🔻 `reduce`: Combine all elements into one value

```c
int reduce(int *arr, int size, int (*func)(int, int), int initial) {
    int result = initial;
    for (int i = 0; i < size; i++) {
        result = func(result, arr[i]);
    }
    return result;
}

int sum(int a, int b) {
    return a + b;
}
```

---

## 🚀 Example: Putting It All Together

```c
#include <stdio.h>

void print_array(const char *label, int *arr, int size) {
    printf("%s: ", label);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result[5];

    // map
    map(arr, size, square);
    print_array("Mapped (squared)", arr, size);

    // filter
    int new_size = filter(arr, result, size, is_even);
    print_array("Filtered (even)", result, new_size);

    // reduce
    int total = reduce(arr, size, sum, 0);
    printf("Reduced (sum): %d\n", total);

    return 0;
}
```

---

## ✅ Output

```
Mapped (squared): 1 4 9 16 25 
Filtered (even): 4 16 
Reduced (sum): 55
```

---

> Function pointers = **pass behavior like data** → more flexible, reusable, and modular code.

</details>