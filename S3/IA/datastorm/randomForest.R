library(randomForest)
data(iris)

model <- randomForest(Species ~ ., iris, importance = T)
show(model)

