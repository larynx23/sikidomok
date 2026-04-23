# Terv - Síkidomok
Vadoba Hunor

## 1. Feladatkörök:
- Parancsok feldolgozása (`CommandParser`).
- Alakzatok reprezentálása (`Shape` hierarchia).
- Alakzatok tárolása és kezelése (`ShapeManager`).
- Geometriai műveletek: `area()`, `perimeter()`, `contains(vector)` `Vector`.

## 2. UML osztálydiagram

```mermaid
classDiagram
    class Vector {
        -double x
        -double y
        +Vector(double x, double y)
        +double length()
        +Vector operator+(const Vector& v)
        +Vector operator-(const Vector& v)
        +Vector operator*(double s)
        +double operator*(const Vector& v)
        +bool operator==(const Vector& v)
    }

    class Shape {
        <<abstract>>
        -string name
        -Vector C
        +Shape(string name, Vector C)
        +virtual double area()
        +virtual double perimeter()
        +virtual bool contains(Vector v)
    }

    class Circle {
        -double R
        +Circle(string name, Vector C, Vector V)
        +double area()
        +double perimeter()
        +bool contains(Vector v)
    }

    class Triangle {
        -Vector[3] vertices
        +Triangle(string name, Vector C, Vector V)
        +double area()
        +double perimeter()
        +bool contains(Vector v)
    }

    class Square {
        -Vector[4] vertices
        +Square(string name, Vector C, Vector V)
        +double area()
        +double perimeter()
        +bool contains(Vector v)
    }

    class ShapeManager {
        -Shape** shapes
        -size_t len
        -size_t capacity 
        +bool addShape(Shape* s)
        +bool deleteShape(string name)
        +Shape* find(string name)
        +Vector list()
    }

    class CommandParser {
        +ShapeManager &mgr
        +CommandParser(ShapeManager &m)
        +void handle(string line)
    }

    Vector *-- Shape
    Shape <|-- Circle
    Shape <|-- Triangle
    Shape <|-- Square
    ShapeManager --* Shape
    CommandParser --* ShapeManager
```

## 3. Osztályok részletei
- `Vector` : `(x,y)` egyszerű adattároló, vektorműveletekkel.
- `Shape` : absztrakt osztály, virtuális függvényekkel.
- Egyszerű terület/kerület képlet a síkidomokhoz. ($\pi r^2, 2r\pi,$ $a^{2}\sqrt{3}\over4$ $,\dots$)
- Konstruktorok,($C, V$: középpont és egy csúcs/kerületi pont.)
- `Circle`: egyszerű, `R = dist(C,V)`.
- `Triangle`: a három csúcsot a C körül $60^\circ$ szögeloszlással számoljuk ki
- `Square`: $V$ a négyzet egyik csúcsa; a négy csúcs kiszámolható $C$ és $V$ alapján (forgás + tükrözés).

## 4. Pont helyzet eldöntése (.contains(v))
Poliginok oldalai ngybetűvel, sorban jelölve ($A,B, C, \dots$), kérdéses pont ($v$), középpont ($C$).

`Circle`: 
- $dist(C,v) \le R$

`Triangle`: 
- Előjeles keresztszorzással megállapítható hogy a pont az egyik oldalvektor jobb, vagy bal oldalán található.
- Ha mindegyik oldaltól csak jobbra, vagy csak balra található, a síkidomon belül helyezkedik el (az oldalvektorok egy körben egymásra mutatnak).
- Egy előjel eldöntése: $\overrightarrow{AB} \times (A-v) < 0$
  
`Square`: 
- Két szomszédos oldal derékszöget zár be egymással. Ezek lineáris kombinációjaként felírható $v$, mivel az oldalak bázist alkotnak $\mathbb{R}^2$-ben.
- $v = x \cdot \overrightarrow{BA} + y \cdot \overrightarrow{BC}$
- Ha $0 < x < 1$ és $0 < y < 1$, $v$ a négyzeten belül van.


## 5. Parancsfeldolgozás - rövid felvázolás
- `CommandParser::handle(line)` tokenizálja a sorokat (szóközzel), majd switch/case a parancsokra (`add`, `list`, `delete`, `contains`, `area|a`, `perimeter|v`, `load`).
- Amennyiben nem talál mgfelelő parancsot, megfelelő hibát ír.
