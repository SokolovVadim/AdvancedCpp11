# Code reuse: inheritance vs composition

## Code reuse with inheritance: Names

1. Bad example

```
class BaseDog{
	... // common activities
};

class BullDog: public BaseDog{
	... // Call the common activities to perform more tasks
};

class ShepherdDog: public BaseDog{
	... // Call the common activities to perform more tasks
};
```

2. Good example

```
class Dog{
	... // common activities
};

class BullDog: public Dog{
	... // Call the common activities to perform more tasks
};

class ShepherdDog: public Dog{
	... // Call the common activities to perform more tasks
};
```

Precise and self-explaining names for classes.

## Code reuse with composition

```
class ActivityManager{
	... // common activities
};

class Dog{
	...
};

class BullDog: public Dog{
	ActivityManager* pActMngr;
	... // Call the common activities to perform more tasks
};

class ShepherdDog: public Dog{
	ActivityManager* pActMngr;
	... // Call the common activities to perform more tasks
};
```

## Composition is better than inheritance

1. Less code coupling between reused code and reuser of the code
a. Child class automatically inherits ALL parent class' public members
b. Child class can access parent's protected members

#### Inheritance breaks encapsulation

2. Dynamic binding
a. Inheritance is bound at compile time
b. Composition can be bound either at compile time or at run time

3. Composition has flexible code constructions

Dog           ActivityManager

BullDog       OutdoorActivityManager
ShepherdDog   IndoorActivityManager
...           ...

```
class OutdoorActivityManager: public ActivityManager{};

class IndoorActivityManager:  public ActivityManager{};
```
