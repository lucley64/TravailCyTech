{-# LANGUAGE InstanceSigs #-}
module ArithExpr(ArithExpr, fromNum, eval) where

data ArithExpr a = Value a
  | Plus (ArithExpr a) (ArithExpr a)
  | Minus (ArithExpr a) (ArithExpr a)
  | Times (ArithExpr a) (ArithExpr a)
  deriving (Eq, Ord)

fromNum :: a -> ArithExpr a
fromNum = Value

instance Show a => Show (ArithExpr a) where
  show :: ArithExpr a -> String
  show (Value x) = show x
  show (Plus  e1 e2) = "(" ++ show e1 ++ ") + (" ++ show e2 ++ ")"
  show (Minus e1 e2) = "(" ++ show e1 ++ ") - (" ++ show e2 ++ ")"
  show (Times e1 e2) = "(" ++ show e1 ++ ") * (" ++ show e2 ++ ")"

eval :: Num a => ArithExpr a -> a
eval (Value x) = x
eval (Plus x y) = eval x + eval y
eval (Minus x y) = eval x - eval y
eval (Times x y) = eval x * eval y

instance (Num a, Ord a) => Num (ArithExpr a) where
  (+) :: ArithExpr a -> ArithExpr a -> ArithExpr a
  (+) = Plus
  (-) :: ArithExpr a -> ArithExpr a -> ArithExpr a
  (-) = Minus
  (*) :: ArithExpr a -> ArithExpr a -> ArithExpr a
  (*) = Times
  abs :: ArithExpr a -> ArithExpr a
  abs e
    | eval e > 0 = e
    | otherwise = -e
  signum :: ArithExpr a -> ArithExpr a
  signum e
    | eval e > 0 = Value 1
    | eval e < 0 = Value (-1)
    | otherwise = Value 0
  fromInteger :: Integer -> ArithExpr a
  fromInteger = Value . fromInteger
