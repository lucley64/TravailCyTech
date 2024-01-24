module TD3Exo where

dichotomy :: Double -> (Double -> Double) -> Double -> Double -> Maybe Double
dichotomy eps f a b
  | f a * f b > 0 = Nothing
  | (b - a) < eps = Just m
  | f a * f m < 0 = dichotomy eps f a m
  | otherwise = dichotomy eps f m b
  where m = (a + b) / 2

