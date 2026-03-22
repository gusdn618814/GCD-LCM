# GCD, LCM Program (my_math ADT)

## 1. 목표
두 정수 a, b를 입력받아
- GCD (Greatest Common Divisor, 최대공약수)
- LCM (Least Common Multiple, 최소공배수)
를 계산하여 출력한다.

---

## 2. 핵심 아이디어

### 2.1 GCD: 유클리드 호제법(Euclidean Algorithm)
- 원리: gcd(a, b) = gcd(b, a mod b)
- b가 0이 되는 순간의 a가 GCD이다.

**주의/정의**
- gcd는 음수 입력이 들어와도 결과는 양수로 정의하기 위해 abs(절댓값)로 처리한다.
- gcd(0, x) = |x|
- gcd(0, 0) = 0 (본 프로그램에서는 0으로 정의)

---

### 2.2 LCM
- 관계식: lcm(a, b) = |a * b| / gcd(a, b)
- 단, 곱셈 overflow를 줄이기 위해 다음 형태를 권장:
  - g = gcd(a, b)
  - lcm = |(a / g) * b|
- a 또는 b가 0이면 lcm은 0으로 정의한다.

---

## 3. 알고리즘 흐름(간단 도식)

[GCD: Euclid]
Start
  |
  v
a = abs(a), b = abs(b)
  |
  v
while (b != 0):
    r = a % b
    a = b
    b = r
  |
  v
return a
  |
 End

[LCM]
Start
  |
  v
if (a == 0 or b == 0) return 0
g = gcd(a, b)
l = abs((a/g) * b)
return l
  |
 End

---

## 4. Pseudo Code

### 4.1 gcd(a, b)
function gcd(a, b):
    a <- abs(a)
    b <- abs(b)
    if a == 0 and b == 0:
        return 0
    while b != 0:
        r <- a mod b
        a <- b
        b <- r
    return a

### 4.2 lcm(a, b)
function lcm(a, b):
    if a == 0 or b == 0:
        return 0
    g <- gcd(a, b)
    return abs((a / g) * b)

---

## 5. 파일 구성
- my_math.h : 함수 원형(prototype), 상수/에러코드 정의
- my_math.c : gcd/lcm 구현
- main.c    : 입력/출력 및 my_math 사용

---

## 6. 실행 예시
Input:
12 18

Output:
GCD = 6
LCM = 36
