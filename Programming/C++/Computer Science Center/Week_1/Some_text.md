### Целочисленные типы в C++

Все целочисленные типы (кроме char) являются знаковыми. Беззнаковые версии типов определяется с ключевым словом unsigned, например: unsigned short int, unsigned int или unsigned long int. Для симметрии в языке предусмотрено явное указание того, что тип является знаковым — ключевое слово signed (используется редко).


Более того, C++ допускает использование следующих сокращений:

* unsigned вместо unsigned int,
* short вместо short int,
* long вместо long int.

Тип char в языке C++ является особенным: стандарт не оговаривает является ли тип char знаковым или беззнаковым — это зависит от компилятора. Если вам нужна именно беззнаковая версия используйте unsigned char явно, если же вам нужна знаковая используйте signed char. При этом все три типа (char, unsigned char, signed char) являются тремя различными типами.

**Операции инкремента и декремента**
```
int a = 10; // a = 10
int b = ++a; // префиксный инкремент возвращает новое значение => b = 11 и a = 11
int c = a++; // постфиксный инкремент возвращает старое значение => с = 11 и a = 12
```

### Преобразование встроенных типов в операторах

Выражениям так же как и значениям в C++ приписывается некоторые типы. Например, если a и b — это переменные типа int, то выражения (a + b), (a - b), (a * b) и (a / b) тоже будут иметь тип int. 

Важно всегда понимать, какой тип у выражения, которое вы написали в программе. Давайте проиллюстрируем это на следующем примере:
```
int a = 20;
int b = 50;
double d = a / b;  // d = 0, оба аргумента целочисленные, а значит деление целочисленное 
```
Как исправить этот код, чтобы получить вещественное значение в переменной d? 

Для этого хотя бы один из аргументов оператора деления должен иметь типа double. Этого можно добиться при помощи уже известного нам оператора приведения типов:
```
double d = (double)a / b;  // d = 0.4
```
Почему это сработало? Дело в том, что операторы для встроенных типов C++ **всегда** работают с **одинаковыми типами аргументов**. Если аргументы имеют разные типы, то происходит преобразование типов (promotion).

**Правило преобразования встроенных типов в операторах**
Рассмотрим выражение (a + b), где вместо '+' может стоять любой другой подходящий оператор.
    * Если один из аргументов имеет числовой тип с плавающей точкой, то второй аргумент приводится к этому типу (например, при сложении double и int значение типа int приводится к double). 
    * Если оба аргумента имеют числовой тип с плавающей точкой, то выбирается наибольший из этих типов (например, при сложении double и float значение типа float приводится к double)
    * Если оба аргумента целочисленные, но их типы меньше int, то оба аргумента приводятся к типу int (например, при сложении двух значений типа char они оба сначала приводятся к int).
    * Если оба аргумента целочисленные, то аргумент с меньшим типом приводится к типу второго аргумента (например, при сложении long и int значение типа int приводится к long).
    * Если оба аргумента целочисленные и имеют тип одного размера, то предпочтение отдаётся беззнаковому типу (например, при сложении int и unsigned int значение типа int приводится к unsigned int).

**Несколько важных следствий**
    * Следите за тем, какие типы участвуют в выражении, от этого может зависеть его значение.
    * Не стоит использовать целочисленные типы меньше int в арифметических выражениях, они всё равно будут приведены к int.
    * **Не стоит смешивать unsigned и signed типы** в одном выражении, это может привести к неприятным последствиям.
Для иллюстрации последнего следствия давайте рассмотрим следующий пример:
```
unsigned from = 100;
unsigned to = 0;
for (int i = from; i >= to; --i) {  ....  }
```
Сколько итераций сделает этот цикл? На самом деле этот цикл — бесконечный: в условии цикла проверяется i >= to, где тип i — int, а тип to — unsigned int. Так как операторы всегда применяются к одинаковым встроенным типам, то в данном случае значение переменной i (в соответствии с правилом 5) будет преобразовано к unsigned int, а значения этого типа **всегда** неотрицательны, т.е. >= 0. Другими словами, когда пременная i станет равной -1, то в условии будет проверяться (unsigned)-1 >= 0, где  (unsigned)-1 = UINT_MAX (UINT_MAX — максимальное значение, которое может принимать переменная типа unsigned int).