library(randomForest)
data(iris)

model <- randomForest(Species ~ ., iris, importance = T)
show(model)

model$oob.times

model$importance
varImpPlot(model)