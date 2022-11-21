Salaire = read.csv("./Salaires.txt", header = T, sep = "\t")

boxplot(Salaire ~ Categorie, data = Salaire)

cs = Salaire[Salaire$Categorie == 'CS',]
cm = Salaire[Salaire$Categorie == 'CM',]
oe = Salaire[Salaire$Categorie == 'OE',]

moyenneCat = c(mean(cs$Salaire),
               mean(cm$Salaire),
               mean(oe$Salaire),
               mean(Salaire$Salaire))


varianceCat = c((nrow(cs) - 1) * var(cs$Salaire) / nrow(cs),
                var(cm$Salaire) * (nrow(cm) - 1) / nrow(cm),
                var(oe$Salaire) * (nrow(oe) - 1) / nrow(oe),
                var(Salaire$Salaire) * (nrow(Salaire) - 1) / nrow(Salaire)
)

effectif = c(nrow(cs), nrow(cm), nrow(oe), nrow(Salaire))

varianceIntra = varianceCat * c(nrow(cs), nrow(cm), nrow(oe), 1)
varianceIntra[4] = sum(varianceIntra[1:3]) / nrow(Salaire)
varianceIntra

varianceInter = c(
    nrow(cs) * (moyenneCat[1] - mean(Salaire$Salaire)) ^ 2,
    nrow(cm) * (moyenneCat[2] - mean(Salaire$Salaire)) ^ 2,
    nrow(oe) * (moyenneCat[3] - mean(Salaire$Salaire)) ^ 2,
    1
)
varianceInter[4] = sum(varianceInter[1:3]) / nrow(Salaire)
varianceInter

df = data.frame()
df = rbind(df, moyenneCat)
df = rbind(df, varianceCat)
df = rbind(df, effectif)
df = rbind(df, varianceInter)
df = rbind(df, varianceIntra)

colnames(df) = c('cs', 'cm', 'oe', "global")
rownames(df) = c("moyenne", "variance", "effectif", "variance inter", "variance intra")

df
