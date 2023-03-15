#1)
lenses = read.table("./ING1_GI_DataExp_QualiQuali_DATA/lenses.txt", header = T)
View(lenses)


cont = table(lenses$Recommendation, lenses$Age)
print(cont)

cont.tot = addmargins(cont)
print(cont.tot)

freq = cont / sum(cont)
print(freq)

freq.tot = addmargins(freq)
print(freq.tot)

#2)
#a)
profil.lignes = prop.table(cont, 1)
print(profil.lignes)

#b)
addmargins(profil.lignes)

#c)
plot(profil.lignes)
profil.lignes.moy = freq.tot[4, 1:3]
profil.lignes = rbind(profil.lignes, profil.lignes.moy)

profil.lignes = as.table(profil.lignes)
profil.lignes

rownames(profil.lignes)[4] = "Profil Moyen"
print(profil.lignes)
plot(profil.lignes, main = "Profils lignes")

#3)
profil.colones = prop.table(x = cont, margin = 2)
print(profil.colones)

addmargins(profil.colones)

plot(profil.colones)
profil.colones.moy = freq.tot[1:3, 4]
profil.colones = rbind(profil.colones, profil.colones.moy)

profil.colones = as.table(profil.colones)
profil.colones

rownames(profil.colones)[4] = "Profil Moyen"
print(profil.colones)
plot(profil.colones, main = "Profils colones")


#4)
tab.theo = matrix(0, 3, 3)
for (i in 1:3) {
  for (j in 1:3) {
    tab.theo[i, j] = profil.lignes.moy[j] * profil.colones.moy[i]
  }
}
tab.theo

tab.theo = tab.theo * nrow(lenses)
print(tab.theo)
tab.chi2 = ((cont - tab.theo) ^ 2) / tab.theo
print(tab.chi2)
dchi2 = sum(tab.chi2)
dchi2
