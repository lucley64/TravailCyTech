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

ppsetosa <- (50 / 150) *
    dnorm(x1, mpl, spl) *
    dnorm(x2, mpw, spw)


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

ppversicolor <- (50 / 150) *
    dnorm(x1, mpl, spl) *
    dnorm(x2, mpw, spw)

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

ppvirginica <- (50 / 150) *
    dnorm(x1, mpl, spl) *
    dnorm(x2, mpw, spw)

# Probabilité
psetosa <- ppsetosa / (ppsetosa + ppversicolor + ppvirginica)
pversicolor <- ppversicolor / (ppsetosa + ppversicolor + ppvirginica)
psetosa <- ppsetosa / (ppsetosa + ppversicolor + ppvirginica)

rm(list = ls())
# Exercice 3
library(e1071)

model <- naiveBayes(Species ~ Petal.Length + Petal.Width, data = iris)
print(model)

# New iris
newIris <- matrix(0, 3, 2)
newIris[1,] <- c(2, .2)
newIris[2,] <- c(5, 1.65)
newIris[3,] <- c(7, 3)
newIris <- as.data.frame(newIris)
names(newIris) <- names(iris)[3:4]

predict(model, newdata = newIris, type = "raw")

rm(list = ls())
# Classif correl
tab <- read.table("Test_Classif_Correl.txt", header = T)
tab$Y <- as.factor(tab$Y)
plot(tab$X1, tab$X2, col = tab$Y)


rm(list = ls())
# Exercice 4
data <- read.table("lenses.txt", header = T)

data$Age <- as.factor(data$Age)
data$Prescription <- as.factor(data$Prescription)
data$Astigmatic <- as.factor(data$Astigmatic)
data$Tears <- as.factor(data$Tears)
data$Recommendation <- as.factor(data$Recommendation)

n <- nrow(data)
ntrain <- floor(2 * n / 3)
i <- sample(1:n, ntrain, replace = F) # n° des lignes à mettre dans la base d'apprentissage

train <- data[i,] # base d'apprentissage
validation <- data[-i,] # base de validation


model <- naiveBayes(Recommendation ~ Age + Prescription + Astigmatic + Tears, data = data)
print(model)

prediction <- predict(model, data)
matConf <- table(data$Recommendation, prediction)
print(matConf)
sum(diag(matConf)) / sum(matConf)

