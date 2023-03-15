#1)
Notes = read.table("./Notes.txt", header = T)

#2)
vp = cor(Notes)

#3)
V = cov(Notes)
decpomp = eigen(V)

#4)
inertie = sum(vp)
inertie2 = sum(diag(V))

#5)
n = nrow(Notes)
moyenne = apply(Notes, 2, mean)
variance = (n - 1) * apply(Notes, 2, var) / n
Z = Notes
for (i in 1:4) {
  Z[, i] = (Notes[, i] - moyenne[i]) / sqrt(variance[i])
}

Z = as.matrix(Z)
R = t(Z) %*% Z / n
R

inertie3 = sum(diag(R))
inertie3

#6)
decomp = eigen(R)

vp = decomp$values

i1 = 100 * vp[1] / inertie3
i2 = 100 * vp[2] / inertie3

#7)
vectp = decomp$vectors
vectp
u1 = vectp[, 1]
c1 = Z %*% u1
u2 = vectp[, 2]
c2 = Z %*% u2
plot (c1,
      c2,
      main = "Proj des indiv",
      xlab = "Axe 1",
      ylab = "Axe 2")
text (c1, c2, row.names(Notes))

mean(c1)
mean(c2)
cor(c1, c2)

(n - 1) * var(c1) / n
(n - 1) * var(c2) / n

decomp$values

#8)
x = seq(-1, 1, by = 0.001)
x

y = sqrt(1 - x ^ 2)
y

plot(c(x, x),
     c(y, -y),
     type = 'l',
     xlab = 'X',
     ylab = 'Y')
F1 = cor(Z, c1)
F2 = cor(Z, c2)
points(F1, F2)
text(F1, F2, names(Notes))
