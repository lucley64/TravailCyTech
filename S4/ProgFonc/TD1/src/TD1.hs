module TD1 where

triangleArea :: (Double, Double, Double) -> Double
triangleArea(a, b, c) =
    let p = 0.5 * (a + b + c) in
        sqrt (p * (p - a) *(p - b) + (p - c))

isLeap :: Int -> Bool
isLeap y 
        | mod y 400 == 0 = True
        | mod y 100 == 0 = False
        | mod y 4 == 0 = True
        | otherwise = False
    -- mod y 400 == 0 || mod y 100 /= 0 && mod y 4 == 0

type Date = (Int, Int, Int)

ageXMas2023 :: Date -> Int
ageXMas2023 birth =
    case birth of
        (d, 12, y) | d > 25 -> 2023 - y - 1
        (_,  _, y)          -> 2023 - y
    -- if m >= 12 && d > 25 then 2023 - y - 1 else 2023 - y where (d, m, y) = birth --no pm