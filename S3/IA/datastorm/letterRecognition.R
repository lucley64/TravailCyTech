library(randomForest)
library(rpart)
library(rpart.plot)
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
tree <- rpart(V1 ~ ., train, control = rpart.control(minsplit = 5, cp = 0))
prp(tree)
plotcp(tree)
cutTree <- prune(tree, cp = .001)
prp(cutTree)
prevision <- predict(cutTree, validation, type = "class")
matConf <- table(validation$V1, prevision)
print(matConf)
# construction d'une forêt
