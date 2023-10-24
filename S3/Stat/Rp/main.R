n <- 15000

ech <- rnorm(n, 15, 5)

echOrg <- matrix(ech, nrow = 200, ncol = 75)

µ <- apply(echOrg, 1, mean)
σ <- apply(echOrg, 1, sd)

confint()