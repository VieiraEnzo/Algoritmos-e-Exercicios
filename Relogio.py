h = int(input())
m = int(input())
s = int(input())
t = int(input())

t += h * 3600
t += m * 60
t += s

RespSegungos = t % 60
t = t // 60
RespMinutos = t % 60
t = t // 60
RespHora = t % 24

print(RespHora)
print(RespMinutos)
print(RespSegungos)
