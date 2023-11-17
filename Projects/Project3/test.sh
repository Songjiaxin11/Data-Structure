#!/bin/bash
./p3 species world-tests/outside-world 1 > out/outside-world.out
diff out/outside-world.out world-tests/outside-world.answer > out/diff/diffResult-outside.txt
./p3 species world-tests/overlap-world 1 > out/overlap-world.out
diff out/overlap-world.out world-tests/overlap-world.answer >> out/diff/diffResult-overlap.txt
./p3 species world-tests/world1 5 > out/world1-c.out
diff out/world1-c.out world-tests/world1-concise.answer >> out/diff/diffResult-world1-concise.txt
./p3 species world-tests/world1 5 v > out/world1-v.out
diff out/world1-v.out world-tests/world1-verbose.answer >> out/diff/diffResult-world1-verbose.txt
./p3 species world-tests/world2 20 > out/world2-c.out
diff out/world2-c.out world-tests/world2-concise.answer >> out/diff/diffResult-world2-concise.txt
./p3 species world-tests/world2 20 v > out/world2-v.out
diff out/world2-v.out world-tests/world2-verbose.answer >> out/diff/diffResult-world2-verbose.txt
./p3 species world-tests/world3 40 > out/world3-c.out
diff out/world3-c.out world-tests/world3-concise.answer >> out/diff/diffResult-world3-concise.txt
./p3 species world-tests/world3 40 v > out/world3-v.out
diff out/world3-v.out world-tests/world3-verbose.answer >> out/diff/diffResult-world3-verbose.txt