#Demo
A = matrix(rnorm(100, sd = .3), ncol = 2)
B = matrix(rnorm(100,mean=100,sd=10), ncol=2)
x = rbind(A,B)
plot(x)
x=scale(x)
distance=dist(x, "euclidean" )
h=hclust(distance, "ward.D2")
plot(h$height)
plot(h)
rect.hclust(h,k=2)
c=cutree(h,k=2)
plot(x, col = c)


cluster = read.table("./Test_Clusters_Atypiques.txt")
cluster = scale(cluster)
d = dist(cluster, "euclidean")
h = hclust(d, "ward.D2")
plot(h$height)
plot(h)
rect.hclust(h, k=2)
c = cutree(h, k = 2)
plot(x, col = c)
pairs(x, col = c)


test = as.matrix(c(1, 2, 9, 12, 20))
d2 = dist(test, "manhatan")
h2 = hclust(distance, "wrad.D2")

centre <- matrix(0, 2,ncol(cluster))
centre

centre[1,] <- cluster[1,]
centre[1,] <- cluster[1499,]

k = kmeans(cluster,center=centre)
print(k)

plot(cluster, col=k$cluster)