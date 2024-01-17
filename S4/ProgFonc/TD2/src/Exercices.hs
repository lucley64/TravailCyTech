module Exercices where

{-
Exercice 1
a.
(i)   ( a -> a ) -> a -> a
(ii)  Num a => a -> a
(iii) Num a => a

b.
(i)   i a b = a + b
(ii)  ii f = f (f 0)
(iii) iii a b c = a + b + c
(iv)  iv a f = f(f a)
(v)   v = flip iv
(vi)  vi f = f (f 0 0) (f 0 0)

c.
(i)   i a = a
(ii)  ii a b = let z = if True then a else b in True
(iii) iii a _ = a
(iv)  iv f x = f x
(v)   v f1 f2 x = f2(f1 x)
(vi)  vi f1 f2 x y = ii(f1 x)(f2 y)
(vii) vii f1 f2 x = f1 x (f2 x)
-}

-- Exercice 2
rateOfChange :: Double -> (Double -> Double) -> Double -> Double
rateOfChange h f x = (f (x + h) - f x) / h

derivative :: (Double -> Double) -> Double -> Double
derivative = rateOfChange 1e-12

-- Exercice 3
fastPow :: Int -> Double -> Double
fastPow n x
  | n < 0 = fastPow (-n) (1.0 / x)
  | n == 0 = 1
  | n == 1 = x
  | even n = fastPow (div n 2) (x ^ (2 :: Integer))
  | otherwise = x * fastPow (div (n - 1) 2) (x ^ (2 :: Integer))


-- fastPow_t :: Int -> Double -> Double
-- fastPow_t n x
--   | n <= 0 = fastPow (-n) (1.0 / x)
--   | n == 0 = 1
--   | n == 1 = x
--   | even n = fastPow (div n 2) (x ^ (2 :: Integer))
--   | otherwise = x * fastPow (div (n - 1) 2) (x ^ (2 :: Integer))

-- Execice 4

fixed :: (a -> a) -> a -> Int -> a
fixed = fixedA 1

fixedA :: Int -> (a -> a) -> a -> Int -> a
fixedA a next x times 
  | a == times = x
  | otherwise = fixedA (a + 1) next (next x) times