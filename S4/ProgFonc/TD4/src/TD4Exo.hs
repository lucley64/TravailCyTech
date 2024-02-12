{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

{-# HLINT ignore "Hoist not" #-}
{-# HLINT ignore "Use elem" #-}
{-# HLINT ignore "Use sum" #-}
{-# HLINT ignore "Use max" #-}
module TD4Exo where

import Data.Char (isUpper)

allNew :: (a -> Bool) -> [a] -> Bool
allNew f l = not (any (not . f) l)

elemNew :: (Eq a) => a -> [a] -> Bool
elemNew x = any (== x)

uppers :: [Char] -> [Char]
uppers = filter isUpper

includes :: (Eq a) => [a] -> [a] -> Bool
includes l1 = all (`elem` l1)

mySum :: [Integer] -> Integer
mySum = foldr (+) 0

myMax :: (Ord a) => [a] -> Maybe a
myMax [] = Nothing
myMax (h : t) = Just (foldr max h t)

maxIndex :: (Ord a) => [a] -> Maybe Int
maxIndex [] = Nothing
maxIndex (h : t) = Just a
  where
    (_, a) = foldr opMaxIndex (h, 0) (zip t [1 ..])
    opMaxIndex (x, i) (y, j) = if x >= y then (x, i) else (y, j)

myAny :: (a -> Bool) -> [a] -> Bool
myAny op = foldr (\x b -> b || op x) False

myFind :: (a -> Bool) -> [a] -> Maybe a
myFind op = foldl opFind Nothing
  where
    opFind Nothing x | op x = Just x
    opFind z _ = z

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter op = foldl (\l x -> if op x then l ++ [x] else l) []

myMap :: (a -> b) -> [a] -> [b]
myMap op = foldl (\l x -> l ++ [op x]) []

myAnyRec :: (a -> Bool) -> [a] -> Bool
myAnyRec _ [] = False
myAnyRec op (h : t) = op h || myAnyRec op t

myFindRec :: (a -> Bool) -> [a] -> Maybe a
myFindRec _ [] = Nothing
myFindRec op (h : t) = if op h then Just h else myFindRec op t

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition op (h : t) = if op h then (h : x, y) else (x, h : y)
  where
    (x, y) = myPartition op t

prefixes :: [a] -> [[a]]
prefixes = foldl (\z x -> z ++ [last z ++ [x]]) [[]]
-- prefixes l = foldr (\x z -> init (head z) : z) [l] l
-- prefixes = foldr (\x z -> [] : map (x :) z) [[]]
-- prefixes l = map (`take` l) [0.. length l]


join :: [a] ->[b] -> [(a, b)]
join l1 l2 = foldl (\z x -> foldl (\z1 y -> z1 ++ [(x, y)]) z l2) [] l1

