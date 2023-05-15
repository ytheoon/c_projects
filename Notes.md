## Row selection function
f(1-3) = 0
f(4-6) = 1
f(7-9) = 2

row = (int) (userInput-1)/3;
1: 0
2: 0
3: 0
4: 1
5: 1
6: 1

## Column selection function
f({1,4,7}) = 0
f({2,5,8}) = 1
f({3,6,9}) = 2

col = (userInput-1)%3;