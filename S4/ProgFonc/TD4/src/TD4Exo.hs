{-# HLINT ignore "Hoist not" #-}
{-# HLINT ignore "Use elem" #-}
{-# HLINT ignore "Use sum" #-}
{-# HLINT ignore "Use max" #-}
{-# OPTIONS_GHC -Wno-missing-export-lists #-}
{-# OPTIONS_GHC -Wno-unrecognised-pragmas #-}

module TD4Exo where

import Classroom (Classroom (clssrmCapacity))
import Data.Char (isUpper)
import Data.List (sort, sortOn, unfoldr)
import Lecture (Lecture (lctrRoom, lctrStart, lctrTeacher, lctrYear))
import Student (Student (stuUser, year))
import Teacher (Teacher (dep, seniority, tchrUser))
import User (User (usrAge))

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

join :: [a] -> [b] -> [(a, b)]
-- join l1 l2 = foldl (\z x -> foldl (\z1 y -> z1 ++ [(x, y)]) z l2) [] l1
-- join l1 l2 = concatMap (\x -> map (x,) l2) l1
join l1 l2 = [(x, y) | x <- l1, y <- l2]

yearList :: [Student] -> Int -> [Student]
-- yearList l y = sort (filter (\s -> year s == y) l)
yearList l y = sort [x | x <- l, year x == y]

deptList :: [Teacher] -> String -> [Teacher]
-- deptList l d = sort (filter (\t -> dep t == d) l)
deptList l d = sort [x | x <- l, dep x == d]

parOfFurniture :: [Teacher] -> [Teacher]
-- parOfFurniture l = sort (filter (\t -> seniority t >= 10) l)
parOfFurniture l = sort [x | x <- l, seniority x >= 10]

studentsOlderThanTeachers :: [Student] -> [Teacher] -> [(Student, Teacher)]
studentsOlderThanTeachers sts ts = [(x, y) | x <- sts, y <- ts, usrAge (stuUser x) >= usrAge (tchrUser y)]

schedule :: [Lecture] -> Teacher -> [Lecture]
schedule lctrs tchr = sortOn lctrStart [x | x <- lctrs, lctrTeacher x == tchr]

timable :: [Lecture] -> Student -> [Lecture]
timable lctrs stdt = sortOn lctrStart [x | x <- lctrs, lctrYear x == year stdt]

overbooked :: [Student] -> [Lecture] -> [Lecture]
overbooked sts cs = [x | x <- cs, clssrmCapacity (lctrRoom x) < length (yearList sts (lctrYear x))]

conflicts :: [Lecture] -> [(Lecture, Lecture)]
conflicts cs = [(x, y) | x <- cs, y <- cs, x `conflictsWith` y]
  where
    c1 `conflictsWith` c2 =
      lctrStart c1 == lctrStart c2
        && ( lctrRoom c1 == lctrRoom c2
               || lctrTeacher c1 == lctrTeacher c2
               || lctrYear c1 == lctrYear c2
           )

fixed :: (a -> a) -> a -> Int -> a
-- fixed next initial times = head $ drop times $ iterate next initial
fixed next initial times = iterate next initial !! times

whilst :: (a -> a) -> a -> (a -> Bool) -> a
whilst next initial cont = head $ dropWhile cont $ iterate next initial

recurrence :: (Integer -> a -> a) -> a -> [a]
-- recurrence f u0 = map snd $ iterate (\(n, u) -> (n + 1, f n u)) (0, u0)
recurrence f u0 = unfoldr (\(n, u) -> Just (u, (n + 1, f n u))) (0, u0) -- <=> [u0 , f 0 u0 , f 1 $ f 0 u0 , ...]
