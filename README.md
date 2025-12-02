# philosophers

> 식사하는 철학자 문제로 배우는 멀티스레딩과 동기화

![Language](https://img.shields.io/badge/Language-C-blue)
![Concurrency](https://img.shields.io/badge/Concurrency-pthread-red)

## 📖 프로젝트 소개

Dijkstra의 "식사하는 철학자 문제"를 멀티스레딩으로 구현한 프로젝트입니다. 데드락과 레이스 컨디션을 방지하며 여러 스레드를 안전하게 동기화합니다.

## 🍝 문제 설명

- N명의 철학자가 원형 테이블에 앉아 있음
- 각 철학자 사이에 포크 1개 (총 N개)
- 밥을 먹으려면 양쪽 포크 2개 필요
- 철학자는 **생각하기** → **먹기** → **자기** 반복
- 일정 시간 내에 먹지 못하면 사망

## ✨ 구현 기능

- **멀티스레딩**: 각 철학자는 독립적인 스레드
- **뮤텍스 동기화**: 포크를 뮤텍스로 보호
- **데드락 방지**: 홀수/짝수 철학자가 다른 순서로 포크 집기
- **모니터링**: 별도 루프에서 죽음/식사 완료 감지
- **정밀한 타이밍**: 밀리초 단위 시간 관리

## 🚀 실행 방법

```bash
make
./philo [철학자 수] [죽는 시간] [식사 시간] [수면 시간] [필수 식사 횟수(선택)]
```

### 예시

```bash
# 5명, 800ms 내 식사, 200ms 식사, 200ms 수면
./philo 5 800 200 200

# 각자 7번 먹으면 종료
./philo 5 800 200 200 7
```

## 📊 출력 형식

```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
200 3 has taken a fork
...
```

## 💻 사용 예시

### 1. 정상적인 시뮬레이션 (철학자가 죽지 않는 경우)

```bash
./philo 5 800 200 200
```

- 5명의 철학자
- 800ms 안에 식사하지 못하면 사망
- 200ms 동안 식사
- 200ms 동안 수면
- 누군가 죽을 때까지 계속 실행

**출력 예시:**
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
200 1 is sleeping
200 3 is sleeping
400 2 has taken a fork
400 2 has taken a fork
400 2 is eating
...
```

### 2. 필수 식사 횟수 지정

```bash
./philo 4 410 200 200 5
```

- 4명의 철학자가 각각 5번씩 식사하면 프로그램 종료
- 모든 철학자가 5번 먹으면 자동 종료

**결과:** 모든 철학자가 5번 식사 완료 후 프로그램 정상 종료

### 3. 철학자가 죽는 케이스

```bash
./philo 4 310 200 100
```

- 죽는 시간(310ms)이 식사+수면 시간(300ms)보다 짧아 철학자가 사망

**출력 예시:**
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
300 1 is thinking
300 3 has taken a fork
300 3 has taken a fork
300 3 is eating
311 2 died
```

### 4. 철학자 1명 (특수 케이스)

```bash
./philo 1 800 200 200
```

- 포크가 1개뿐이라 식사 불가능
- 철학자는 800ms 후 사망

**출력 예시:**
```
0 1 has taken a fork
800 1 died
```

### 5. 많은 철학자

```bash
./philo 200 800 200 200
```

- 200명의 철학자도 데드락 없이 정상 동작
- 모든 철학자가 순서대로 식사

### 6. 잘못된 입력

```bash
# 인자가 부족한 경우
./philo 5 800 200
# Error: 인자 개수가 올바르지 않습니다

# 음수나 0을 입력한 경우
./philo 0 800 200 200
# Error: 잘못된 인자입니다

# 숫자가 아닌 값을 입력한 경우
./philo abc 800 200 200
# Error: 잘못된 인자입니다
```

## 🛠️ 기술 스택

- **언어**: C
- **라이브러리**: pthread
- **시스템 콜**: gettimeofday, usleep
- **핵심 개념**: 멀티스레딩, 뮤텍스, 동기화

## 📚 학습 내용

- pthread를 이용한 스레드 생성/관리
- 뮤텍스를 통한 크리티컬 섹션 보호
- 데드락 발생 원인과 해결 방법
- 레이스 컨디션 회피
- 밀리초 단위 정밀 타이밍

## 💡 구현 특징

- 10ms 이내 죽음 감지
- 메시지 출력 동기화 (순서 보장)
- 최적화된 sleep (바쁜 대기 + usleep)
- 모든 뮤텍스 정리 (메모리 누수 0)

---

**philosophers - Dining Philosophers Problem**
