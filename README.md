Comparable interface for PHP
============================

Note: This is to the most part just code demonstrating the implementation of a magic interface for
a tutorial. I do not currently plan on proposing including such an interface for PHP itself.

This extension implements a magic `Comparable` interface for PHP:

    interface Comparable {
        static function compare($obj1, $obj2);
    }

When two objects in the same inheritance chain are compared using `<`, `>` or `==` the `compare()`
method will be invoked (on the class that is further down the interitance chain).

The `compare()` method can either return `null` to fall back to the default comparison behavior
or one of the integer values `-1` (for "smaller"), `0` (for "equal") and `1` (for "greater"). If
the returned value is not an integer, it will be cast to one. If it is not one of -1, 0 or 1 it
will be normalized to them.

An example (not sure how much sense it makes):

```php
<?php

class Point implements Comparable {
    protected $x, $y, $z;

    public function __construct($x, $y, $z) {
        $this->x = $x; $this->y = $y; $this->z = $z;
    }

    public static function compare($p1, $p2) {
        if ($p1->x == $p2->x && $p1->y == $p2->y && $p1->z == $p2->z) {
            return 0;
        }

        if ($p1->x < $p2->x && $p1->y < $p2->y && $p1->z < $p2->z) {
            return -1;
        }

        if ($p1->x > $p2->x && $p1->y > $p2->y && $p1->z > $p2->z) {
            return 1;
        }

        return 1;
    }
}

$p1 = new Point(1, 1, 1);
$p2 = new Point(2, 2, 2);
$p3 = new Point(1, 0, 2);

var_dump($p1 < $p2, $p1 > $p2, $p1 == $p2); // true, false, false

var_dump($p1 == $p1); // true

var_dump($p1 < $p3, $p1 > $p3, $p1 == $p3); // false, false, false
```

Installation
------------

The extension is installed as usual:

    ./configure --enable-comparable
    make
    make install
