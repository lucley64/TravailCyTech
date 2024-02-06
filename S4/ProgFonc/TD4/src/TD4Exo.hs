module TD4Exo where
import Data.Char (isUpper)

allNew :: (a -> Bool) -> [a] -> Bool
allNew f l = not (any (not . f) l)


elemNew :: Eq a => a -> [a] -> Bool
elemNew x = any (== x)

uppers :: [Char] -> [Char]
uppers = filter isUpper

includes :: Eq a => [a] -> [a] -> Bool
includes l1 = all (`elem` l1)


