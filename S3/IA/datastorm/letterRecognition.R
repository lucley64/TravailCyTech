library(randomForest)
library(rpart)
library(rpart.plot)
library(e1071)
data <- read.table("letter-recognition.data", sep = ",", header = F)
data$V1 <- as.factor(data$V1)
# Verification repartition des classes
pie(table(data$V1))

# Création bases apprentissage (2/3), validation (1/6) et test (1/6)
n <- nrow(data)
# Base apprentissage
ntrain <- floor(2 * n / 3)
index <- sample(1:n, ntrain, replace = F)
train <- data[index,]
reste <- data[-index,]
# Bases validation et test
nval <- floor(n / 6)
indexval <- sample(seq_len(nrow(reste)), nval, replace = F)
validation <- reste[indexval,]
test <- reste[-indexval,]

#construction d'un arbre
tree <- rpart(V1 ~ ., train)
tree <- rpart(V1 ~ ., train, control = rpart.control(minsplit = 5, cp = 0))
prp(tree)
plotcp(tree)
cutTree <- prune(tree, cp = .001)
prp(cutTree)
prevision <- predict(cutTree, validation, type = "class")
matConf <- table(validation$V1, prevision)
print(matConf)
sum(diag(matConf)) / sum(matConf)

bestTree <- tune.rpart(V1 ~ ., train, minbucket = c(5, 10, 20, 30))
prp(bestTree$best.model)
prevision <- predict(bestTree$best.model, validation, type = "class")
matConf <- table(validation$V1, prevision)
print(matConf)
sum(diag(matConf)) / sum(matConf)


# construction d'une forêt
forest <- randomForest(V1 ~ ., train, importance = T)
show(forest)
forest$oob.times
varImpPlot(forest)
prevision <- predict(forest, validation, type = "class")
matConf <- table(validation$V1, prevision)
print(matConf)


# Naive bayes
library(e1071)
model <- naiveBayes(V1 ~ ., data = train)
print(model)
prevision <- predict(model, validation)
matConf <- table(validation$V1, prevision)
print(matConf)
sum(diag(matConf)) / sum(matConf)
