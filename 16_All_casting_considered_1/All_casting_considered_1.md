# All casting considered 1

1. Static cast

```
in ti = 9;
float f = static_cast<float>(i);
Dog dog = static_cast<Dog>(std::string("Bob"));
Dog* pd = static_cast<Dog*>(new Yellowdog()); // down / up cast
```

2. Dynamic cast

```
Dog* pd = new Yellowdog();
Yellowdog* py = dynamic_cast<Yellowdog*>(pd);

```
Can not work on objects	
Converts pointer / ref from one type to related type
Run-time type check. If succeed, py == pd, if fail: py = 0
It requires 2 types to be polymorthic (at least one virtual function)

3. COnst cast

```
const char* str = "Hello";
char* modifiable = const_cast<char*>(str);	
```

Only works on pointers
Only works on same type
Cast away constness of the object being pointed to

4. Reinterpret cast

```
long p = 0x87746246132
Dog* dd = reinterpret_cast<Dog>(p);
```

Reinterprets the bits of object pointed to
Can cast one pointer to any cast of pointers

5. C-Style cast

```
short a = 200;
int i = (int)a; // cast notation
int j = int(a); // functional notation
```

## Preferences

C++ style of cast is preffered
1. Easier to identify in code
2. Less usage error
- Narrowly specified purpose of each cast
- Run-tyme type check