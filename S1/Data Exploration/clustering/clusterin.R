tab = read.table("./Test_Clusters_Distincts.txt")
View(tab)
# a 2-dimensional example
A = matrix(rnorm(100,sd=0.3), ncol=2)
# rnorm génère une matrice de
B = matrix(rnorm(100,mean=1,sd=0.3), ncol=2) # réalisations d’une loi normale
x = rbind(A,B) # rbind concatène des matrices

plot(x)
x=scale(x) #centre et réduit
cl= kmeans(x,center=2,nstart=5)
#clustering à 2 classes
print(cl) # affiche les résultats
plot(x, col = cl$cluster) # affiche les points avec une couleur différente par classe
# indexée par le numéro de la classe
points(cl$centers, col = 1:2, pch = 8, cex = 2) # ajoute les centres des classes