PIOR CASO:
c1 +
c2(n - 1) +
c3(n - 1) +
c4(n - 1) +
c5(n² - n)/2 +
c6(n² - n)/2 +
c7(n² - n)/2 +
c8(n - 1)

T(n) = [(n² - n)/2]*(c5 + c6 + c7) + (n - 1)*(c2 + c3 + c4 + c8) + c1 

T(n) = a[(n² - n)/2] + b(n - 1) + c

O(n²) 

MELHOR CASO:
c1 +
c2(n - 1) +
c3(n - 1) +
c4(n - 1) +
c5(n - 1) +
c6(n - 1)

T(n) = (n - 1)*(c2 + c3 + c4 + c5 + c6) + c1

T(n) = a(n - 1) + b

O(n) 
