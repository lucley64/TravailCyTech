library(randomForest)
library(rpart)
library(rpart.plot)
library(e1071)
data <- read.table("letter-recognition.data", sep = ",", header = F)
data$V1 <- as.factor(data$V1)
# Verification repartition des classes
pie(table(data$V1))

# Construction des bases train et validation
n <- nrow(data)
ntrain <- floor(2 * n / 3)
i <- sample(1:n, ntrain, replace = F) # n° des lignes à mettre dans la base d'apprentissage

train <- data[i,] # base d'apprentissage
validation <- data[-i,] # base de validation

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
sum(diag(matConf))/sum(matConf)

bestTree <- tune.rpart(V1 ~ ., train, minbucket = c(5, 10, 20, 30))
prp(bestTree$best.model)
prevision <- predict(bestTree$best.model, validation, type = "class")
matConf <- table(validation$V1, prevision)
print(matConf)
sum(diag(matConf))/sum(matConf)


# construction d'une forêt
forest <- randomForest(V1 ~ ., train, importance = T)
show(forest)
forest$oob.times
varImpPlot(forest)
prevision <- predict(forest, validation, type = "class")
matConf <- table(validation$V1, prevision)
print(matConf)



