ech1 <- read.table("Ech1.txt", header = T, sep = ",")
ech2 <- read.table("Ech2.txt", header = T, sep = ",")
ech3 <- read.table("Ech3.txt", header = T, sep = ",")
ech4 <- read.table("Ech4.txt", header = T, sep = ",")
ech5 <- read.table("Ech5.txt", header = T, sep = ",")

meanVec <- c(apply(ech1, 2, mean), apply(ech2, 2, mean), apply(ech3, 2, mean), apply(ech4, 2, mean), apply(ech5, 2, mean))
meanVec <- c(apply(ech1, 2, sd), apply(ech2, 2, sd), apply(ech3, 2, sd), apply(ech4, 2, sd), apply(ech5, 2, sd))

hist(sapply(ech1, as.numeric), nclass = 10)

t.test(ech1, mu = .5, alternative = "greater")
t.test(ech2, mu = .5, alternative = "greater")
t.test(ech3, mu = .5, alternative = "greater")
t.test(ech4, mu = .5, alternative = "greater")
t.test(ech5, mu = .5, alternative = "greater")

