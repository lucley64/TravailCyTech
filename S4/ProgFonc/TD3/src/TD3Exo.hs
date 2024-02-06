module TD3Exo where

dichotomy :: Double -> (Double -> Double) -> Double -> Double -> Maybe Double
dichotomy eps f a b
  | f a * f b > 0 = Nothing
  | (b - a) < eps = Just m
  | f a * f m < 0 = dichotomy eps f a m
  | otherwise = dichotomy eps f m b
  where
    m = (a + b) / 2

-- isLeap :: Int -> Bool
-- isLeap y
--   | mod y 400 == 0 = True
--   | mod y 100 == 0 = False
--   | mod y 4 == 0 = True
--   | otherwise = False

isLeap :: Int -> Maybe Bool
isLeap year
  | year < 1582 = Nothing
  | mod year 400 == 0 = Just True
  | mod year 100 == 0 = Just False
  | mod year 4 == 0 = Just True
  | otherwise = Just False

dayCnt :: Int -> Bool -> Maybe Int
dayCnt month leap
  | month < 1 || month > 12 = Nothing
  | month `elem` [1, 3, 5, 7, 8, 10, 12] = Just 31
  | month `elem` [4, 6, 9, 11] = Just 30
  | leap = Just 29
  | otherwise = Just 28

dayCount :: Int -> Int -> Maybe Int
dayCount year month = isLeap year >>= dayCnt month
