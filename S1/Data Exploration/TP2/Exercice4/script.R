save.image("~/Travail/S1/Data Exploration/TP2/Exercice3/data.RData")
library(readr)
Commandes <- read_delim("Exercice3/ING1_GI_DataExp_DATA_QuantQuant/Commandes.csv", 
+     ";", escape_double = FALSE, trim_ws = TRUE)
View(Commandes)
summary(Commandes)


plot(x = Commandes$Prix, y = Commandes$Vente)
plot(y = Commandes$Prix, x = Commandes$Vente)
plot(x = Commandes$Prix, y = Commandes$Vente)
coefficientDeCorrelation = cor(Commandes)
coefficientDeCorrelation

modele = lm(Commandes$Prix ~ Commandes$Vente)
modele

summary(modele)

attributes(modele)

modele$coefficients

abline(modele$coefficients[1], modele$coefficients[2], col="red", lwd=2)
plot(y = Commandes$Prix, x = Commandes$Vente)
abline(modele$coefficients[1], modele$coefficients[2], col="red", lwd=2)
modele$fitted.values

modele$residuals

restd = rstandard(modele)
restd

x11()
plot(modele$fitted.values, restd, ylim = range(-2, 2, restd))
abline(h=2,col="red",lwd=2)
abline(h=-2,col="red",lwd=2)

v = log(Commandes$Vente)
u = log(Commandes$Prix)
plot(u, v)
RegLin = lm(v~u)
summary(RegLin)

rstd = rstudent(RegLin)
plot(RegLin$fitted.values, rstd, ylim = range(-2, 2, rstd))
abline(h=2,col="red",lwd=2)
abline(h=-2,col="red",lwd=2)

nevu = data.frame(u=c(log(75)))
nevV = predict(RegLin, newdata = nevu)
nevV
#1 
#5.368901 
exp(nevV)
#1 
#214.6269 