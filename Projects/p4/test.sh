./blackjack 1000 1 simple > MyResults/001.out
diff -b MyResults/001.out pretest_cases/case1.out >Differs/001.diff
./blackjack 10000 10 simple> MyResults/002.out
diff -b MyResults/002.out pretest_cases/case2.out>Differs/002.diff
./blackjack 5 100 simple> MyResults/003.out
diff -b MyResults/003.out pretest_cases/case3.out>Differs/003.diff
./blackjack 500 100 counting> MyResults/004.out
diff -b MyResults/004.out pretest_cases/case4.out>Differs/004.diff
./blackjack 5000 500 counting> MyResults/005.out
diff -b MyResults/005.out pretest_cases/case5.out>Differs/005.diff

./blackjack 3 500 counting> MyResults/006.out
diff -b MyResults/006.out pretest_cases/case6.out>Differs/006.diff

./blackjack 50 10000 simple> MyResults/007.out
diff -b MyResults/007.out pretest_cases/case7.out>Differs/007.diff

./blackjack 500 100 simple> MyResults/008.out
diff -b MyResults/008.out pretest_cases/case8.out>Differs/008.diff