# Exercice 2
# 2)

data(iris)
summary(iris)

x1 <- 2
x2 <- .2

# Setosa

setosa <- subset(iris, Species == "setosa")

# Vérification des hypothèses indépendance
cor(setosa[, -5])
hist(setosa$Petal.Length) # loi normale
hist(setosa$Petal.Width) # pa loi normale

# Moyenne et écart-types
mpl <- mean(setosa$Petal.Length)
mpw <- mean(setosa$Petal.Width)
spl <- sd(setosa$Petal.Length)
spw <- sd(setosa$Petal.Width)

# Calcul de PPsetosa

ppsetosa <- (50 / 150) * dnorm(x1, mpl, spl) * dnorm(x2, mpw, spw)


# Versicolor

versicolor <- subset(iris, Species == "versicolor")

# Vérification des hypothèses indépendance
cor(versicolor[, -5])
hist(versicolor$Petal.Length) # loi normale
hist(versicolor$Petal.Width) # pa loi normale

# Moyenne et écart-types
mpl <- mean(versicolor$Petal.Length)
mpw <- mean(versicolor$Petal.Width)
spl <- sd(versicolor$Petal.Length)
spw <- sd(versicolor$Petal.Width)

# Calcul de PPversicolor

ppversicolor <- (50 / 150) * dnorm(x1, mpl, spl) * dnorm(x2, mpw, spw)

# Virginica

virginica <- subset(iris, Species == "virginica")

# Vérification des hypothèses indépendance
cor(virginica[, -5])
hist(virginica$Petal.Length) # loi normale
hist(virginica$Petal.Width) # pa loi normale

# Moyenne et écart-types
mpl <- mean(virginica$Petal.Length)
mpw <- mean(virginica$Petal.Width)
spl <- sd(virginica$Petal.Length)
spw <- sd(virginica$Petal.Width)

# Calcul de PPvirginica

ppvirginica <- (50 / 150) * dnorm(x1, mpl, spl) * dnorm(x2, mpw, spw)

# Probabilité
psetosa <- ppsetosa / (ppsetosa + ppversicolor + ppvirginica)
pversicolor <- ppversicolor / (ppsetosa + ppversicolor + ppvirginica)
psetosa <- ppsetosa / (ppsetosa + ppversicolor + ppvirginica)

rm(list = ls())
# Exercice 3
library(e1071)

modele <- naiveBayes(Species ~ Petal.Length + Petal.Width, data = iris)
print(modele)