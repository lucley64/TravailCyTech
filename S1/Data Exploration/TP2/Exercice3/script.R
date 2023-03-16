DepensesEduData = read.table("Exercice3/ING1_GI_DataExp_DATA_QuantQuant/DepensesEduData.csv", header = T, sep = ";", dec = ",")
View(DepensesEduData)
summary(DepensesEduData)


plot(y = DepensesEduData$Depenses, x = DepensesEduData$nbEleves, main = "Budget en fonction du nombre d'élèves en Europe", xlab="nombre d'étudiants (en milliers)",ylab="Budget (K€)")
text(DepensesEduData$nbEleves, DepensesEduData$Depenses, row.names(DepensesEduData), cex = 0.8)
# nuage de points avec noms des pays

cor(DepensesEduData)
# ceof de correlation

modele = lm(DepensesEduData$Depenses ~ DepensesEduData$nbEleves)
summary(modele)
attributes(modele)

abline(modele$coefficients[1], modele$coefficients[2], col="red", lwd=2)

X11()
plot(modele$fitted.values, restd, ylim = range(-2, 2, restd))
abline(h = 2, col="red", lwd=2)
abline(h = -2, col="red", lwd=2)
text(modele$fitted, restd ,row.names(DepensesEduData))

modele2 = lm(Depenses ~ nbEleves, data = DepensesEduData[-26,])
abline(modele2$coefficients[1], modele2$coefficients[2], col="blue", lwd=2)
abline(modele2$coefficients[1], modele2$coefficients[2], col="blue", lwd=2)
restd2 = rstudent(modele2)

plot(modele2$fitted.values, restd2, ylim = range(-2, 2, restd2))
abline(h = 2, col="red", lwd=2)
abline(h = -2, col="red", lwd=2)
text(modele2$fitted, restd2 ,row.names(DepensesEduData))