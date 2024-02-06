module FirstOrderPredicate where

data FirstOrderPredicate a
  = X
  | T
  | F
  | Not (FirstOrderPredicate a)
  | And (FirstOrderPredicate a) (FirstOrderPredicate a)
  | Or (FirstOrderPredicate a) (FirstOrderPredicate a)
  deriving (Eq, Show)

evaluate :: Bool -> FirstOrderPredicate a -> Bool
evaluate x X = x
evaluate _ T = True
evaluate _ F = False
evaluate x (Not a) = not (evaluate x a)
evaluate x (And a b) = evaluate x a && evaluate x b
evaluate x (Or a b) = evaluate x a || evaluate x b

(<=>) :: FirstOrderPredicate a -> FirstOrderPredicate a -> Bool
a <=> b = (return True a == return True b) && (return False a == return False b)

simplify :: FirstOrderPredicate a -> FirstOrderPredicate a
simplify (Not (Not x)) = simplify x
simplify (Not x) = Not (simplify x)
simplify (And T x) = simplify x
simplify (And x T) = simplify x
simplify (And F _) = F
simplify (And _ F) = F
simplify (And x y) = And (simplify x) (simplify y)
simplify (Or F x) = simplify x
simplify (Or x F) = simplify x
simplify (Or T _) = T 
simplify (Or _ T) = T 
simplify (Or x y) = Or (simplify x) (simplify y)
simplify p = p