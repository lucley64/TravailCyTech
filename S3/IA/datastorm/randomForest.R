library(randomForest)
data(iris)

model <- randomForest(Species ~ ., iris, importance = T)
show(model)

model$oob.times

model$importance
varImpPlot(model)

newIrirs <- as.data.frame(t(c(4, 3, 1, 2)))
names(newIrirs) <- names(iris)[1:4]
predict(model, newIrirs)
predict(model, newIrirs, type = "prob")

forest1 <- randomForest(Species ~ ., iris, ntree = 100)
forest2 <- randomForest(Species ~ ., iris, ntree = 500)
model <- combine(forest1, forest2)

plot(forest2$err.rate[, 1], type = "l")

