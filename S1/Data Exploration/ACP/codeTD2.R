#Exercice1
#1)
install.packages("FactoMineR")
library(FactoMineR)

#2)
EspVieACPData <-
  read.table(file = "./EspVieACPData.txt",
             header = T)
View(EspVieACPData)

#3)
pairs(EspVieACPData[, 1:6])

EspVieACPData[, 1:6] = scale(EspVieACPData[, 1:6])

#4)
? PCA
res.PCA = PCA(
  EspVieACPData[, 1:6],
  scale.unit = T,
  ncp = 6,
  axes = c(1, 2)
)

res.PCA
res.PCA$eig

barplot(res.PCA$eig[, 2], main = "% de var par axe")

res.PCA$var$cos2
sum(res.PCA$var$cos2[1,])

res.PCA$var$contrib

res.PCA$ind$cos2

sort(res.PCA$ind$contrib[, 1], decreasing = T)

res = PCA(
  EspVieACPData[, 1:6],
  ind.sup = c(127),
  scale.unit = T,
  ncp = 6,
  graph = T,
  axes = c(1, 2)
)

res2 = PCA(
  EspVieACPData,
  quali.sup = 7,
  scale.unit = T,
  ncp = 6,
  graph = T,
  axes = c(1, 2)
)


#Exercice 2
install.packages("explor")
library(explor)
library(readxl)
DecathlonData <- read_excel("./DecathlonData.xls", col_names = T)
names <- DecathlonData$...1
DecathlonData <- subset(DecathlonData, select = -...1)
row.names(DecathlonData) <- names
View(DecathlonData)

#1)
DecathlonData[1:10] <- scale(DecathlonData[1:10])
head(DecathlonData)
res.PCA <-
  PCA(
    DecathlonData[1:10],
    scale.unit = T,
    ncp = 10,
    graph = T,
    axes = c(1, 2)
  )
explor(res.PCA)

res.PCA$eig

res.PCA$var$cos2

sort(res.PCA$var$contrib[,1],decreasing = T)
sort(res.PCA$var$contrib[,2],decreasing = T)

res.PCA$var$contrib[,1:2]

res.PCA <- PCA(DecathlonData[,1:10],quanti.sup = c(11:12),quali.sup = c(13), scale.unit = T, ncp=10, graph = T, axes = c(1,2))



#Exercice 3
library(readxl)
EconomieEuropData <- read_excel("./EconomieEuropData.xls", skip = 1)
View(EconomieEuropData)

#1)
EconomieEuropData[,2:6] <- scale(EconomieEuropData[,2:6])
head(EconomieEuropData)
res.PCA = PCA(EconomieEuropData[,2:6], scale.unit = T, ncp = 4, graph = T, axes = c(1,2))
