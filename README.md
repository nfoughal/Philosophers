# 🧠 Philosophers

A multithreaded simulation of the classic **Dining Philosophers** problem. This project is part of the 42 Network curriculum and aims to introduce fundamental concepts of **concurrency**, **mutexes**, and **race condition prevention** using **POSIX threads** in C.

---

## 📜 Overview

Five philosophers sit around a table doing one of three things:

- Thinking 🤔  
- Eating 🍝  
- Sleeping 😴  

They must **pick up two forks** (mutexes) to eat, and release them afterward. The challenge is to:

- Prevent **deadlocks**
- Prevent **race conditions**
- Avoid **starvation**

---

## ⚙️ Usage

### 🔧 Compilation
```bash
make
```

### 🚀 Execution
```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [meals_required]
```

Example:
```bash
./philo 5 800 200 200
```

Optional last argument ensures the simulation stops once all philosophers have eaten the required number of times:
```bash
./philo 5 800 200 200 7
```

---

## 📁 Files & Structure

- `philo.c` - Setup and main loop  
- `actions.c` - Philosopher actions (eat, sleep, think)  
- `monitor.c` - Death check and stopping condition  
- `utils.c` - Time, print, and helpers  
- `philo.h` - Headers and structures  
- `Makefile` - Build automation

---

## 🧪 Testing

Test for leaks and thread issues:
```bash
valgrind ./philo 5 800 200 200
```

Or with thread sanitizer:
```bash
gcc -fsanitize=thread *.c -lpthread
```

## 🎯 Key Concepts

- Mutex locking/unlocking (`pthread_mutex_t`)
- Thread creation and joining (`pthread_create`, `pthread_join`)
- Time management and precision using `gettimeofday()`
- Thread-safe logging and error handling

---

## 👨‍💻 Author

**Nabil Foughali**  
🔗 [GitHub](https://github.com/nfoughal)

---

> 📚 Developed as part of the 42 Network — 1337 Khouribga
