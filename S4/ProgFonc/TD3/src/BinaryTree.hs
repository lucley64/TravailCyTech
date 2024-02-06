module BinaryTree where

data BinaryTree a = Nil | Node (BinaryTree a) a (BinaryTree a) deriving (Eq, Ord, Show)

size :: BinaryTree a -> Integer
size = fold 0 (\l _ r -> l + 1 + r)

height :: BinaryTree a -> Integer
height = fold 0 (\l _ r -> 1 + max l r)

elemNode :: (Eq a) => a -> BinaryTree a -> Bool
elemNode x = fold False (\l y r -> x == y || l || r)

fold :: b -> (b -> a -> b -> b) -> BinaryTree a -> b
fold z _ Nil = z
fold z op (Node l x r) = op (fold z op l) x (fold z op r)