demographie <- read.delim("EspVieACPData.txt")

boxplot(EV~CONT, data = demographie)

anova(lm(EV~CONT, data = demographie))



industries <- read.csv2("Industries.csv")
unique(industries$Industry.classfication)

boxplot(R.D.investment~Industry.classfication, data = industries)

kruskal.test(R.D.investment~Industry.classfication, data = industries)

anova(lm(R.D.investment~Industry.classfication, data = industries))


